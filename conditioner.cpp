#include <iostream>
#include <string>
int main(void) {
  int n;
  std::cin >> n;
  const int kTLow = 15, kTHigh = 30;
  for (int i = 0; i < n; i++) {
    int m;
    int cur_max = kTHigh, cur_min = kTLow;
    std::cin >> m;
    bool clinch = false;
    for (int j = 0; j < m; j++) {
      int temp;
      std::string sign;
      std::cin >> sign >> temp;
      if (!clinch) {
        if (sign == ">=") {
          if (temp > cur_min) {
            cur_min = temp;
          }
        } else {
          if (temp < cur_max) {
            cur_max = temp;
          }
        }
      }
      if (cur_max < cur_min) {
        std::cout << -1 << "\n";
        clinch = true;
      } else {
        std::cout << cur_min << "\n";
      }
    }
    std::cout << std::endl;
  }
  return 0;
}