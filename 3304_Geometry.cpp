#include <iostream>
#include <cmath>
struct Point {
    double x;
    double y;
};
//@brief p3, p4 on the 2-sides of p1-p2
bool two_sides(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    double v1x = p2.x - p1.x;
    double v1y = p2.y - p1.y;
    double v2x = p3.x - p1.x;
    double v2y = p3.y - p1.y;
    double v3x = p4.x - p1.x;
    double v3y = p4.y - p1.y;
    return ((v1x * v2y) - (v2x * v1y)) * ((v1x * v3y) - (v3x * v1y)) <= 1e-8;
}

double distance(const Point& p1, const Point& p2) {
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    return sqrt(x*x + y*y);
} 

int main() {
    Point points[400];
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; j++) {
            std::cin >> points[2*j].x >> points[2*j].y >> points[2*j+1].x >> points[2*j+1].y;
        }
        bool exist = false;
        if (m == 1 || m == 2) {
            exist = true;
        } else {
            for (int j = 0; j < 2 * m; j++) {
                if (exist) break;
                for (int k = j+1; k < 2 * m; k++) {
                    if (distance(points[j], points[k]) < 1e-6) { 
                        continue; 
                    }

                    bool result = true;
                    for (int l = 0; l < m; l++) {
                        if (!two_sides(points[j], points[k], points[2*l], points[2*l+1])) {
                            result = false;
                        }
                    } 
                    if (!exist && result) {
                        exist = true;
                    }
                }
            }
        }

        if (exist) {
            std::cout << "Yes!" << std::endl;
        } else {
            std::cout << "No!" << std::endl;
        }
    }
    return 0;
}
