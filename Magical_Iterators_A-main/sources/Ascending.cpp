
#include "MagicalContainer.hpp"
#include <math.h>
#include <iostream>

using namespace ariel;

int MagicalContainer::AscendingIterator::operator*() const
{
    return *it;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() // ++i
{
    if (it == pointerto->_set.end())
    {
        throw std::runtime_error(" ");
    }
    ++it;

    size_step++;
    return *this;
}

const MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int) // i++
{
    if (it == pointerto->_set.end())
    {
        throw std::runtime_error(" ");
    }
    AscendingIterator tmp = *this;
    ++it;
    size_step++;
    return tmp;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &rhs) const
{
    if (this->pointerto != rhs.pointerto)
    {
        throw std::runtime_error(" not the same magic.");
    }
    return it == rhs.it;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &rhs) const
{
    return !(it == rhs.it);
}
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this->pointerto != other.pointerto)
        throw std::runtime_error("Cant copy ");
    pointerto = other.pointerto;
    size_step = other.size_step;
    it = other.it;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &rhs) const
{
    if (this->pointerto != rhs.pointerto)
    {
        throw std::runtime_error(" not the same magic.");
    }
    return (size_step) > (rhs.size_step);

}
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &rhs) const
{
    if (this->pointerto != rhs.pointerto)
    {
        throw std::runtime_error(" not the same magic.");
    }
    return (size_step) < (rhs.size_step);
}
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin()
{

    it = pointerto->_set.begin();
    return *this;
}
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end()
{
    it = pointerto->_set.end();
    return *this;
}
