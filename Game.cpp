#include "Game.h"
#include <iostream> 
#include <deque> 
#include <vector>
#include <string>

using namespace std;


Game::Game(int numberOfPlayers, vector<string> nameArray, int numberOfCards, Card currentCard, Player currentPlayer){
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
	Card currentCard;
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
    Game(numberOfPlayers, nameArray, numberOfCards, currentCard, currentPlayer);
	// bool clockWise = true
}

void gamePrintForPlayer(){

}