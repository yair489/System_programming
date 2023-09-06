#include "MagicalContainer.hpp"
#include <math.h>
#include <iostream>

using namespace ariel;

int MagicalContainer::AscendingIterator::operator*() const {
    return **it;  // Return the value pointed to by the iterator
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {  // Pre-increment (++i)
    if (it == _p_m->Acsend.end()) {
        throw std::runtime_error(" ");  // Throw an error if the iterator has reached the end
    }
    ++it;  // Move the iterator to the next element

    size_step++;  // Increment the size_step variable
    return *this;
}

const MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int) {  // Post-increment (i++)
    if (it == _p_m->Acsend.end()) {
        throw std::runtime_error(" ");  // Throw an error if the iterator has reached the end
    }
    AscendingIterator tmp = *this;  // Create a temporary iterator
    ++it;  // Move the iterator to the next element
    size_step++;  // Increment the size_step variable
    return tmp;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& rhs) const {
    if (this->_p_m != rhs._p_m) {
        throw std::runtime_error(" not the same magic.");  // Throw an error if the iterators belong to different MagicalContainers
    }
    return it == rhs.it;  // Compare if the iterators are pointing to the same element
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& rhs) const {
    return !(it == rhs.it);  // Compare if the iterators are not pointing to the same element
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if (this->_p_m != other._p_m)
        throw std::runtime_error("Cant copy ");  // Throw an error if the iterators belong to different MagicalContainers
    _p_m = other._p_m;
    size_step = other.size_step;
    it = other.it;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& rhs) const {
    if (this->_p_m != rhs._p_m) {
        throw std::runtime_error(" not the same magic.");  // Throw an error if the iterators belong to different MagicalContainers
    }
    return (size_step) > (rhs.size_step);  // Compare the size_step variables of the iterators
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& rhs) const {
    if (this->_p_m != rhs._p_m) {
        throw std::runtime_error(" not the same magic.");  // Throw an error if the iterators belong to different MagicalContainers
    }
    return (size_step) < (rhs.size_step);  // Compare the size_step variables of the iterators
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::begin() {
    it = _p_m->Acsend.begin();  // Set the iterator to the beginning of the Acsend vector
    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::end() {
    it = _p_m->Acsend.end();  // Set the iterator to the end of the Acsend vector
    return *this;
}
