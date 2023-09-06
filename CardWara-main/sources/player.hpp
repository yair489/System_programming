#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{


class Player
{
private:
    string name;
    // int year;
    // string id;
public:
    Player();
    // {
    //     this->name = "";
    // }
    Player(string name);
    // {
    //      this->name = name;
    // }
    int stacksize(); 
    int cardesTaken();
};

}//namescap