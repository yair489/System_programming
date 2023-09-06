
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "Fraction.hpp"
using namespace std;

namespace ariel
{
    /*https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/*/
    void Fraction::reduced(){
        int gcdd = __gcd(abs(numerator_h),abs(denominator_h));
        numerator_h/=gcdd;
        denominator_h/=gcdd;

        if(denominator_h<0){
            numerator_h*=  -1;
            denominator_h*=-1;
        }

    }
    Fraction::Fraction(): numerator_h(0), denominator_h(1){}

    Fraction::Fraction (int numerator, int denominator): numerator_h(numerator), denominator_h(denominator){
        if(denominator==0){
            throw invalid_argument("denominator=0");
        }
        this->reduced();
    }
    Fraction::Fraction(float number) {
        // cout<< "shcar" <<endl;
        int point = 1;
        while (point < 1000)
        {
            number =number *10;
            point  =point  *10;
        }

        numerator_h = number;
        denominator_h = point;

        reduced();
    }
   
    Fraction operator+(const Fraction& number1, const Fraction& number2){
        int numerator= number1.numerator_h*number2.denominator_h+number2.numerator_h*number1.denominator_h;
        int denominator=number2.denominator_h*number1.denominator_h;
        Fraction tempfr = Fraction(numerator,denominator);
        tempfr.reduced();
        return tempfr;
    }
    // friend Fraction operator+(const Fraction& number1);



    Fraction operator-(const Fraction& number1, const Fraction& number2){
        int numerator= number1.numerator_h*number2.denominator_h-number2.numerator_h*number1.denominator_h;
        int denominator=number2.denominator_h*number1.denominator_h;
        Fraction tempfr = Fraction(numerator,denominator);
        tempfr.reduced();
        return tempfr;
    }
    Fraction operator*(const Fraction& number1, const Fraction& number2){
        int numerator= number1.numerator_h*number2.numerator_h;
        int denominator=number2.denominator_h*number1.denominator_h;
        Fraction tempfr = Fraction(numerator,denominator);
        tempfr.reduced();
        return tempfr;
    }
    Fraction operator/(const Fraction& number1, const Fraction& number2){
        int numerator= number1.numerator_h*number2.denominator_h;
        int denominator=number1.denominator_h*number2.numerator_h;
        Fraction tempfr = Fraction(numerator,denominator);
        tempfr.reduced();
        return tempfr;
    }
    bool operator==(const Fraction& number1, const Fraction& number2){
        // Fraction number1=num3;
        // Fraction number2=num4;
        // number1.reduced();
        // number2.reduced();
        if(number1.numerator_h*number2.denominator_h==number2.numerator_h*number1.denominator_h)return true;
    
    return false;
    }
     bool operator!=(const Fraction& number1, const Fraction& number2){
        
        if(number1==number2)return false;
    
    return true;
    }
     bool operator>(const Fraction& number1, const Fraction& number2){
        int n1= number1.numerator_h*number2.denominator_h;
        int n2=number2.numerator_h*number1.denominator_h;
        if(n1>n2)return true;

        return false;
    }
     bool operator<(const Fraction& number1, const Fraction& number2){
        int n1= number1.numerator_h*number2.denominator_h;
        int n2=number2.numerator_h*number1.denominator_h;
        if(n1<n2)return true;

        return false;
    }
     bool operator>=(const Fraction& number1, const Fraction& number2){
        int n1= number1.numerator_h*number2.denominator_h;
        int n2=number2.numerator_h*number1.denominator_h;
        if(n1>=n2)return true;

        return false;
    }
     bool operator<=(const Fraction& number1, const Fraction& number2){
        int n1= number1.numerator_h*number2.denominator_h;
        int n2=number2.numerator_h*number1.denominator_h;
        if(n1<=n2)return true;

        return false;
    }

    //----------------------------------
    // friend global IO operators
    //----------------------------------
    ostream& operator<<(ostream& outsystem, const Fraction& fraction) {
        outsystem << fraction.numerator_h << "/" << fraction.denominator_h;
        return outsystem;
    }

    istream& operator>>(istream& insystem, Fraction& fraction) {
      

        return insystem;
    }
  
}