#include <string>
using namespace std;
#include <iostream>
#include "card.hpp"

namespace ariel{

    card::card(Numberr num1, Type type1){
        this->num=num1;
        this->type=type1;
    }
    string card::printcard() const{
        Numberr num=this->num;
        

        string findNum;
        if(num== Ace){
            findNum = "Ace";
        }
        if(num>1 && num<11){
            findNum = to_string((int)num);
        }
        if(num== Jack){
            findNum = "Jack";
        }
        if(num== Queen){
            findNum = "Queen";
        }
        if(num== King){
            findNum = "King";
        }
        //findnum

        //type
        Type type=this->type;
        string findType;
        if(type== Clubs){
            findType = "Clubs";
        }
        if(type== Hearts){
            findType = "Hearts";
        }
        if(type== Spades){
            findType = "Spades";
        }
        if(type == Diamonds){
            findType = "Diamonds";
        } 
    
        string findCard=findNum+" of "+findType;
        return findCard;
    
            
    }
}
