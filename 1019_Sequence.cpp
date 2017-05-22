#include <iostream>
#include <sstream>
// l(n) is length of n
// l(n) = 1   1 <= n <= 9
// l(n) = 2   10 <= n <= 99
// l(n) = 3   100 <= n <= 999
// l(n) = 4   1000 <= n <= 9999
// ...
//
// s(n) = \sum{1}{n}l(i)
// s(n) = n                      1 <= n <= 9
// s(n) = 2 * n - 9              10 <= n <= 99
// s(n) = 3 * n - 99 - 9         100 <= n <= 999
// s(n) = 4 * n - 999 - 99 - 9   1000 <= n <= 9999
// ...
//
// S(n) = \sum{1}{n}s(i)
// S(n) = (n + 1) * n / 2        1 <= n <= 9
// S(n) = (9 + 1) * 9 / 2 + (2 * 10 - 9 + 2 * n - 9) * 90 / 2        10 <= n <= 99
// ...

int l(int n) {
  if (1 <= n && n <= 9) return 1;
  if (10 <= n && n <= 99) return 2;
  if (100 <= n && n <= 999) return 3;
  if (1000 <= n && n <= 9999) return 4;
  if (10000 <= n && n <= 99999) return 5;
  if (100000 <= n && n <= 999999) return 6;
  else return 7;
}

long long s(int n) {
  if (1 <= n && n <= 9) return n;
  else if (10 <= n && n <= 99) return 2 * n - 9;
  else if (100 <= n && n <= 999) return 3 * n - 99 - 9;
  else if (1000 <= n && n <= 9999) return 4 * n - 999 - 99 - 9;
  else if (10000 <= n && n <= 99999) return 5 * n - 9999 - 999 - 99 - 9;
  else if (100000 <= n && n <= 999999) return 6 * n - 99999 - 9999 - 999 - 99 - 9;
  else return 7 * n - 999999 - 99999 - 9999 - 999 - 99 - 9;
}

long long S(int n) {
  if (1 <= n && n <= 9) return (n + 1) * n / 2;
  else if (10 <= n && n <= 99) return S(9) + (s(10) + s(n)) * (n - 9) / 2;
  else if (100 <= n && n <= 999) return S(99) + (s(100) + s(n)) * (n - 99) / 2;
  else if (1000 <= n && n <= 9999) return S(999) + (s(1000) + s(n)) * (n - 999) / 2;
  else if (10000 <= n && n <= 99999) return S(9999) + (s(10000) + s(n)) * (n - 9999) / 2;
  else if (100000 <= n && n <= 999999) return S(99999) + (s(100000) + s(n)) * (n - 99999) / 2;
  else return S(999999) + (s(1000000) + s(n)) * (n - 999999) / 2;
}

std::string itoa(int n) {
  std::stringstream ss;
  ss << n;
  return ss.str();
}

int binary_search(int m, long long(*f)(int)) {
  int start = 1;
  int end = 99999;
  while (start <= end) {
    int mid = (start + end) / 2;
    long long f_mid = f(mid);
    if (f_mid > m) {
      end = mid - 1;
    } else if (f_mid <= m && f(mid+1) > m) {
      return mid;
    } else {
      start = mid + 1;
    }
  }
  return start;
}

int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int m = 0;
    std::cin >> m;

    int m1 = binary_search(m, S);
    if (S(m1) == m) {
      std::cout << *itoa(m1).rbegin() << std::endl;
    } else {
      int m2 = binary_search(m - S(m1), s);
      int n = m - S(m1) - s(m2);
      if (n == 0) {
        std::cout << *itoa(m2).rbegin() << std::endl;
      } else {
        std::cout << itoa(m2+1)[n-1] << std::endl;
      }
    }
  }
  return 0;
}
