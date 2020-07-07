#include <iostream>
#include "deck.h"
#include "player.h"
using namespace std;

int main()
{
  deck play;
  player x;
  x.get_hand(play.get_card(2));
  x.show_info();
}
