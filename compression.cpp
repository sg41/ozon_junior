#include <iostream>
#include <vector>
int main(void) {
  int n;
  std::cin >> n;
  std::vector<int> out_sequence[n];
  for (int j = 0; j < n; j++) {
    int len;
    std::cin >> len;
    std::vector<int> sequence(len);
    for (int i = 0; i < len; i++) {
      std::cin >> sequence[i];
    }
    sequence.push_back(sequence[len - 1] + 10);  // Fake number
    if (len == 1) {
      out_sequence[j].push_back(sequence[0]);
      out_sequence[j].push_back(0);
      continue;
    }
    for (int i = 1; i < len + 1; i++) {
      int step = 0;
      int count = 0, start = sequence[i - 1];
      if (sequence[i] == sequence[i - 1] + 1) {
        step = +1;
      } else if (sequence[i] == sequence[i - 1] - 1) {
        step = -1;
      }
      while (step != 0 && sequence[i] == sequence[i - 1] + step && i < len) {
        count++;
        i++;
      }
      out_sequence[j].push_back(start);
      out_sequence[j].push_back(count * step);
    }
  }
  for (int j = 0; j < n; j++) {
    std::cout << out_sequence[j].size() << "\n";
    for (auto dig : out_sequence[j]) {
      std::cout << dig << " ";
    }
    std::cout << "\n";
  }
}