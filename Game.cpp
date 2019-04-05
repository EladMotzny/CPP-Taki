#include "Game.h"
#include "Card.h"
#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <exception>

using namespace std;

class gameExeption: public exception{
    virtual const char* what() const throw(){
        return "You entered negative number! Game Over...";
    }
} gameEx;

Game::Game(const vector<string> nameArray,const int numberOfCards,const Card currentCard, Player* currentPlayer)
{
    for (int i = 0; i < nameArray.size(); i++)
    {
        Player* p = new Player(nameArray[i], numberOfCards);
        this->playersDeque.push_back(p);
        cout << "size: " << this->playersDeque.size() << endl;
    }
    this->currentCard = currentCard;
    this->currentPlayer = currentPlayer;
}

void Game::start()
{
    deque<Player> playersDeque;
    int numberOfPlayers;

    cout << "How many players?" << endl;
    cin >> numberOfPlayers;

    if(numberOfPlayers < 0)
        throw  gameEx;

    cout << "How many cards?" << endl;
    cin >> this->numberOfCards;

    if(numberOfCards < 0)
        throw  gameEx;

    if(numberOfCards == 0 || numberOfPlayers == 0){
        return;
    }

    for (int i = 0; i < numberOfPlayers; i++)
    {
        string currentName;
        cout << "Player number " << (i+1) << " name?" << endl;
        cin >> currentName;
        Player *p = new Player(currentName, numberOfCards);
        this->playersDeque.push_back(p);
    }
    this->currentCard = Card::generate_card();
    this->currentPlayer = this->playersDeque.front();

    bool winner = false;

    while (true)
    {
        int cardIndex;
        gamePrintForPlayer();

        //need to check validity of user pick
        if (this->currentPlayer->play(this->currentCard))
        {
            if (this->winner())
            {
                cout << this->currentPlayer->getName() << "  wins!" << endl;
                return;
            }

            if (this->currentCard.get_sign() == sign::PLUS)
            {
                //Player gets the WHOLE "his turn again" shanbang in recursion
                this->plusCardMove();
            }

            if(this->currentCard.get_sign() == sign::STOP){
                //move to the player after the next NEED TO TEST
                this->currentPlayer = this->playersDeque.front();
                this->playersDeque.pop_front();
                this->playersDeque.push_back(this->currentPlayer);
            }

            if(this->currentCard.get_sign() == sign::CD){}
            //idea: make a flag: true-> regular false-> backwards. if flag is false, do the opposite of what we're doing now untill CD is played again
            //inside the function above simply change the flag and make an if,else statements below
        }
        
        this->playersDeque.pop_front();
        this->playersDeque.push_back(this->currentPlayer);
        this->currentPlayer = this->playersDeque.front();
    }
}

void Game::gamePrintForPlayer()
{
    cout << "Current: " << this->currentCard << endl;
    cout << this->currentPlayer->getName() << ", your turn -" << endl;
    cout << "Your cards: ";
    for (int i = 0; i < this->currentPlayer->getPlayerCard().size(); i++)
    {
        cout << "(" << (i+1) << ")" << this->currentPlayer->getPlayerCard()[i] << "  ";
    }
    cout << " " << endl;
}

bool Game::winner()
{
    // cout << "started winner" << endl;
    deque<Player*>::iterator it = this->playersDeque.begin();
    // it->toString();
    for (; it != this->playersDeque.end(); it++)
    {
        
        // cout  << "winnerloop " << endl; //it->getName();
        if ((*it)->getPlayerCard().size() == 0)
            return true;
    }
    return false;
}

void Game::plusCardMove()
{
    gamePrintForPlayer();
    if (this->currentPlayer->play(this->currentCard))
    {
        if (this->winner())
        {
            cout << this->currentPlayer->getName() << "  wins!" << endl;
            return;
        }

        if (this->currentCard.get_sign() == sign::PLUS)
        {
            this->plusCardMove();
        }

        if (this->currentCard.get_sign() == sign::STOP)
        {
        }

        if (this->currentCard.get_sign() == sign::CD)
        {
        }
    }
}

Game::~Game(){
    int size = this->playersDeque.size();
    for(int i=0; i<size;  i++){
        Player* p = this->playersDeque.front();
        this->playersDeque.pop_front();
        delete p;
    }
    this->currentPlayer = NULL;
}