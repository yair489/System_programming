#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include "card.hpp"

//https://www.geeksforgeeks.org/vector-in-cpp-stl/
namespace ariel
{


class Player
{
private:
    string name;
    int CardesTaken;
    bool isPlaying;
    vector<card> playerStack;
public:
    // Player();
    Player(string name="yair");
    string getName() const { return this->name;   }
    // int stacksize()  ;
    int stacksize() const {
        // if((int)this->playerStack.size()<0){
        //     return 0;
        // }
        return (int)this->playerStack.size();
        
        }
    int cardesTaken()const{return this->CardesTaken;} 
    void addCardesTaken(){this->CardesTaken++;    }
    bool isinPlaying() const { return this->isPlaying; }
    void setisPlaying(bool ingame) {  this->isPlaying = ingame; }
    const card& getCard() const { return this->playerStack.back(); }
    void removefromPlayerCard() {  this->playerStack.pop_back();}
    void addCard(card& card1); 
     string toString() const {
            return  this->name + " have " + to_string(this->stacksize()) + " stacksize and " + to_string(this->cardesTaken()) + "CardesTaken";
            }

};

}//namescap