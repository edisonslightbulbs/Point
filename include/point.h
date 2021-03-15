#ifndef POINT_H
#define POINT_H

#include <Eigen/Dense>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

/** Global variables */
extern const int NOISE;
extern const int UNDEFINED;

extern const int xCol; // vector column with x values
extern const int yCol; // vector column with y values
extern const int zCol; // vector column with Z values
extern const int R; // dimensions

/** todo: optimize data structure for color manipulation
 * Bit values for colors*/

class Point {

public:
    bool operator<(const Point& rhs) const;
    bool operator!=(const Point& rhs) const;
    bool operator==(const Point& rhs) const;
    friend std::ostream& operator<<(std::ostream& t_stream, const Point& point);
    friend std::istream& operator>>(std::istream& t_stream, Point& point);

    int m_id;
    int m_cluster;

    float m_x;
    float m_y;
    float m_z;

    Point();
    Point(float t_x, float t_y, float t_z);

    std::pair<int, float> m_distance;

    bool undefined() const;

    float distance(Point point) const;

    static Point centroid(std::vector<Point>& t_points);

    static void sort(std::vector<Point>& points);
};
#endif /* POINT_H */
