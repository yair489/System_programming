
#include <iostream>
#include <numeric>
#include <string>
#include <stdexcept>
#include <stdexcept>
#include <algorithm>
#include "Fraction.hpp"
#include <limits>
using namespace std;

namespace ariel
{
    // /*https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/*/
    void Fraction::reduced(){
        int gcdd = __gcd(abs(_numerator),abs(_denominator));
        _numerator/=gcdd;
        _denominator/=gcdd;

        if(_denominator<0){
            _numerator*=  -1;
            _denominator*=-1;
        }

    }
    float Fraction::fractionToFloat() const{
      float num = (float)_numerator/_denominator;
      int temp=(int)(num * 1000);
      num=(float)temp /1000;
      return num;
    }

              /****************/
             /* Constructor  */
            /****************/
    Fraction::Fraction(int numerator, int denominator):_numerator(numerator),_denominator(denominator){
                if(denominator==0)throw  invalid_argument("denominator=0");

                reduced();
            }
    
    Fraction::Fraction(float num1){
         num1*=1000;
        _numerator=num1;
        _denominator=1000;
        reduced();
    }

          /****************/
         /*   operators  */
        /****************/

           /**************+ operator **************/
             Fraction operator+(const Fraction& number1, const Fraction& number2){
              if ((number2._numerator > 0) && (number1._numerator > std::numeric_limits<int>::max() - number2._numerator)) {
              // overflow occurred
                 throw std::overflow_error("Integer addition overflow");
              } else if ((number2._numerator < 0) && (number1._numerator < std::numeric_limits<int>::min() - number2._numerator)) {
                // underflow occurred
               throw std::overflow_error("Integer addition underflow");
                }
                int lcm= std::lcm(number1._denominator,number2._denominator );
                int lcm1=lcm/number1._denominator;
                int lcm2=lcm/number2._denominator;
                int numerator1=number1._numerator*lcm1 +number2._numerator*lcm2 ;
                int denominator1=lcm;

                return Fraction(numerator1 ,denominator1);
             }

           /**************- operator **************/

             Fraction operator-(const Fraction& number1, const Fraction& number2){
                  // check for overflow during subtraction
                if ((number2._numerator > 0) && (number1._numerator <std::numeric_limits<int>::min() + number2._numerator)) {
                   throw std::overflow_error("Integer subtraction overflow");
                } else if ((number2._numerator < 0) && (number1._numerator > std::numeric_limits<int>::max() + number2._numerator)) {
                    throw std::overflow_error("Integer subtraction underflow");
                }
                
                int lcm= std::lcm(number1._denominator,number2._denominator );
                int lcm1=lcm/number1._denominator;
                int lcm2=lcm/number2._denominator;
                int numerator1=number1._numerator*lcm1 -number2._numerator*lcm2 ;
                int denominator1=lcm;
                
                return Fraction(numerator1 ,denominator1);
             }

           /************** * operator **************/
             Fraction operator*(const Fraction& number1, const Fraction& number2){

                 int num1, num2;

            if (__builtin_mul_overflow(number1._numerator, number2._numerator, &num1) ||
                 __builtin_mul_overflow(number1._denominator, number2._denominator, &num2))
                {
                  throw overflow_error("biggg");
                }
                int numerator1=number1._numerator*number2._numerator ;
                int denominator1=number1._denominator*number2._denominator;
                return Fraction(numerator1 ,denominator1);
             }
           /************** / operator **************/
         

             Fraction operator/(const Fraction& number1, const Fraction& number2){
              if(number2._numerator==0)
                  throw std::runtime_error("eror");
              int num1, num2;

              if (__builtin_mul_overflow(number1._numerator, number2._denominator, &num1) ||
                          __builtin_mul_overflow(number1._denominator, number2._numerator, &num2)) {
                                throw overflow_error("biggg");
                            }
                
                int numerator1=number1._numerator*number2._denominator;
                int denominator1=number1._denominator*number2._numerator;
                return Fraction(numerator1 ,denominator1);
             }
           /************** == operator **************/
             bool operator==(const Fraction& number1, const Fraction& number2){
                if(number1._numerator==number2._numerator && number1._denominator==number2._denominator)
                    return true;
                return false;
             }
           /************** > operator **************/
             bool operator>(const Fraction& number1, const Fraction& number2){
                if(number1._numerator*number2._denominator>number2._numerator *number1._denominator)
                    return true;
                return false;
             }
           /************** >= operator **************/
             bool operator>=(const Fraction& number1, const Fraction& number2){
                if(number1==number2 || number1>number2)
                    return true;
                return false;
             }
           /************** < operator **************/
             bool operator<(const Fraction& number1, const Fraction& number2){
                if(! (number1>=number2) )
                    return true;
                return false;
             }
             
           /************** <= operator **************/
             bool operator<=(const Fraction& number1, const Fraction& number2){
                if(! (number1>number2) )
                    return true;
                return false;
             }
           /************** != operator **************/
             bool operator!=(const Fraction& number1, const Fraction& number2){
                if(! (number1==number2) )
                    return true;
                return false;
             }
           /************** << operator **************/
            ostream& operator<<(ostream& outsystem, const Fraction& fraction) {
                outsystem << fraction._numerator << "/" << fraction._denominator;
                return outsystem;
            }
           /**************  >>  operator **************/
   
            istream& operator>>(std::istream& isInput, Fraction& fraction)
            {
              int numerator  = 0;
              int denominator= 0;

              isInput >> numerator >> denominator;

        
               if (denominator == 0){
               throw std::runtime_error("Denominator =0");

               }else if (denominator < 0)
                {
                numerator   *= -1;
                denominator *= -1;
              }

            fraction._numerator   = numerator;
            fraction._denominator = denominator;
            fraction.reduced();

             return isInput;
           }





    
}


