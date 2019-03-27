#include "Game.h"
#include "Card.h"
#include <iostream> 
#include <deque> 
#include <vector>
#include <string>

using namespace std;


Game::Game(vector<string> nameArray, int numberOfCards, Card currentCard, Player currentPlayer){
    for (int i=0; i<nameArray.size(); i++) {
        Player* p = new Player(nameArray[i], numberOfCards);
        this->playersDeque.push_back(*p);
        cout << "size: " << this->playersDeque.size() << endl;
    }
    this->currentCard = currentCard;
    this->currentPlayer =  currentPlayer;
}

void Game::start(){
    deque <Player> playersDeque;
    int numberOfPlayers;
    
    cout << "How many players?" << endl;
    cin >> numberOfPlayers;

    cout << "How many cards?" << endl;
    cin >> this->numberOfCards;

    for(int i=1; i<=numberOfPlayers; i++){
        string currentName;
        cout << "Player number " << i << " name?"<< endl;
        cin >> currentName;
        Player* p = new Player(currentName, numberOfCards);
        this->playersDeque.push_back(*p);
        cout << "size: " << this->playersDeque.size() << endl;
    }
    this->currentCard = Card::generate_card();
    this->currentPlayer =  this->playersDeque.front();
    this->playersDeque.pop_front();
    this->playersDeque.push_back(this->currentPlayer);

    bool winner = false;
    cout << this->clockWise << " :" << this->currentPlayer.getName() << " " << this->playersDeque.size();
    this->winner();

    while(!winner){
        int cardIndex;
        gamePrintForPlayer();
        cin >> cardIndex;
        //need to check validity of user pick


        winner = this->winner();
    }
    
	
}

void Game::gamePrintForPlayer(){
    cout << "Current: " << this->currentCard << endl;
    cout << this->currentPlayer.getName() << ", your turn -" << endl;
    cout << "Your cards: ";
    for(int i=1; i<this->currentPlayer.getPlayerCard().size(); i++){
        cout << "(" << i << ")" << this->currentPlayer.getPlayerCard()[i] << "  ";
    }
}

bool Game::winner(){
    cout << "started winner" << endl;
    deque<Player> :: iterator it = this->playersDeque.begin();
    it->toString();
    for (; it != this->playersDeque.end(); it++){
        cout  << it->getName();
        if(it->getPlayerCard().size() == 0)
            return true;
    }
    return false;
    }
