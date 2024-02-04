#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Comment {
  int id;
  int parent;
  string text;
};

map<int, vector<Comment>> comments;

void PrintVLines(int level) {
  for (int i = 0; i < level + 1; ++i) {
    cout << "|  ";
  }
  std::cout << std::endl;
  for (int i = 0; i < level; ++i) {
    cout << "|  ";
  }
}

void printCommentTree(int parentId, int level) {
  sort(comments[parentId].begin(), comments[parentId].end(),
       [](const Comment& a, const Comment& b) { return a.id < b.id; });

  for (const auto& comment : comments[parentId]) {
    // for (int i = 0; i < level; ++i) {
    //   cout << "|  ";
    // }
    PrintVLines(level);
    cout << "|--" << comment.text << endl;
    if (comments.find(comment.id) != comments.end()) {
      printCommentTree(comment.id, level + 1);
    }
  }
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    comments.clear();

    for (int j = 0; j < n; ++j) {
      int id, parent;
      string text;
      cin >> id >> parent;
      cin.ignore();
      getline(cin, text);
      comments[parent].push_back({id, parent, text});
    }

    for (const auto& comment : comments[-1]) {
      cout << comment.text << endl;
      printCommentTree(comment.id, 0);
    }

    if (i < t - 1) {
      cout << endl;
    }
  }

  return 0;
}