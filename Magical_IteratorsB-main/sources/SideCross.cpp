#include "MagicalContainer.hpp"
#include <math.h>
#include <iostream>

using namespace ariel;

int MagicalContainer::SideCrossIterator::operator*() const {
    return *current;  // Return the value pointed to by the iterator
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {  // Pre-increment (++i)
    if (_end == _p_m->_set.end()) {
        throw std::runtime_error(" ");  // Throw an error if the iterator has reached the end
    }
    if (count % 2 == 1) {  // Alternate between moving the iterators it_s and it_e
        _end++;
        ++it_s;
        current = it_s;
        count++;
    } else {
        _end++;
        --it_e;
        current = it_e;
        count++;
    }
    size_step++;  // Increment the size_step variable
    return *this;
}

const MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(int) {  // Post-increment (i++)
    if (_end == _p_m->_set.end()) {
        throw std::runtime_error(" ");  // Throw an error if the iterator has reached the end
    }
    SideCrossIterator tmp = *this;
    if (count % 1 == 0) {  // Alternate between moving the iterators it_s and it_e
        _end++;
        ++it_s;
        current = it_s;
        count++;
    } else {
        _end++;
        --it_e;
        current = it_e;
        count++;
    }
    size_step++;  // Increment the size_step variable
    return tmp;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (this->_p_m != other._p_m)
        throw std::runtime_error("Cant copy ");

    it_s = other.it_s;
    it_e = other.it_e;
    current = other.current;
    _end = other._end;
    _p_m = other._p_m;
    size_step = other.size_step;
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& rhs) const {
    if (this->_p_m != rhs._p_m) {
        throw std::runtime_error(" not the same magic.");  // Throw an error if the iterators belong to different MagicalContainers
    }
    return _end == rhs._end;  // Compare if the iterators are pointing to the same element
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& rhs) const {
    return !(_end == rhs._end);  // Compare if the iterators are not pointing to the same element
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& rhs) const {
    if (this->_p_m != rhs._p_m) {
        throw std::runtime_error(" not the same magic.");  // Throw an error if the iterators belong to different MagicalContainers
    }
    return size_step > (rhs.size_step);  // Compare the size_step variables of the iterators
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& rhs) const {
    if (this->_p_m != rhs._p_m) {
        throw std::runtime_error(" not the same magic.");  // Throw an error if the iterators belong to different MagicalContainers
    }
    return (size_step) < (rhs.size_step);  // Compare the size
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::begin() {
    current = _p_m->_set.begin();  // Set the current iterator to the beginning of the _set vector
    _end = _p_m->_set.begin();  // Set the _end iterator to the beginning of the _set vector
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::end() {
    _end = _p_m->_set.end();  // Set the _end iterator to the end of the _set vector
    return *this;
}
