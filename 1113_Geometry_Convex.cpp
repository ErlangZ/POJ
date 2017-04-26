#include <iostream>
#include <algorithm>
#include <cmath>
#define PI 3.1415926535
struct Point {
    double x;
    double y;
};
bool operator<(const Point& p1, const Point& p2) {
    return p1.x < p2.x || (fabs(p1.x - p2.x) < 1e-8 && p1.y < p2.y);
}
std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << "," << point.y << ")";
}
bool clockwise(const Point& p1, const Point& p2, const Point& p3) {
    //p1 -> p2 -> p3
    double v1x = p2.x - p1.x;
    double v1y = p2.y - p1.y;
    double v2x = p3.x - p2.x;
    double v2y = p3.y - p2.y;
    return v1x * v2y - v2x * v1y > 0;
}
int comvex(Point* points, int n, int* result) {
    std::sort(points, points+n); 

    int top = 0;
    if (n == 0) return 0;
    result[top++] = 0; if (n == 1) { return top; }
    result[top++] = 1; if (n == 2) { return top; }
    for (int i = 2; i < n; i++) {
       while (top > 0 && 
              clockwise(points[result[top-2]], points[result[top-1]], points[i])) {
           top --;
       }
       result[top++] = i;
    }

    int tmp = top;
    //n-1 must be in the result queue.
    result[top++] = n - 2;
    for (int i = n - 3; i >= 0; i--) {
        while (top > tmp &&
               clockwise(points[result[top-2]], points[result[top-1]], points[i])) {
            top --;
        }
        result[top++] = i;
    } 
    return top;
}
double distance(const Point& p1, const Point& p2) {
    return std::sqrt((p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y));
}
int main() {
    int n, L;
    int result[2000];
    Point points[2000];

    std::cin >> n >> L;
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
    }    

    int num = comvex(points, n, result); 

    double dis = 0.0;
    for (int i = 0; i < num; i++) {
        dis += distance(points[result[i-1]], points[result[i]]);
    }
    //round 0.5
    std::cout << static_cast<int>(dis + 2 * PI * L + 0.5) << std::endl;
    return 0;
}
