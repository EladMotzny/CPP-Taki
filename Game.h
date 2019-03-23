#include <string>
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
class Game {
private:
	//private members and functions
	int numberOfPlayers;
	int numberOfCards;
	std::string playersNameArray[];
public:
	//public members and functions
	Game(){}
	void start();
};
#endif




