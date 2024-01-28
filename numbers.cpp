#include <iostream>
#include <string>

bool is_digit(char ch) { return (ch >= '0' && ch <= '9'); }

bool is_alpha(char ch) {
  return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
int main(void) {
  int n;
  std::cin >> n;
  std::string numbers[n];
  for (int i = 0; i < n; i++) {
    std::cin >> numbers[i];
  }
  for (auto number : numbers) {
    std::string res;
    for (int i = 0; i < number.size();) {
      if (is_alpha(number[i]) && is_digit(number[i + 1])) {
        int len = 4;
        if (is_digit(number[i + 2])) len++;
        if (is_alpha(number[i + len - 1]) && is_alpha(number[i + len - 2])) {
          res = res + number.substr(i, len) + " ";
          i += len;
          continue;
        }
      }
      res = "-";
      break;
    }
    std::cout << res << std::endl;
  }
  return 0;
}