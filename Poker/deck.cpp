#include <iostream>
#include <ctime>
#include <random>
#include "deck.h"
#define DECK_SIZE 52
using namespace std;

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
  /*
  optimize using built in shuffle method
  */
  srand((unsigned)time(0));
  for (int i = 0; i < 150; i++)
  {
    unsigned idx1 = rand() % DECK_SIZE;
    unsigned idx2 = rand() % DECK_SIZE;
    swap(main_deck[idx1], main_deck[idx2]);
  }
}

card deck::get_card()
{
  // maybe optimize incrementing w/ circular array notation
  static int idx = 0;
  idx++;
  if (idx >= 52)
  {
    idx = 0;
  }
  return main_deck[idx];
}
