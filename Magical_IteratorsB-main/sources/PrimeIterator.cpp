#include "MagicalContainer.hpp"
#include <math.h>
#include <iostream>

using namespace ariel;

int MagicalContainer::PrimeIterator::operator*() const {
    return **it;  // Dereference the iterator twice to access the prime value
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if (this->_p_m != other._p_m)
        throw std::runtime_error("Cannot copy iterator from a different MagicalContainer");
    _p_m = other._p_m;
    it = other.it;
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    if (it == _p_m->_prime.end())
        throw std::runtime_error("Iterator reached the end");
    ++it;  // Move the iterator to the next prime number
    return *this;
}

const MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++(int) {
    if (it == _p_m->_prime.end())
        throw std::runtime_error("Iterator reached the end");
    PrimeIterator tmp = *this;
    ++it;  // Move the iterator to the next prime number
    return tmp;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& rhs) const {
    if (this->_p_m != rhs._p_m)
        throw std::runtime_error("Iterators belong to different MagicalContainers");
    return it == rhs.it;  // Compare the iterators for equality
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& rhs) const {
    return !(it == rhs.it);  // Compare the iterators for inequality
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& rhs) const {
    if (this->_p_m != rhs._p_m)
        throw std::runtime_error("Iterators belong to different MagicalContainers");
    return it > rhs.it;  // Compare the iterators for greater than
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& rhs) const {
    if (this->_p_m != rhs._p_m)
        throw std::runtime_error("Iterators belong to different MagicalContainers");
    return it < rhs.it;  // Compare the iterators for less than
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::begin() {
    it = _p_m->_prime.begin();  // Set the iterator to the beginning of the _prime vector
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::end() {
    it = _p_m->_prime.end();  // Set the iterator to the end of the _prime vector
    return *this;
}
