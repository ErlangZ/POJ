#include <iostream>
#include <cstring>

//@brief (x2, y2) on the [(x0, y0), (x1, y1)] left
bool left(const int x0, const int y0, const int x1, const int y1, const int x2, const int y2) {
    int v1x = x1 - x0;
    int v1y = y1 - y0;
    int v2x = x2 - x0;
    int v2y = y2 - y0;
    return (v1x * v2y - v2x * v1y) <= 0;
}

int main() {
    int x, y;
    int n, m, x0, y0, x1, y1;
    int x_upper[5003], x_lower[5003];//x_upper & x_lower has n+2 segments, including 2 bounds.
    int result[5003];
    while(true) {
        memset(result, 0, sizeof(result));
        std::cin >> n >> m >> x0 >> y0 >> x1 >> y1;
        if (n == 0) break;
        
        x_upper[0] = x0;
        x_lower[0] = x0;
        for (int i = 0; i < n; i++) { 
            std::cin >> x_upper[i+1] >> x_lower[i+1];
        } 
        x_upper[n+1] = x1;
        x_lower[n+1] = x1;
        
        for (int i = 0; i < m; i++) {
            std::cin >> x >> y; 
            size_t lower = 0, upper = n+2; // upper & lower are the indexes for regions [0,1,..,n+1].
            while (true) {
                const size_t mid = (lower + upper) / 2;
                const bool left1 = left(x_upper[mid], y0, x_lower[mid], y1, x, y);
                const bool left2 = left(x_upper[mid+1], y0, x_lower[mid+1], y1, x, y);
                if (!left1 && left2) {
                    result[mid] ++; 
                    break;
                }
                if (left1) {
                    upper = mid;
                } else {
                    lower = mid+1;
                }
            }
        }

        for (int i = 0; i < n+1; i++) {
            std::cout << i << ": " << result[i] << std::endl;
        }
        std::cout << std::endl;
    }
}
