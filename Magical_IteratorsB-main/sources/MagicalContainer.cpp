#include "MagicalContainer.hpp"
#include <math.h>
#include <iostream>

using namespace ariel;

/********            class MagicalContainer             *********/

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

MagicalContainer::~MagicalContainer() { }  // Destructor

MagicalContainer::MagicalContainer(const MagicalContainer& other)
    : _set(other._set.begin(), other._set.end())  // Construct new vector from other
{
    update();
}

void MagicalContainer::update() {
    _prime.clear();
    for (auto it = _set.begin(); it != _set.end(); ++it) {
        if (isPrime(*it)) {
            _prime.push_back(&(*it));  // Store the address of prime numbers in _prime vector
        }
    }

    Acsend.clear();
    for (auto it = _set.begin(); it != _set.end(); ++it) {
        Acsend.push_back(&(*it));  // Store the address of all elements in _set vector in Acsend vector
    }

    // Sort the vector based on the values pointed to by int* elements
    std::sort(Acsend.begin(), Acsend.end(), [](const int* a, const int* b) {
        return *a < *b;
    });
}

void MagicalContainer::addElement(int element) {
    _set.push_back(element);  // Add the element to the _set vector
    update();  // Update _prime and Acsend vectors
}

void MagicalContainer::removeElement(int numberToDelete) {
    auto it = std::find(_set.begin(), _set.end(), numberToDelete);
    if (it != _set.end()) {
        _set.erase(it);  // Remove the element from the _set vector
    } else {
        throw std::runtime_error("Number not found in the vector");
    }
    update();  // Update _prime and Acsend vectors
}

bool MagicalContainer::operator==(const MagicalContainer &other) const {
    return this == &other;  // Check if the current object is the same as the other object
}

bool MagicalContainer::operator!=(const MagicalContainer &other) const {
    return this != &other;  // Check if the current object is different from the other object
}
