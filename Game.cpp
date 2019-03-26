#include "Game.h"
#include <iostream> 
#include <deque> 
#include <vector>
#include <string>

using namespace std;

void Game::start(){
    printf("erjgejrgnfng");
}

Game::Game(int numberOfPlayers, vector<string> nameArray, int numberOfCards){
    for (int i=0; i<nameArray.size(); i++) {
        Player* p = new Player(nameArray[i], numberOfCards);
        this->playersDeque.push_back(*p);
    }
}