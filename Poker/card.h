#include <iostream>

class Card {
 public:
  Card(int value, const std::string &suit);
  Card();
  bool operator<(const Card& rhs);
 private:
  int value;
  std::string suit;
}