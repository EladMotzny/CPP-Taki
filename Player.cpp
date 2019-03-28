#include "Player.h"

Player::Player(){//empty constructor
    vector <Card> pc;
    this->name = "Jahlawit";
    this->num_cards = 0;
    this->playerCards = pc;
}

Player::Player(string name, int numOfCards){//regular constructor
    this->name = name;
    this->num_cards = numOfCards;
    for(int i = 0; i <= numOfCards; i++){
        this->playerCards.push_back(Card::generate_card());
    }
}

Player::Player(const Player& pl){// copy constructor
    this->name = pl.name;
    this->num_cards = pl.num_cards;
    this->playerCards = pl.playerCards;


}

Player::~Player(){};//destructor

bool Player::play(const Card& c){//The play function
    //check if card is in range and is legal
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
