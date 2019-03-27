#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
using namespace std;

class Player {
private:
	// name;
	string name;
	// num_of_cards;
	int num_cards;
	// container of cards
	vector <Card> playerCards;
	// more private members

public:

Player();//empty constructor
Player(string name, int numOfCards);//regular constractor
Player(const Player& pl);//copy constractor
~Player();//destructor
bool play(const Card& c);//the play function
string getName();
int getNumCards();
vector<Card> getPlayerCard();

};
#endif



