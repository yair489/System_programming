#include "game.hpp"
#include "player.hpp"

using namespace std;

#include <string>
using namespace std;

namespace ariel{
//     Game::Game(){
//        this->player1 = 0;
//        this->player2 = 0;
//    }

    Game::Game(Player player11,Player player21)
        {
            this->player1 = player11;
            this->player2 = player21;
        }
    void Game::playAll(){}
    void Game::playTurn(){}
    string Game::printLastTurn(){return "";}
    string Game::printLog(){return "";}
    void Game::printStats(){}
    void Game::printWiner(){}

}
