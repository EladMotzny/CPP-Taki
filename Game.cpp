#include "Game.h"
#include <iostream> 
#include <deque> 

using namespace std;

void Game::start(){
    printf("erjgejrgnfng");
}

Game::Game(int numberOfPlayers, string nameArray[], int numberOfCards){
    for (int i=0; i<sizeof(nameArray); i++) {
        Player* p = new Player(nameArray[i], numberOfCards);
        this->playersDeque.push_back(*p);
    }
}