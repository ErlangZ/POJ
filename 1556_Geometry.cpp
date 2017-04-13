#include <iostream>
#include <cmath>
#include <cfloat>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Point {
    double x;
    double y;
    double min_dis_; //min distance to (0,5)
    Point(double x_, double y_, double min_dis=FLT_MAX) : 
        x(x_), y(y_), min_dis_(min_dis) {
    }
    Point(const Point& other) {
        x = other.x;
        y = other.y;
        min_dis_ = other.min_dis_;
    }
    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            min_dis_ = other.min_dis_;
        }
        return *this;
    }
};

bool two_side(const Point& lp1, const Point& lp2, const Point& p1, const Point& p2) {
    double x1 = lp2.x - lp1.x;
    double y1 = lp2.y - lp1.y;
    double x2 = p1.x - lp1.x;
    double y2 = p1.y - lp1.y;
    double x3 = p2.x - lp1.x;
    double y3 = p2.y - lp1.y;
    return (x1*y2 - x2*y1) * (x1*y3 - x3*y1) < 0;
}

bool cross(const Point& l1p1, const Point& l1p2, const Point& l2p1, const Point& l2p2) {
    return (two_side(l1p1, l1p2, l2p1, l2p2) && two_side(l2p1, l2p2, l1p1, l1p2));
}

double distance(const Point& p1, const Point& p2) {
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    return sqrt(x * x + y * y);
}

int n = 0;
double X[20];
double Y[20][4];

void update_points(const int end_index, const std::vector<Point>& points, Point* point) {
    for (size_t k = 0; k < points.size(); k++) {
        //points[k] is the point on the left.
        int l_wall_index = 0;
        while (l_wall_index < n && X[l_wall_index] <= points[k].x) {
            l_wall_index ++;
        }
        bool crossed = false;
        //upper-bound is i
        while (l_wall_index < end_index) {
            if (cross(Point(X[l_wall_index], 0.0), 
                      Point(X[l_wall_index], Y[l_wall_index][0]),
                      points[k], *point) ||
                cross(Point(X[l_wall_index], Y[l_wall_index][1]),
                      Point(X[l_wall_index], Y[l_wall_index][2]),
                      points[k], *point) ||
                cross(Point(X[l_wall_index], Y[l_wall_index][3]),
                      Point(X[l_wall_index], 10.0),
                      points[k], *point)) {
                crossed = true;
                break;
            }
            l_wall_index ++;
        }
        if (!crossed) {
            if (points[k].min_dis_ + distance(points[k], *point) < point->min_dis_) {
                point->min_dis_ = points[k].min_dis_ + distance(points[k], *point);
            }
        }
    }

}

int main() {

    while(true) {

        std::cin >> n;
        if (n == -1) {
            break;
        }

        for (int i = 0; i < n; i++) {
            std::cin >> X[i];
            for (int j = 0; j < 4; j++) {
                std::cin >> Y[i][j];
            }
        }
       
        std::vector<Point> points;
        Point start(0.0, 5.0, 0.0); 
        points.push_back(start);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                Point point(X[i], Y[i][j]);
                update_points(i, points, &point);
                points.push_back(point);
            }
        }

        Point end(10.0, 5.0);
        update_points(n, points, &end);
        std::cout << std::fixed << std::setprecision(2) << end.min_dis_ << std::endl;
    }
    return 0;
}
