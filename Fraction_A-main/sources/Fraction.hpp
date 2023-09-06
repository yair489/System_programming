#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

namespace ariel
{
    class Fraction{
        private:
            int numerator_h;//up
            int denominator_h;//down
            void reduced();
        public:
            /*constructors*/
            Fraction();
            Fraction(int numerator, int denominator);
            // Fraction(float number);
            /*copy constructor*/
            Fraction(float number);
            // Fraction(const Fraction& copyFra);
            //  ~Fraction()= default;

            /*function
            https://github.com/erelsgl-at-ariel/cpp-5783/blob/main/04-operator-overloading/1-arithmetic-operators/Complex.hpp*/
            // friend Fraction& operator=(const Fraction& number1);
            // Fraction& operator=(const Fraction& other);

            friend Fraction operator+(const Fraction& number1, const Fraction& number2);
            // friend Fraction operator+(const Fraction& number1);



            friend Fraction operator-(const Fraction& number1, const Fraction& number2);
            friend Fraction operator*(const Fraction& number1, const Fraction& number2);
            friend Fraction operator/(const Fraction& number1, const Fraction& number2);
            friend bool operator==(const Fraction& number1, const Fraction& number2);
            friend bool operator!=(const Fraction& number1, const Fraction& number2);
            friend bool operator>(const Fraction& number1, const Fraction& number2);
            friend bool operator<(const Fraction& number1, const Fraction& number2);
            friend bool operator>=(const Fraction& number1, const Fraction& number2);
            friend bool operator<=(const Fraction& number1, const Fraction& number2);

            friend std::ostream& operator<<(std::ostream& outsystem, const Fraction& fraction);
            friend std::istream& operator>>(std::istream& insystem, Fraction& fraction);


            Fraction& operator++(){
                numerator_h+=denominator_h;
                return *this;
                
            } 
            Fraction operator++(int dummy_flag_for_postfix_increment){
                Fraction copy = *this;
                numerator_h+=denominator_h;
                return copy;
            } 
            Fraction& operator--(){
                numerator_h-=denominator_h;
                return *this;
                
            } 
            Fraction operator--(int dummy_flag_for_postfix_increment){
                Fraction copy = *this;
                numerator_h-=denominator_h;
                return copy;
            } 

            
    };

    
}