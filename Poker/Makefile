all: poker
poker: main.cpp deck.h player.h game.h
	g++ -Wall -Werror -std=c++11 -o poker main.cpp player.cpp deck.cpp game.cpp
clean:
	rm -f poker