#include <string>
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <deque> 
using namespace std;
class Game {
private:
	//private members and functions
	deque <Player> playersDeque;
	int numberOfCards;
	Card currentCard;
	Player currentPlayer;
	bool clockWise = true;
public:
	//public members and functions
	Game(){}
	Game(int numberOfPlayers, vector<string> nameArray, int numberOfCards);
	void start();
};
#endif




