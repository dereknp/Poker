#pragma once
#include "deck.h"

class player
{
private:
  card hand[2];
  int money;

public:
  player();
  void show_info();
  int bet();
  void get_hand(card one, card two);
};
