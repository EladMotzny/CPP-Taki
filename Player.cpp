#include "Player.h"

Player::Player(){}

Player::Player(string name, int numOfCards){}//regular constractor

Player::Player(const Player& pl){}//copy constractor

Player::~Player(){};//destructor

bool Player::play(const Card& c){}//the play function

string Player::getName(){
    return this->name;
}

int Player::getNumCards(){
    return this->num_cards;
}

vector<Card> Player::getPlayerCard(){
    return this->playerCards;
}
