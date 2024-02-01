#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using Comments = std::map<int, std::pair<int, std::string>>;

struct Comment {
  int parent_id = -1;
  int id = 0;
  std::set<Comment> childs;
};

struct CommentTree {
  Comment root;
};

int main(void) {
  int t, n;
  std::cin >> t;
  std::vector<Comments> comments(t);
  for (int i = 0; i < t; i++) {
    std::cin >> n;
    for (int j = 0; j < n; j++) {
      int id, p;
      std::string text;
      std::cin >> id >> p >> text;
      comments[i][id] = std::make_pair(p, text);
    }
  }
  for (int i = 0; i < t; i++) {
  }
}