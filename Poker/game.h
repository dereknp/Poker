#pragma once
#include "deck.h"
#include "player.h"

class game
{
private:
  int pot_value;
  card shared_cards[5];
  player x;
  deck d;
public:
  game();
  void show_game_info();
  void deal();
  void deal_flop();
  void deal_turn();
  void deal_river();
  void winner();
};
