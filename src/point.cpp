#include "point.h"

extern const int NOISE = -2;
extern const int UNASSIGNED = -1;
extern const int UNDEFINED = -1;

extern const int xCol = 0; //  x_i = {x_1, x_2, ... x_m}
extern const int yCol = 1; //  y_i = {y_1, y_2, ... y_m}
extern const int zCol = 2; //  z_i = {z_1, z_2, ... z_m}
extern const int R = 3;    // dimensional space

bool compare(const Point& point, const Point& other)
{
    return point.m_distance.second < other.m_distance.second;
}

void Point::sort(std::vector<Point>& points)
{
    /** sort points using m_distance.second (i.e., euclidean distance) */
    std::sort(points.begin(), points.end(), compare);
}

Point::Point()
    : m_x(0.0)
    , m_y(0.0)
    , m_z(0.0)

    , m_id(UNASSIGNED)
    , m_cluster(UNDEFINED)
    , m_distance(0, __DBL_MAX__)
{
}

Point::Point(float x, float y, float z)
    : m_x(x)
    , m_y(y)
    , m_z(z)

    , m_id(UNASSIGNED)
    , m_cluster(UNDEFINED)
    , m_distance(0, __DBL_MAX__)
{
}

bool Point::undefined() const
{
    return (m_cluster == UNDEFINED || m_cluster == NOISE);
}

float Point::distance(Point point) const
{
    float x = m_x - point.m_x;
    float y = m_y - point.m_y;
    float z = m_z - point.m_z;
    return (float)std::sqrt((x * x) + (y * y) + (z * z));
}

Point Point::centroid(std::vector<Point>& points)
{
    Eigen::MatrixXd pointsMat(points.size(), R);

    int row = 0;
    for (auto point : points) {
        pointsMat(row, xCol) = point.m_x;
        pointsMat(row, yCol) = point.m_y;
        pointsMat(row, zCol) = point.m_z;
        row++;
    }
    return Point { (float)pointsMat.col(xCol).mean(),
        (float)pointsMat.col(yCol).mean(), (float)pointsMat.col(zCol).mean() };
}

bool Point::operator==(const Point& rhs) const
{
    return (m_x == rhs.m_x && m_y == rhs.m_y && m_z == rhs.m_z);
}

bool Point::operator!=(const Point& rhs) const
{
    return (m_x != rhs.m_x || m_y != rhs.m_y || m_z != rhs.m_z);
}

bool Point::operator<(const Point& rhs) const
{
    return (this->m_distance.second < rhs.m_distance.second);
}

std::ostream& operator<<(std::ostream& stream, const Point& point)
{
    stream << point.m_x << " " << point.m_y << " " << point.m_z;
    return stream;
}

std::istream& operator>>(std::istream& stream, Point& point)
{
    stream >> point.m_x >> point.m_y >> point.m_z;
    return stream;
}
