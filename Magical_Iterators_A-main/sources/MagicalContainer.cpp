#include "MagicalContainer.hpp"
#include <math.h>
#include <iostream>

using namespace ariel;


/********            class MagicalContainer             *********/
// MagicalContainer::MagicalContainer():elements(){}

bool MagicalContainer::isPrime(int number) {
    if (number < 2) {
        return false;
    }

    int sqrtNumber = std::sqrt(number);
    for (int i = 2; i <= sqrtNumber; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}
MagicalContainer::~MagicalContainer(){  }

MagicalContainer::MagicalContainer(const MagicalContainer& other) 
    : 

    _set(other._set.begin(), other._set.end())
    {
        update();
    } // Construct new vector from other

void MagicalContainer::update(){
    std::sort(_set.begin(), _set.end());
    _prime.clear();
    for (auto it = _set.begin(); it != _set.end(); ++it) {
        if(isPrime(*it)){
            _prime.push_back(&(*it));
        }
    }
}
void MagicalContainer::addElement(int element){

    _set.push_back(element);
    update();
}
void MagicalContainer::removeElement(int numberToDelete){
    auto it = std::find(_set.begin(), _set.end(), numberToDelete);
    if (it != _set.end()) {
        _set.erase(it);
    } else {
        throw std::runtime_error("Number not found in the vector");
    }
    update();
}

bool MagicalContainer::operator==(const MagicalContainer &other) const{
    return this==&other;
}
bool MagicalContainer::operator!=(const MagicalContainer &other) const{
    return this!=&other;
}