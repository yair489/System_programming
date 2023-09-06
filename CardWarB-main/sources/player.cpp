#include "player.hpp"
using namespace std;

namespace ariel{
    Player::Player(string name)
    {
        cout << "Player(" << name <<")"<< endl; 
        this->name = name;
        this->CardesTaken=0;
        this->isPlaying=false;
    }

    // int stacksize() const {
    //     if((int)this->playerStack.size()<0){
    //         return 0;
    //     }
    //     return (int)this->playerStack.size();
        
    //     } 
    void Player::addCard(card& card1) { 
 
        this->playerStack.push_back(card1); 
    }


}//namescap


