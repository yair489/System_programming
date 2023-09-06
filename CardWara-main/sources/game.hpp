#pragma once
#include <iostream>
#include "player.hpp"

#include <string>
using namespace std;

namespace ariel{
    class Game
    {
    private:
        Player player1;
        Player player2;
        string winnwer;
    public:
        string to_string();

        // Constructors:
        Game();
   
        Game(Player player11,Player player21);
        // {
        //     this->player1 = player11;
        //     this->player2 = player21;
        // }
        void playTurn();
        string printLastTurn();
        void playAll(); 
        void printWiner(); 
        string printLog(); 
        void printStats();
    };
}
