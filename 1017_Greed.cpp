#include <iostream>
void greed_search(int* packages, const int length, int* result) {
    int num_package_2 = 0;
    for (int i = length - 1; i >= 0 ; i--) {
        if (!packages[i]) continue;

        (*result) ++;
        switch (i + 1) {
        case 6:
            packages[5] --;
            return greed_search(packages, length, result);
        case 5:
            if (packages[0] <= 11) packages[0] = 0;
            else packages[0] -= 11;
            packages[4] --;
            return greed_search(packages, length, result);
        case 4:
            if (packages[1] <= 5) { 
                if (packages[0] <= 20 - packages[1] * 2) packages[0] = 0;
                else packages[0] -= 20 - packages[1] * 2;
                packages[1] = 0;
            } else {
                packages[1] -= 5;
            }
            packages[3] --;
            return greed_search(packages, length, result);
        case 3:
            if (packages[2] == 1) {
                num_package_2 = packages[1];
                if (packages[1] <= 5) {
                    packages[1] = 0;
                } else {
                    packages[1] -= 5;
                }
                if (packages[0] <= 27 - (num_package_2 > 5 ? 5 : num_package_2) * 4) {
                    packages[0] = 0;
                } else {
                    packages[0] -= 27 - (num_package_2 > 5 ? 5 : num_package_2) * 4;
                }
                packages[2] = 0;
            } else if (packages[2] == 2) {
                num_package_2 = packages[1];
                if (packages[1] <= 3) {
                    packages[1] = 0;
                } else {
                    packages[1] -= 3;
                }
                if (packages[0] <= 18 - (num_package_2 > 3 ? 3 : num_package_2) * 4) {
                    packages[0] = 0;
                } else {
                    packages[0] -= 18 - (num_package_2 > 3 ? 3 : num_package_2) * 4;
                }
                packages[2] = 0;
            } else if (packages[2] == 3) {
                num_package_2 = packages[1];
                if (packages[1] <= 1) {
                    packages[1] = 0;
                } else {
                    packages[1] -= 1;
                }
                if (packages[0] <= 9 - (num_package_2 > 1 ? 1 : num_package_2) * 4) {
                    packages[0] = 0;
                } else {
                    packages[0] -= 9 - (num_package_2 > 1 ? 1 : num_package_2)  * 4;
                }
                packages[2] = 0;
            } else {
                packages[2] -= 4;
            }
            return greed_search(packages, length, result);
        case 2:
            num_package_2 = packages[1];
            if (packages[1] < 9) {
                packages[1] = 0;
            } else {
                packages[1] -= 9;
            }
            if (packages[0] < 36 - 4 * (num_package_2 > 9 ? 9 : num_package_2)) {
                packages[0] = 0;
            } else {
                packages[0] -= 36 - 4 * (num_package_2 > 9 ? 9 : num_package_2);
            }
            return greed_search(packages, length, result);
        case 1:
            if (packages[0] <= 36) {
                packages[0] = 0;
            } else {
                packages[0] -= 36;
                return greed_search(packages, length, result);
            }
        }
    }
}
int main() {
    int packages[6];

    while (true) {
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            std::cin >> packages[i];
            sum += packages[i];
        }
        if (!sum) { break; }
        
        int result = 0; 
        greed_search(packages, 6, &result);
        std::cout << result << std::endl;
    }
    return 0;
}
