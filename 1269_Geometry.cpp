#include <cstdio>
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << "INTERSECTING LINES OUTPUT" << std::endl;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        //Line-1
        std::cin >> x1 >> y1 >> x2 >> y2;
        int a1 = y2 - y1;
        int b1 = x1 - x2;
        int c1 = x2 * y1 - x1 * y2;
        //Line-2
        std::cin >> x1 >> y1 >> x2 >> y2;
        int a2 = y2 - y1;
        int b2 = x1 - x2;
        int c2 = x2 * y1 - x1 * y2;

        //Check the lines
        int det = a1 * b2 - a2 * b1;
        if (det == 0) { // parallel or same-line
            int div1 = a1 * a1 + b1 * b2;
            int div2 = a2 * a2 + b1 * b2;
            // a1/a2 == b1/b2 == c1/c2;
            if (c1*c1*div2 == c2*c2*div1) {
                std::cout << "LINE" << std::endl;
            } else {
                std::cout << "NONE" << std::endl;
            }
        } else {
            double x, y;
            x = (b1*c2-b2*c1) / static_cast<double>(a1*b2-b1*a2);
            y = (a2*c1-a1*c2) / static_cast<double>(a1*b2-b1*a2);
            //printf("POINT %.2f %.2f\n", x, y);
            std::cout << "POINT " << std::fixed << std::setprecision(2) << x << " " << y << std::endl;
        }
    }
    std::cout << "END OF OUTPUT" << std::endl;
    return 0;
}
