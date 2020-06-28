#pragma once
#include <iostream>
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

game::game()
{
  pot_value = 0;
}

void game::show_game_info()
{
  std::cout << "Chips in pot: " << pot_value << std::endl;
  for (int i = 0; i < 5; i++)
  {
    std::cout << shared_cards[i].suit << shared_cards[i].value << std::endl;
  }
}

void game::deal()
{
  d.shuffle_deck();
  x.get_hand(d.get_card(), d.get_card());
  x.show_info();
  pot_value += x.bet(pot_value);
}

void game::deal_flop()
{
  for (int i = 0; i < 3; i++)
  {
    shared_cards[i] = d.get_card();
  }
  show_game_info();
  pot_value += x.bet(pot_value);
}

void game::deal_turn()
{
  shared_cards[3] = d.get_card();
  pot_value += x.bet(pot_value);
  show_game_info();
}

void game::deal_river()
{
  shared_cards[4] = d.get_card();
  pot_value += x.bet(pot_value);
  show_game_info();
}
