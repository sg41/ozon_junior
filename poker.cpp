#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using Players = std::vector<std::pair<std::string, std::string>>;
using Cards = std::set<std::string>;

std::map<int, int> kRating = {
    {'A', 14}, {'K', 13}, {'Q', 12}, {'J', 11}, {'T', 10}, {'9', 9}, {'8', 8},
    {'7', 7},  {'6', 6},  {'5', 5},  {'4', 4},  {'3', 3},  {'2', 2},
};

bool check_winner(const std::string& card, const Players& hands) {
  std::set<std::pair<int, int>> winners{};
  for (int i = 0; i < hands.size(); i++) {
    if (hands[i].first[0] == hands[i].second[0] &&
        hands[i].first[0] == card[0]) {
      winners.insert(std::make_pair(300 + kRating[hands[i].first[0]], i));
      continue;
    }
    if (hands[i].first[0] == hands[i].second[0] ||
        hands[i].first[0] == card[0]) {
      winners.insert(std::make_pair(200 + kRating[hands[i].first[0]], i));
      continue;
    }
    if (hands[i].second[0] == card[0]) {
      winners.insert(std::make_pair(200 + kRating[hands[i].second[0]], i));
      continue;
    }
    int max_card =
        std::max(kRating[hands[i].first[0]], kRating[hands[i].second[0]]);
    max_card = std::max(max_card, kRating[card[0]]);
    winners.insert(std::make_pair(max_card, i));
  }
  bool result = false;
  auto winner = *winners.rbegin();
  if (winner.second == 0) {
    result = true;
  } else {
    for (auto w = winners.rbegin();
         w != winners.rend() && w->first == winner.first; w++) {
      if (w->second == 0) {
        result = true;
        break;
      }
    }
  }
  return result;
}

int main(void) {
  Cards deck{"AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "TS", "JS",
             "QS", "KS", "AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H",
             "TH", "JH", "QH", "KH", "AD", "2D", "3D", "4D", "5D", "6D", "7D",
             "8D", "9D", "TD", "JD", "QD", "KD", "AC", "2C", "3C", "4C", "5C",
             "6C", "7C", "8C", "9C", "TC", "JC", "QC", "KC"};
  int t, n;
  std::cin >> t;
  std::vector<Players> hands(t);
  std::vector<Cards> deck_copy(t, deck);
  for (int j = 0; j < t; j++) {
    std::cin >> n;
    hands[j].resize(n);
    for (int i = 0; i < n; i++) {
      std::cin >> hands[j][i].first >> hands[j][i].second;
      deck_copy[j].erase(hands[j][i].first);
      deck_copy[j].erase(hands[j][i].second);
    }
  }

  for (int i = 0; i < t; i++) {
    std::vector<std::string> win_deck{};
    for (auto card : deck_copy[i]) {
      if (check_winner(card, hands[i])) {
        win_deck.push_back(card);
      }
    }
    std::cout << win_deck.size() << std::endl;
    for (auto card : win_deck) {
      std::cout << card << std::endl;
    }
  }
  return 0;
}