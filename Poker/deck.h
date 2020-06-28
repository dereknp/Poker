#pragma once
#define DECK_SIZE 52

typedef struct card
{
  std::string suit; // spades, hearts, diamonds, clubs
  int value; // ace = 1, king = 13
}card;

class deck
{
private:
  card main_deck[DECK_SIZE];

public:
  deck();
  void show_deck();
  void shuffle_deck();
  card get_card();
};
