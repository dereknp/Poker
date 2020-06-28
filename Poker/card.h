#include <iostream>

class Card {
 public:
  Card(int value, const std::string &suit);
  Card();
  bool operator<(const Card& rhs);
 private:
  int value;
  std::string suit;
};

Card::Card(int value, const std::string& suit) : value(value), suit(std::move(suit)) {}

Card::Card() : Card(-1, "") {}

// form of LHS < RHS
// ex      5 "Diamonds" < 8 "Hearts"
bool operator<(const card& rhs) {
  // note ace has value 1
  bool lhs_is_ace = this->value == 1;
  bool rhs_is_ace = rhs.value == 1;

  // ex. 1 < 7
  if (lhs_is_ace && !rhs_is_ace) {
    return false;
  }
  // ex. 5 < 1
  if (rhs_is_ace && !lhs_is_ace) {
    return true;
  }
  return this->value < rhs.value;
}