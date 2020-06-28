#include <iostream>
#include "deck.h"
#include "player.h"
#include "game.h"

game::game()
{
  pot_value = 0;
}

void game::show_game_info()
{
  std::cout << "Chips in pot: " << pot_value << std::endl;

}

void game::deal()
{
  d.shuffle_deck();
  x.get_hand(d.get_card(), d.get_card());
  pot_value += x.bet();
}
