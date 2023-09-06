#include "player.hpp"
using namespace std;

namespace ariel{
//  Player::Player(string name){
//     this->name = name;
//    }
    Player::Player()
    {
        this->name = "";
    }
    Player::Player(string name)
    {
         this->name = name;
    }
int Player::stacksize(){ 
return 26;
}
int Player::cardesTaken(){ 
return 0;
}

}//namescap