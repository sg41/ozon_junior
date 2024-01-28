#include <iostream>
#include <string>
#include <vector>
int main(void) {
  int n;
  std::cin >> n;
  std::string in[n];
  for (int i = 0; i < n; i++) {
    std::cin >> in[i];
  }
  for (auto str : in) {
    std::vector<std::string> out(1, "");
    int l = 0, p = 0;
    for (int i = 0; i < str.size(); i++) {
      if ((str[i] >= 'a' && str[i] <= 'z') ||
          (str[i] >= '0' && str[i] <= '9')) {
        out[l].insert(p++, 1, str[i]);
      }
      if (str[i] == 'L' && p > 0) p--;
      if (str[i] == 'R' && p < out[l].size()) p++;
      if (str[i] == 'B') p = 0;
      if (str[i] == 'E') p = out[l].size();
      if (str[i] == 'U' && l > 0) {
        l--;
        if (p > out[l].size()) p = out[l].size();
      }
      if (str[i] == 'D' && l < out.size() - 1) {
        l++;
        if (p > out[l].size()) p = out[l].size();
      }
      if (str[i] == 'N') {
        if (p < out[l].size()) {
          out.insert(out.begin() + l + 1, out[l].substr(p));
          out[l].erase(p);
        } else {
          out.insert(out.begin() + l + 1, "");
        }
        l++;
        p = 0;
      }
    }
    for (auto o_str : out) {
      std::cout << o_str << "\n";
    }
    std::cout << "-\n";
  }
}