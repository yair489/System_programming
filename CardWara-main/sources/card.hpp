#pragma once
#include <string>
using namespace std;

namespace ariel{
    class card
    {
    private:
        int num;
        string type;
    public:
        

        // Constructors:
        card();

        // card(int number,string type){
        //     this->num = number;
        //     this->type = type;
        // } 
       
        void printcard();
    };
    
}
