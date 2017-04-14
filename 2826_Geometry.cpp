#include <iostream>
#include <cmath>
#include <iomanip>

bool two_sides(const double lx1, const double ly1, const double lx2, const double ly2,
               const double p1x, const double p1y, const double p2x, const double p2y) {
    double x1 = lx2 - lx1;
    double y1 = ly2 - ly1;
    double x2 = p1x - lx1;
    double y2 = p1y - ly1;
    double x3 = p2x - lx1;
    double y3 = p2y - ly1;
    return (x1*y2 - x2*y1) * (x1*y3 - x3*y1) <= 1e-8;
}

void cross_point(const double l1x1, const double l1y1, const double l1x2, const double l1y2,
                 const double l2x1, const double l2y1, const double l2x2, const double l2y2,
                 double* x, double* y) {
    double a1 = l1y1 - l1y2; 
    double b1 = l1x2 - l1x1; 
    double c1 = l1x1 * l1y2 - l1x2 * l1y1; 

    double a2 = l2y1 - l2y2; 
    double b2 = l2x2 - l2x1; 
    double c2 = l2x1 * l2y2 - l2x2 * l2y1; 
    double div = a2*b1-a1*b2;
    *x = (c1*b2 - c2*b1)/div;
    *y = (a1*c2 - c1*a2)/div;
}

bool left(const double x1, const double y1, 
          const double x2, const double y2, const double x3, const double y3) {
    const double v1x = x2 - x1;
    const double v1y = y2 - y1;
    const double v2x = x3 - x1;
    const double v2y = y3 - y1;
    return v2y * v1x - v2x * v1y <= 1e-8;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << std::fixed << std::setprecision(2);

    double l1x1, l1y1, l1x2, l1y2;
    double l2x1, l2y1, l2x2, l2y2;

    double result = 0.0;
    for (int i = 0; i < n; i++) {
        std::cin >> l1x1 >> l1y1 >> l1x2 >> l1y2 
                 >> l2x1 >> l2y1 >> l2x2 >> l2y2;

        if (two_sides(l1x1, l1y1, l1x2, l1y2, l2x1, l2y1, l2x2, l2y2) &&
            two_sides(l2x1, l2y1, l2x2, l2y2, l1x1, l1y1, l1x2, l1y2)) {
            //x, y is the cross point.
            double x = 0.0, y = 0.0; 
            cross_point(l1x1, l1y1, l1x2, l1y2, l2x1, l2y1, l2x2, l2y2, &x, &y);
            //std::cout << "cross point is: (" << x << "," << y << ")" << std::endl;
            //find the aera above the cross point.
            double x1 = l1y1 > l1y2 ? l1x1 : l1x2; 
            double y1 = l1y1 > l1y2 ? l1y1 : l1y2;
            double x2 = l2y1 > l2y2 ? l2x1 : l2x2; 
            double y2 = l2y1 > l2y2 ? l2y1 : l2y2;
            //std::cout << "point1:(" << x1 << "," << y1 << "), "
            //             "point2:(" << x2 << "," << y2 << ")" << std::endl;
            double hx = y1 > y2 ? x1 : x2;
            double hy = y1 > y2 ? y1 : y2;
            double lx = y1 <= y2 ? x1 : x2;
            double ly = y1 <= y2 ? y1 : y2;
            
            double height = ly - y;
            //std::cout << "height is:" << height << " ly:" << ly << " y:" << y << std::endl;
            if (height < 1e-8) {
                result = 0.0;
            } else if (left(x, y, hx, hy, lx, ly) && hx >= lx) {
                result = 0.0; 
            } else if (fabs(hy - ly) < 1e-8) { //the hight board must on the right of the low board.
                double width = hx - lx;
                //std::cout << "width:" << width << " lx:" << lx << " x:" << x << std::endl;
                result = std::fabs(height * width / 2.0);
            } else {
                //key point is the point of water's surface join to higher_board.
                double key_x = 0.0, key_y = 0.0;  
                cross_point(hx, hy, x, y, lx, ly, hx, ly, &key_x, &key_y);
                //std::cout << "key point is (" << key_x << "," << key_y << ")" << std::endl;
             
                double width = key_x - lx;
                result = std::fabs(height * width / 2.0);
            }
        } else {
            result = 0.0;
        }
        std::cout << result << std::endl;
    }
    return 0;
}
