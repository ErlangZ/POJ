#include <iostream>
#include <cstring>
#include <iomanip>
int main () {
    const int NUM = 3000;
    int band[2][NUM];

    int t = 0;
    int n = 0;

    std::cin >> t;
    for (int t0 = 0; t0 < t; t0++) {
    std::cin >> n;
    std::memset(band, 0x7f, sizeof(band));

    int m = 0;
    int b = 0, p = 0;
    int index = 0;

    std::cin >> m;
    for (int j = 0; j < m; j++) {
        std::cin >> b >> p;
        band[index][b] = p;
    }

    for (int i = 1; i < n; i++) {
        std::cin >> m;
        for (int j = 0; j < m; j++) {
            std::cin >> b >> p;
            for (int k = 0; k < NUM ; k++) {
                if (band[index][k] == 0x7f7f7f7f) continue;
                if (k <= b) {
                    if (band[(index+1)%2][k] > band[index][k] + p) {
                        band[(index+1)%2][k] = band[index][k] + p;
                    }
                } else {
                    if (band[(index+1)%2][b] > band[index][k] + p) {
                        band[(index+1)%2][b] = band[index][k] + p;
                    }
                }
            }
        }
        for (int j = 0; j < NUM; j++) {
            band[index][j] = 0x7f7f7f7f;
        }
        index = (index+1) % 2;
    }

    double result = 0.0;
    for (int i = 0; i < NUM; i++) {
        if (band[index][i] == 0x7f7f7f7f) continue;
        if (result < static_cast<double>(i) / band[index][i]) {
            result = static_cast<double>(i) / band[index][i];
        }
    }
    std::cout << std::fixed << std::setprecision(3) << result << std::endl;
    
    }
}
