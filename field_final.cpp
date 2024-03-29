/*
Условие задачи
Игровое поле представляет собой белый прямоугольник n×m, на котором изображены
черные прямоугольные рамки. Толщина каждой рамки равна 1, рамки не пересекаются
и не касаются. Таким образом, для любых двух рамок A и B верно: либо A вложена в
B, либо B вложена в A, либо A не вложена в B и одновременно B не вложена в A.
Пример возможного поля изображён ниже. Белые символы обозначены точками ('.'),
чёрные — звёздочками ('*').
*********......
*********......
*.......*..****
*.......*..****
*.***...*..*..*
*.***...*..*..*
*.*.*...*..****
*.*.*...*..****
*.***...*......
*.***...*......
*.......*......
*.......*......
*...***.*......
*...***.*......
*...*.*.*.***..
*...*.*.*.***..
*...*.*.*.*.*..
*...*.*.*.*.*..
*...*.*.*.***..
*...*.*.*.***..
*...***.*......
*...***.*......
*.......*......
*.......*......
*.......*......
*.......*......
*********......
*********......
...............
...............
.**************
.**************
.*............*
.*............*
.*.*********..*
.*.*********..*
.*.*.......*..*
.*.*.......*..*
.*.*.*****.*..*
.*.*.*****.*..*
.*.*.*...*.*..*
.*.*.*...*.*..*
.*.*.*****.*..*
.*.*.*****.*..*
.*.*.......*..*
.*.*.......*..*
.*.*********..*
.*.*********..*
.*............*
.*............*
.**************
.**************
Для каждой рамки найдите количество рамок, в которые она вложена. Выведите
получившиеся r чисел в порядке неубывания, где r — количество рамок на поле.
Например, для поля выше результат имеет вид: 0,0,0,0,1,1,1,2 (четыре рамки не
вложены в какие-либо другие, три рамки вложены в одну, одна рамка вложена в
две).

Входные данные
В первой строке входных данных записано целое число t (1≤t≤1000) — количество
наборов входных данных. Наборы входных данных в тесте являются независимыми.
Друг на друга они никак не влияют. Первая строка каждого набора входных данных
содержит пару целых чисел n,m (3≤n,m≤2000) — количество строк и столбцов на
поле. Далее следуют n строк по m символов в каждой строке. Каждый символ это
либо ‘.’ (пустая белая клетка), либо ‘*’ (чёрная клетка, то есть часть рамки).
Гарантируется, что каждая рамка имеет прямоугольную форму, толщина каждой рамки
равна 1. Ширина и высота каждой рамки не меньше 3. Никакие две рамки не
пересекаются и не касаются по стороне или углу. На поле есть хотя бы одна рамка.
Гарантируется, что суммарный размер (площадь) всех полей в тесте не превосходят
4⋅10^6.
Выходные данные
Для каждого набора входных данных выведите строку из целых чисел — глубины
вложенностей рамок в отсортированном по неубыванию порядке.
Пример теста 1
Входные данные
3
26 15
*********......
*.......*..****
*.***...*..*..*
*.*.*...*..****
*.***...*......
*.......*......
*...***.*......
*...*.*.*.***..
*...*.*.*.*.*..
*...*.*.*.***..
*...***.*......
*.......*......
*.......*......
*********......
...............
.**************
.*............*
.*.*********..*
.*.*.......*..*
.*.*.*****.*..*
.*.*.*...*.*..*
.*.*.*****.*..*
.*.*.......*..*
.*.*********..*
.*............*
.**************
15 15
***************
*.............*
*.***********.*
*.*.........*.*
*.*.*******.*.*
*.*.*.....*.*.*
*.*.*.***.*.*.*
*.*.*.*.*.*.*.*
*.*.*.***.*.*.*
*.*.*.....*.*.*
*.*.*******.*.*
*.*.........*.*
*.***********.*
*.............*
***************
3 4
***.
*.*.
***.
Выходные данные
0 0 0 0 1 1 1 2
0 1 2 3
0
*/
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