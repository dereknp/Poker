#pragma once
#include <iostream>
#include "deck.h"
#include "player.h"

class game
{
private:
  int pot_value;
  card shared_cards[5];
  player p1;
  player p2;
  deck d;
public:
  game();
  void show_game_info();
  void calc_bets();
  void deal_players();
  void deal_flop();
  void deal_turn();
  void deal_river();
  void winner();
};

game::game()
{
  pot_value = 0;
  for (int i = 0; i < 5; i++)
  {
    shared_cards[i].value = 0;
    shared_cards[i].suit = "";
  }
  string n1, n2;
  std::cout << "Enter name of player 1" << std::endl;
  std::cin >> n1;
  std::cout << "Enter name of player 2" << std::endl;
  std::cin >> n2;

  p1.set_name(n1);
  p2.set_name(n2);
}

void game::show_game_info()
{
  std::cout << "Chips in pot: " << pot_value << std::endl;
  for (int i = 0; i < 5; i++)
  {
    std::cout << shared_cards[i].suit;
    std::cout<< shared_cards[i].value << std::endl;
  }
}

void game::calc_bets()
{
  
}

void game::deal_players()
{
  d.shuffle_deck();
  p1.get_hand(d.get_card(2));
  p2.get_hand(d.get_card(2));
  p1.show_info();
  p2.show_info();
  calc_bets();
  p1.show_info();
  p2.show_info();
  show_game_info();
}

void game::deal_flop()
{
  vector <card> flop = d.get_card(3);
  for (int i = 0; i < 3; i++)
  {
    shared_cards[i] = flop[i];
  }
  show_game_info();
  pot_value += p1.bet(pot_value);
}

void game::deal_turn()
{
  vector <card> turn = d.get_card(1);
  shared_cards[3] = turn[0];
  pot_value += p1.bet(pot_value);
  show_game_info();
}

void game::deal_river()
{
  vector <card> river = d.get_card(1);
  shared_cards[4] = river[0];
  pot_value += p1.bet(pot_value);
  show_game_info();
}

void game::winner()
{

}
