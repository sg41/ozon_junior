#include <cctype>
#include <iostream>
#include <set>
#include <string>
#include <vector>
int main(void) {
  int t;
  std::cin >> t;
  int k[t];
  std::vector<std::string> pages(t, "");
  std::vector<std::set<int>> printed(t);
  for (int i = 0; i < t; i++) {
    std::cin >> k[i] >> pages[i];
  }
  for (int i = 0; i < t i++) {
    for (int p = 0; p < k[i]; p++) {
    }
  }
  return 0;
}