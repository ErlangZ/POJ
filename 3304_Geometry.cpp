#include <iostream>
struct Point {
    double x;
    double y;
};
//@brief p3, p4 on the 2-sides of p1-p2
bool two_sides(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
}
int main() {
    Point points[400];
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; j++) {
            std::cin >> point[2*j].x >> point[2*j].y >> point[2*j+1].x >> point[2*j+1].y;
        }
    }
    return 0;
}
