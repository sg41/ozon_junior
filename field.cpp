#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using Coord = std::pair<int, int>;
using Boxes = std::vector<std::tuple<Coord, Coord, int, int>>;

void parse_field(const std::vector<std::string> &field, Boxes &boxes,
                 Coord start, Coord end, int level) {
  Coord top_left, down_rigth;
  if (level > 0) {
    start.first += 1;
    start.second += 1;
    end.first -= 1;
    end.second -= 1;
  }
  for (int i = start.first; i < end.first; i++) {
    for (int j = start.second; j < end.second; j++) {
      if (field[i][j] == '*' && (i == 0 || field[i - 1][j] == '.') &&
          (j == 0 || field[i][j - 1] == '.')) {
        top_left = {i, j};
        if (std::find_if(boxes.begin(), boxes.end(), [top_left](auto box) {
              return std::get<0>(box) == top_left;
            }) != boxes.end()) {
          continue;
        }
        while (i < end.first && field[i][j] == '*') i++;
        while (j < end.second && field[i - 1][j] == '*') j++;
        down_rigth = {i - (i == end.first ? 0 : 1),
                      j - (j == end.second ? 0 : 1)};
        boxes.emplace_back(top_left, down_rigth,
                           (down_rigth.first - top_left.first + 1) *
                               (down_rigth.second - top_left.second + 1),
                           level);
        parse_field(field, boxes, top_left, down_rigth, level + 1);
        i = top_left.first;
        j = down_rigth.second;
        continue;
      }
    }
  }
}

int main(void) {
  int t;
  std::cin >> t;
  int n, m;
  std::vector<Boxes> boxes(t);
  std::vector<std::vector<std::string>> field(t);
  for (int i = 0; i < t; i++) {
    std::cin >> n >> m;
    field[i].resize(n);
    for (int j = 0; j < n; j++) {
      std::cin >> field[i][j];
    }
    parse_field(field[i], boxes[i], {0, 0}, {n, m}, 0);
  }
  for (int i = 0; i < t; i++) {
    std::vector<int> res;
    std::sort(boxes[i].begin(), boxes[i].end(),
              [](auto a, auto b) { return std::get<3>(a) < std::get<3>(b); });
    for (size_t j = 0; j < boxes[i].size(); j++) {
      std::cout << std::get<3>(boxes[i][j]) << " ";
    }
    std::cout << std::endl;
  }
}