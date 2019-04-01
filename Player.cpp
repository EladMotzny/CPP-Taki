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

bool Player::play(Card& c){//The play function
    int cardToPlay;
    bool endFlag=false;//if the play was legal
    bool playOrDraw = false;//false if the player drew a card and true if he played a card
    while(!endFlag){
        cin >> cardToPlay;
        //check if card is in range
        if(0 == cardToPlay || cardToPlay > this->getPlayerCard().size()){
            this->playerCards.push_back(Card::generate_card());//draw a card
            endFlag = true;
            playOrDraw = false;
        }
        else{//card is not in range, draw a card
            //check if move is legal
            if(c.is_legal(this->playerCards.at(cardToPlay))){//move is legal
                playOrDraw = true;
                c = this->playerCards.at(cardToPlay);
                this->playerCards.erase(this->playerCards.begin() + cardToPlay);//might want to +1 or -1, need to confirm
                this->getPlayerCard().erase(this->getPlayerCard().begin() + cardToPlay);
                endFlag = true;
            }
            else{//move is illegal
                cout << "You cant put " << this->playerCards.at(cardToPlay) << " on " << c << endl;
            }
        }
    }
    return playOrDraw;
}

string Player::getName(){
    return this->name;
}

int Player::getNumCards(){
    return this->num_cards;
}

vector<Card> Player::getPlayerCard(){
    return this->playerCards;
}
