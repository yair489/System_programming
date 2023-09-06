#pragma once
#include <string>
using namespace std;

#include <iostream>

    enum Numberr
{
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

enum Type
{
    Clubs = 1,
    Hearts,
    Spades,
    Diamonds
    
};
namespace ariel{




    class card
    {
    private:
        Numberr num;
        Type type;
    public:
        

        // Constructors:
        card(Numberr num=King,Type type=Diamonds);

        //getter
        Type getType() const{
            return this->type;
        }
        Numberr getNumberr() const{
            
        return this->num;
        }
        //tostring
        string printcard() const;
       
    };
    
}
