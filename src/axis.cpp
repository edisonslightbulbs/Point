#include <algorithm>
#include <vector>

#include "axis.h"

void axis::sortX(std::vector<Point>& points)
{
    std::sort(points.begin(), points.end(),
        [](const Point& point, const Point& other) {
            return point.m_x < other.m_x;
        });
}

void axis::sortY(std::vector<Point>& points)
{
    std::sort(points.begin(), points.end(),
        [](const Point& point, const Point& other) {
            return point.m_y < other.m_y;
        });
}

void axis::sortZ(std::vector<Point>& points)
{
    std::sort(points.begin(), points.end(),
        [](const Point& point, const Point& other) {
            return point.m_z < other.m_z;
        });
}
