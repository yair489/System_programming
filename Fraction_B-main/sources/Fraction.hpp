#pragma once
#include <iostream>
#include <string>
#include <algorithm>


namespace ariel
{
    class Fraction{
        private:
            int _numerator;//up
            int _denominator;//down
            void reduced();
            float fractionToFloat() const;

        public:
              /****************/
             /* Constructor  */
            /****************/
            Fraction():_numerator(0),_denominator(1){}
            Fraction(int numerator, int denominator);
            Fraction(float num1);
           
             /****************/
            /*   get set  */
           /****************/
           int getNumerator() const{
            return _numerator;
           }
           int getDenominator() const{
            return _denominator;
           } 
            
             /****************/
            /*   operators  */
           /****************/


           /**************+ operator **************/
            friend Fraction operator+(const Fraction& number1, const Fraction& number2);
           /**************- operator **************/
            friend Fraction operator-(const Fraction& number1, const Fraction& number2);
           /************** * operator **************/
            friend Fraction operator*(const Fraction& number1, const Fraction& number2);
           /************** / operator **************/
             friend Fraction operator/(const Fraction& number1, const Fraction& number2);
           /************** == operator **************/
            friend bool operator==(const Fraction& number1, const Fraction& number2);
           /************** > operator **************/
            friend bool operator>(const Fraction& number1, const Fraction& number2);
           /************** >= operator **************/
            friend bool operator>=(const Fraction& number1, const Fraction& number2);
           /************** < operator **************/
            friend bool operator<(const Fraction& number1, const Fraction& number2);
           /************** <= operator **************/
            friend bool operator<=(const Fraction& number1, const Fraction& number2);
           /************** != operator **************/
            friend bool operator!=(const Fraction& number1, const Fraction& number2);
           /************** << operator **************/
            friend std::ostream& operator<<(std::ostream& outsystem, const Fraction& fraction);
           /**************  >>  operator **************/
            friend std::istream& operator>>(std::istream& insystem, Fraction& fraction);


            Fraction& operator++(){
                _numerator+=_denominator;
                return *this;
                
            } 
            Fraction operator++(int dummy_flag_for_postfix_increment){
                Fraction copy = *this;
                _numerator+=_denominator;
                return copy;
            } 
            Fraction& operator--(){
                _numerator-=_denominator;
                return *this;
                
            } 
            Fraction operator--(int dummy_flag_for_postfix_increment){
                Fraction copy = *this;
                _numerator-=_denominator;
                return copy;
            } 


    };

    
}