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
	
public:
	deque <Player> playersDeque;
	int numberOfCards;
	Card currentCard;
	Player currentPlayer;
	bool clockWise = true;

	//public members and functions
	Game(){}
	Game(vector<string> nameArray, int numberOfCards, Card currentCard, Player currentPlayer);
	void start();
	void changeDirection();	//poland
	bool winner();
	
};
#endif




