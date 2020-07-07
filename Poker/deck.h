#pragma once
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#define DECK_SIZE 52
using namespace std;

struct card
{
  std::string suit; // spades, hearts, diamonds, clubs
  int value; // ace = 1, king = 13
};

class deck
{
private:
  vector <card> main_deck;

public:
  deck();
  void show_deck();
  void shuffle_deck();
  vector <card> get_card(int num_cards);
  vector <card> get_deck();
};

deck::deck()
{
  string suits[4] =
  {
    "Spades",
    "Hearts",
    "Diamonds",
    "Clubs"
  };
  int index = 0;

  for (int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 13; j++)
    {
      main_deck.push_back(card());
      main_deck[index].suit = suits[i];
      main_deck[index].value = j+1;
      index++;
    }
  }
}

void deck::show_deck()
{
  for (int i = 0; i < DECK_SIZE; i++)
  {
    cout << main_deck[i].value << main_deck[i].suit << endl;
  }
}

void deck::shuffle_deck()
{
  srand((unsigned)time(0));
  unsigned seed = rand();
  shuffle (main_deck.begin(), main_deck.end(), default_random_engine(seed));
}

vector <card> deck::get_card(int num_cards)
{
  vector <card> v;
  rotate(main_deck.begin(), main_deck.begin() +1, main_deck.end()); //burns
  for (int i = 0; i < num_cards; i++)
  {
    v.push_back(card());
    v[i].value = main_deck[i].value;
    v[i].suit = main_deck[i].suit;
  }
  return v;
}

vector <card> deck::get_deck()
{
  return main_deck;
}
