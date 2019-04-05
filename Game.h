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
	deque <Player*> playersDeque;
	int numberOfCards;
	Card currentCard;
	Player* currentPlayer;
	bool clockWise = true;

	Game& operator=(const Game& game){
		this->numberOfCards = game.numberOfCards;
		this->currentCard = game.currentCard;
		this->currentPlayer = game.currentPlayer;
		this->clockWise = game.clockWise;
		this->playersDeque = game.playersDeque;
		return *this;
	}

	Game(const Game& g){
		this->numberOfCards = g.numberOfCards;
		this->currentCard = g.currentCard;
		this->currentPlayer = g.currentPlayer;
		this->clockWise = g.clockWise;
		this->playersDeque = g.playersDeque;
	}

public:
	//public members and functions
	Game(){
		deque <Player*> pd;
		this->playersDeque = pd;
		this->numberOfCards = 0;
		this->currentCard = Card::generate_card();
		this->currentPlayer = NULL;
	}
	Game(const vector<string> nameArray,const int numberOfCards,const Card currentCard, Player* currentPlayer);
	void start();
	bool winner();
	void gamePrintForPlayer();
	void plusCardMove();
	
	
};
#endif




