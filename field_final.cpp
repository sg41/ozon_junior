#include <algorithm>
#include <iostream>
#include <vector>
using Coord = std::pair<int, int>;

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> field(n);
    for (int i = 0; i < n; i++) {
      std::cin >> field[i];
    }

    std::vector<std::vector<int>> depth(n, std::vector<int>(m, -1));
    std::vector<int> depths;
    int level = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (field[i][j] == '*' && (i == 0 || field[i - 1][j] == '.') &&
            (j == 0 || field[i][j - 1] == '.')) {
          Coord start = {i, j};
          //   level = (i == 0) ? 0 : depth[i - 1][j] + 1;
          level = (j == 0) ? 0 : depth[i][j - 1] + 1;
          depths.push_back(level);
          while (j < m && field[i][j] == '*') {
            depth[i][j] = level;
            j++;
          }
          int width = j - start.second;
          while (i < n && field[i][j - 1] == '*') {
            depth[i][j - 1] = level - 1;  // close level
            depth[i][start.second] = level;
            i++;
          }
          //   int height = start.first - i;
          for (int c = 0; c < width - 1; c++) {
            depth[i - 1][start.second + c] = level;
          }
          i = start.first;
          j--;
          continue;
        }
        if (field[i][j] == '*' && (j < m - 1 && field[i][j + 1] == '*')) {
          while (j < m && field[i][j] == '*') {
            j++;
          }
          j--;
          continue;
        }
        if (field[i][j] == '*') {
          level = depth[i][j];
          j++;
          while (j < m && field[i][j] == '.') {
            depth[i][j] = level;
            j++;
          }
          j--;
          continue;
        }
        if (field[i][j] == '.') {
          depth[i][j] = (j == 0 ? -1 : depth[i][j - 1]);
        }
      }
    }

    sort(depths.begin(), depths.end());
    for (int d : depths) {
      std::cout << d << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}