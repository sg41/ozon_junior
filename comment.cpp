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