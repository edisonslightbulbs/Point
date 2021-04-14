#ifndef POINT_H
#define POINT_H

#include <Eigen/Dense>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

extern const int R;    // <- dimensional space
extern const int xCol; // x column
extern const int yCol; // y column
extern const int zCol; // z column

extern const int NOISE;
extern const int UNLABELED;

class Point {

public:
    bool operator<(const Point& rhs) const;
    bool operator!=(const Point& rhs) const;
    bool operator==(const Point& rhs) const;
    friend std::ostream& operator<<(std::ostream& t_stream, const Point& point);
    friend std::istream& operator>>(std::istream& t_stream, Point& point);

    std::array<int, 3> m_rgb {};
    std::array<float, 3> m_xyz {};

    int m_cluster;
    std::string m_clusterColor;

    std::pair<Point*, float> m_distance;

    Point();

    Point(float x, float y, float z);

    [[nodiscard]] bool unlabeled() const;

    static void sort(std::vector<Point>& points);

    void setColor(const std::vector<float>& rgb);

    static Point centroid(std::vector<Point>& points);

    [[nodiscard]] float distance(const Point& other) const;
};
#endif /* POINT_H */
