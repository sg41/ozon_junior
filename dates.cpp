#include <iostream>

int main(void) {
  int last_day[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int day, month, year;
    std::cin >> day >> month >> year;
    if (day <= last_day[month - 1]) {
      std::cout << "YES\n";
    } else {
      if (month == 2 &&
          ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && day == 29)
        std::cout << "YES\n";
      else
        std::cout << "NO\n";
    }
    std::fflush(stdout);
  }
  return 0;
}