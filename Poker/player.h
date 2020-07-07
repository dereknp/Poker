#pragma once
#include <iostream>
#include "deck.h"
using namespace std;

class player
{
private:
  card hand[2];
  int money;

public:
  player();
  void show_info();
  int bet(int min_bet);
  void get_hand(vector <card> from_deck);
};

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
  // need to fix betting logic
  int bet_amount = 0;
  do
  {
    cout << "Enter bet: ";
    cin >> bet_amount;
  } while(bet_amount > money && bet_amount < min_bet);
  money-=bet_amount;
  return bet_amount;
}

void player::get_hand(vector <card> from_deck)
{
  hand[0].value = from_deck[0].value;
  hand[0].suit = from_deck[0].suit;
  hand[1].value = from_deck[1].value;
  hand[1].suit = from_deck[1].suit;
}
