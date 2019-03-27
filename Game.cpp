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
    }
    this->currentCard = currentCard;
    this->currentPlayer =  currentPlayer;
}

void Game::start(){
    deque <Player> playersDeque;
	int numberOfCards;
    int numberOfPlayers;
    vector<string> nameArray;
    Card currentCard = Card::generate_card();
	Player currentPlayer;

    cout << "How many players?" << endl;
    cin >> numberOfPlayers;

    cout << "How many cards?" << endl;
    cin >> numberOfCards;

    for(int i=1; i<=numberOfPlayers; i++){
        string currentName;
        cout << "Player number " << i << " name?"<< endl;
        cin >> currentName;
        nameArray.push_back(currentName);
    }
    Game game = Game(nameArray, numberOfCards, currentCard, currentPlayer);
    bool winner = false;
    this->winner();
    // while(!winner){

    // }
    
	
}

void gamePrintForPlayer(Game game){
    cout << "Current: " << game.currentCard << endl;
    cout << game.currentPlayer.getName() << ", your turn -" << endl;
    cout << "Your cards: ";
    for(int i=1; i<game.currentPlayer.getPlayerCard().size(); i++){
        cout << "(" << i << ")" << game.currentPlayer.getPlayerCard()[i] << "  ";
    }
}

bool Game::winner(){
    // deque<Player> :: iterator it;
    // for (it = this->playersDeque.begin(); it != this->playersDeque.end(); it++){
    //     cout  << it->getName();
        // if(*it->getPlayerCard.size() == 0)
    //         return true;
    // }
    // return false;

    // for(auto const& i: this->playersDeque){
    //     if(i.getPlayerCard.size() == 0)
    //         return true;
    // }
    // return false;
    // for(int i=0; i<this->playersDeque.size(); i++){
    //     if(this->playersDeque[i].getPlayerCard.size()== 0)
    //     return  true;
    // }
    return false;
    }
