#include "Player.h"

Player::Player(){//empty constructor
    this->name = "Jahlawit";
    this->num_cards = 0;
}

Player::Player(string name, int numOfCards){//regular constructor
    this->name = name;
    this->num_cards = numOfCards;

}

Player::Player(const Player& pl){// copy constructor
    this->name = pl.name;
    this->num_cards = pl.num_cards;
    this->playerCards = pl.playerCards;


}

Player::~Player(){};//destructor

bool Player::play(const Card& c){//The play function
    return true;
}//NEED TO CHANGE

string Player::getName(){
    return this->name;
}

int Player::getNumCards(){
    return this->num_cards;
}

vector<Card> Player::getPlayerCard(){
    return this->playerCards;
}
