#pragma once
#include <iostream>
#include "player.hpp"
#include <vector>
#include "card.hpp"
#include <string>
using namespace std;

namespace ariel{
    class Game
    {
    private:
        Player& player1;
        Player& player2;
        string winnwer;
        string lastTurn;
        string log;
        unsigned  int numberOfTurn;
        int draws;

    public:

        // Constructors:
        Game(Player& playe1,Player& playe2);

        void playTurn();
        void printLastTurn(){cout<<lastTurn<<endl;}
        void playAll(); 
        void printWiner(); 
        void printLog(){cout<<log<<endl;}
        void printStats();
    };
}
