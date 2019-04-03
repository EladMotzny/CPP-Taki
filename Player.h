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
Player& operator=(const Player& p){name = p.name; num_cards = p.num_cards; playerCards = p.playerCards; return *this;};
bool play(Card& c);//the play function, true if put a card and false if took a card from deck
string getName();
int getNumCards();
vector<Card> getPlayerCard();
void toString(){
	cout << "name: " << this->name << endl;
}

};
#endif



