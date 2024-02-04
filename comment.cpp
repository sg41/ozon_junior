/*
Условие задачи
Вам задан набор комментариев. Каждый комментарий описывается тремя параметрами:
  ∙ своим идентификатором (уникальное целое число от 1 до 10^9),
  ∙ идентификатором предка (или -1, если предка нет),
  ∙ своим текстом (непустая строка из символов с кодами от 32 до 126,
включительно). Выведите заданные комментарии в древесном виде, отформатировав их
в точности так, как изображено в примерах. Обратите внимание, что для каждого
комментария-родителя его детей надо выводить в порядке увеличения их
идентификаторов. Иными словами, всех детей одного родителя надо упорядочивать по
возрастанию их идентификаторов. Внимательно изучите примеры, точно следуйте всем
особенностям форматирования (включая количество пробелов и т.п.). Вы можете
выводить произвольное количество пробелов в конце строки. Например, при выводе
<< | | | >> допустимо вывести << | | | >>.
Входные данные
Входные данные состоят из одного или более набора входных данных.
Наборы входных данных в тесте являются независимыми. Друг на друга они никак не
влияют. В первой строке записано целое число t (1≤t≤100) — количество наборов
входных данных в тесте. Далее следуют t наборов входных данных. Каждый набор
входных данных начинается строкой, которая содержит целое число n (1≤n≤200) —
количество комментариев. Далее заданы сами комментарии, по одному в строке.
Каждая строка имеет вид << id p text >>, где id — идентификатор комментария
(уникальное целое число от 1 до 10^9), p — идентификатор предка или -1, если
предка нет, text — текст комментария в виде непустой строки длины не более 100.
Текст содержит только символами с кодами от 32 до 126.
Гарантируется, что заданные комментарии корректны — задают одно или более дерево
комментариев (циклические зависимости запрещены, если указан родитель, то он
существует).
Выходные данные
Выведите комментарии в виде деревьев. Между выводами для разных наборов входных
данных выводите пустую строку. В точности следуйте примерам, ваш вывод должен в
точности совпадать с выводом авторского решения.
Пример теста 1
Входные данные

4
14
75 22 I'm fine. Thank you.
84 82     Ciao!
26 22 So-so
45 26 What's wrong?
22 -1 How are you?
72 45 Maybe I got sick
81 72 I wish you a speedy recovery!
97 26   Stick it!
2 97 Thanks
47 72 I also got sick recently.
25 -1 Hi!
82 -1 Bye
17 82 Good day!
29 72 Visit the doctor
8
5 4 e
6 5 f
7 6 g
1 -1 a
2 1 b
3 2 c
4 3 d
8 7 h
6
10 -1 x
20 10 x
40 -1 x
50 -1 x
11 20 x
30 10 x
1
1000000000 -1 root
Выходные данные

How are you?
|
|--So-so
|  |
|  |--What's wrong?
|  |  |
|  |  |--Maybe I got sick
|  |     |
|  |     |--Visit the doctor
|  |     |
|  |     |--I also got sick recently.
|  |     |
|  |     |--I wish you a speedy recovery!
|  |
|  |--  Stick it!
|     |
|     |--Thanks
|
|--I'm fine. Thank you.

Hi!

Bye
|
|--Good day!
|
|--    Ciao!

a
|
|--b
   |
   |--c
      |
      |--d
         |
         |--e
            |
            |--f
               |
               |--g
                  |
                  |--h

x
|
|--x
|  |
|  |--x
|
|--x

x

x

root
*/
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using Comments = std::map<int, std::map<int, std::string>>;

void PrintPrefix(int level, const std::vector<std::string>& prefix) {
  if (level == 0) return;
  for (auto p : prefix) std::cout << p;
  std::cout << "|\n";
  for (auto p : prefix) std::cout << p;
  std::cout << "|--";
}
void PrintCommentTree(Comments& comments, int parent_id, int level,
                      std::vector<std::string>& prefix) {
  size_t count = 0;
  for (auto [id, text] : comments[parent_id]) {
    PrintPrefix(level, prefix);
    if (level != 0) {
      if (comments[parent_id].size() > 1 &&
          count != comments[parent_id].size() - 1) {
        prefix.push_back("|  ");
      } else {
        prefix.push_back("   ");
      }
    }
    std::cout << text << std::endl;
    PrintCommentTree(comments, id, level + 1, prefix);
    if (prefix.size() > 0) prefix.pop_back();
    count++;
  }
  if (level == 1) std::cout << std::endl;
}

int main(void) {
  int t, n;
  std::cin >> t;
  std::vector<Comments> comments(t);
  for (int i = 0; i < t; i++) {
    std::cin >> n;
    for (int j = 0; j < n; j++) {
      int id, p;
      std::string text;
      std::cin >> id >> p;
      std::cin.ignore();
      std::getline(std::cin, text);
      comments[i][p][id] = text;
    }
  }
  std::vector<std::string> prefix{};
  for (int i = 0; i < t; i++) {
    PrintCommentTree(comments[i], -1, 0, prefix);
  }
}