#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using Coord = std::pair<int, int>;
using Box = std::tuple<Coord, Coord, int, int>;
using Boxes = std::vector<Box>;

void parse_field(std::vector<std::string> &field, Boxes &boxes, Coord start,
                 Coord end, int level) {
  Coord top_left, down_rigth;
  if (level > 0) {
    start.first += 2;
    start.second += 2;
    end.first -= 1;
    end.second -= 1;
  }

  for (int i = start.first; i < end.first; i++) {
    for (int j = start.second; j < end.second; j++) {
      if (field[i][j] == '*' && (i == 0 || field[i - 1][j] == '.') &&
          (j == 0 || field[i][j - 1] == '.')) {
        top_left = {i, j};
        // auto box = std::find_if(
        //     boxes.begin(), boxes.end(),
        //     [top_left](auto box) { return std::get<0>(box) == top_left; });
        // if (box != boxes.end()) {
        //   j = std::get<1>(*box).second + 1;
        //   continue;
        // }
        i += 3;
        while (i < end.first && field[i][j] == '*') i++;
        j += 3;
        while (j < end.second && field[i - 1][j] == '*') j++;
        down_rigth = {i - 1, j - 1};
        boxes.emplace_back(top_left, down_rigth, 0, level);
        if (down_rigth.first - top_left.first > 5 &&
            down_rigth.second - top_left.second > 5)
          parse_field(field, boxes, top_left, down_rigth, level + 1);
        field[top_left.first][top_left.second] = '0';  // mark visited
        i = top_left.first;
        j = down_rigth.second;
        continue;
      }
    }
  }
}

void simple_parse_field(std::vector<std::string> &field, Boxes &boxes,
                        Coord start, Coord end, int level) {
  Coord top_left, down_rigth;
  for (int i = start.first; i < end.first; i++) {
    for (int j = start.second; j < end.second; j++) {
      if (field[i][j] == '*' && (i == 0 || field[i - 1][j] == '.') &&
          (j == 0 || field[i][j - 1] == '.')) {
        top_left = {i, j};
        i += 3;
        while (i < end.first && field[i][j] == '*') i++;
        j += 3;
        while (j < end.second && field[i - 1][j] == '*') j++;
        down_rigth = {i - 1, j - 1};
        int len = down_rigth.second - top_left.second + 1;
        int height = down_rigth.first - top_left.first + 1;
        int square = (height) * (len);
        boxes.emplace_back(top_left, down_rigth, square, level);
        i = top_left.first;
        j = down_rigth.second;
        continue;
      }
    }
  }
}

bool is_inside(const Box &a, const Box &b) {
  bool res = false;
  if (std::get<0>(a).first < std::get<0>(b).first &&
      std::get<1>(a).first > std::get<1>(b).first &&
      std::get<0>(a).second < std::get<0>(b).second &&
      std::get<1>(a).second > std::get<1>(b).second) {
    res = true;
  }
  return res;
}
void mark_levels(std::vector<Boxes> &boxes, int i) {
  std::sort(boxes[i].begin(), boxes[i].end(),
            [](auto a, auto b) { return std::get<2>(a) > std::get<2>(b); });
  for (size_t b = 0; b < boxes[i].size(); b++) {
    if (b == 0) {
      std::get<3>(boxes[i][b]) = 0;
      continue;
    }
    if (is_inside(boxes[i][b - 1], boxes[i][b])) {
      std::get<3>(boxes[i][b]) = std::get<3>(boxes[i][b - 1]) + 1;
    } else {
      for (int r = b - 2; r >= 0; r--) {
        if (is_inside(boxes[i][r], boxes[i][b])) {
          std::get<3>(boxes[i][b]) = std::get<3>(boxes[i][r]) + 1;
          break;
        }
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
    // parse_field(field[i], boxes[i], {0, 0}, {n, m}, 0);
    simple_parse_field(field[i], boxes[i], {0, 0}, {n, m}, 0);
  }

  for (int i = 0; i < t; i++) {
    mark_levels(boxes, i);

    std::sort(boxes[i].begin(), boxes[i].end(),
              [](auto a, auto b) { return std::get<3>(a) < std::get<3>(b); });
    for (size_t j = 0; j < boxes[i].size(); j++) {
      std::cout << std::get<3>(boxes[i][j]) << " ";
    }
    std::cout << std::endl;
  }
}