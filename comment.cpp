#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

struct Comment {
  int parent_id = -1;
  int id = 0;
  std::string text;
  // std::set<Comment> childs{};
};

// using Comments = std::map<int, std::vector<Comment>>;
using Comments = std::map<int, std::vector<Comment>>;

void PrintPrefix(int level) {
  if (level == 0) return;
  std::cout << "|\n";
  std::cout << "|";
  for (int i = 0; i < level; ++i) {
    std::cout << "|--";
  }
}
void PrintCommentTree(Comments& comments, int parent_id, int level) {
  for (auto child : comments[parent_id]) {
    PrintPrefix(level);
    std::cout << child.text << std::endl;
    PrintCommentTree(comments, child.id, level + 1);
  }
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
      comments[i][p].push_back({p, id, text});
    }
  }
  for (int i = 0; i < t; i++) {
    PrintCommentTree(comments[i], -1, 0);
  }
}