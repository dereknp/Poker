#include <iostream>
#include "player.h"
#include "deck.h"
using namespace std;

player::player()
{
  money = 500;
  for (int i = 0; i < 2; i++)
  {
    hand[i].value = -1;
    hand[i].suit = "None";
  }
}

void player::show_info()
{
  for (int i = 0; i < 2; i++)
  {
    cout << hand[i].suit << hand[i].value << endl;
  }
  cout << "Chips remaining: " << money << endl;
}

int player::bet(int min_bet)
{
  int bet_amount = 0;
  do
  {
    cout << "Enter bet: ";
    cin >> bet_amount;
  } while(bet_amount > money && bet_amount < min_bet);
  money-=bet_amount;
  return bet_amount;
}

void player::get_hand(card one, card two)
{
  hand[0].value = one.value;
  hand[0].suit = one.suit;
  hand[1].value = two.value;
  hand[1].suit = two.suit;
}
