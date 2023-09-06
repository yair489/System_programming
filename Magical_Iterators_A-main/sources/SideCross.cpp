#include "MagicalContainer.hpp"
#include <math.h>
#include <iostream>

using namespace ariel;

int MagicalContainer::SideCrossIterator::operator*() const
{

    return *current;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() // ++i
{
    if (_end == pointerto->_set.end())
    {
        throw std::runtime_error(" ");
    }
    if (count % 2 == 1)
    {
        _end++;
        ++it_s;
        current = it_s;
        count++;
    }
    else
    {
        _end++;
        --it_e;
        current = it_e;
        count++;
    }
    size_step++;
    return *this;
}

const MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(int) // i++
{
    if (_end == pointerto->_set.end())
    {
        throw std::runtime_error(" ");
    }
    SideCrossIterator tmp = *this;
    if (count % 1 == 0)
    {
        _end++;
        ++it_s;
        current = it_s;
        count++;
    }
    else
    {
        _end++;
        --it_e;
        current = it_e;
        count++;
    }
    size_step++;
    return tmp;
}
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (this->pointerto != other.pointerto)
        throw std::runtime_error("Cant copy ");

    it_s = other.it_s;
    it_e = other.it_e;
    current = other.current;
    _end = other._end;
    pointerto = other.pointerto;
    size_step = other.size_step;
    return *this;
}
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &rhs) const
{
    if (this->pointerto != rhs.pointerto)
    {
        throw std::runtime_error(" not the same magic.");
    }
    return _end == rhs._end;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &rhs) const
{

    return !(_end == rhs._end);
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &rhs) const
{
    if (this->pointerto != rhs.pointerto)
    {
        throw std::runtime_error(" not the same magic.");
    }
    return size_step > (rhs.size_step);
}
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &rhs) const
{
    if (this->pointerto != rhs.pointerto)
    {
        throw std::runtime_error(" not the same magic.");
    }
    return (size_step) < (rhs.size_step);
}
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::begin()
{

    current = pointerto->_set.begin();
    _end = pointerto->_set.begin();
    return *this;
}
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::end()
{

    _end = pointerto->_set.end();
    return *this;
}
