#include <iostream>
#include <cfloat>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Point {
    double x;
    double y;
    double min_dis_; //min distance to (0,5)
    Point(double x_, double y_, double min_dis=-FLT_MAX) : 
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

int n = 0;
double X[20];
double Y[20][4];

void update_points(const std::vector<Point>& points, Point* point) {
    for (size_t k = 0; k < points.size(); k++) {
        //points[k] is the point on the left.
        double* l_wall_x = std::upper_bound(X, X+n, points[k].x);
        bool crossed = false;
        //upper-bound is i
        while (l_wall_x != X + j) {
            size_t index = std::distance(X, l_wall_x);
            if (cross(Point(*l_wall_x, Y[index][0]), 
                        Point(*l_wall_x, Y[index][1]),
                        points[k], *point) ||
                    cross(Point(*l_wall_x, Y[index][2]),
                        Point(*l_wall_x, Y[index][3]),
                        points[k], *point)) {
                crossed = true;
            }
            l_wall_x ++;
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
                update_points(points, &point);
                points.push_back(point);
            }
        }

        Point end(10.0, 5.0);
        update_points(points, &end);
        std::cout << std::fixed << std::setprecision(2) << end.min_dis_ << std::endl;
    }
    return 0;
}
