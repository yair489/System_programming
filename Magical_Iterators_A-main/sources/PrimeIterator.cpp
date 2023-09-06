#include "MagicalContainer.hpp"
#include <math.h>
#include <iostream>

using namespace ariel;

int MagicalContainer::PrimeIterator::operator*() const
{
    return **it;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (this->pointerto != other.pointerto)
        throw std::runtime_error("Cant copy ");
    pointerto = other.pointerto;
    it = other.it;
    return *this;
}
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() // ++i
{
    if (it == pointerto->_prime.end())
    {
        throw std::runtime_error(" ");
    }
    ++it;
    return *this;
}

const MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++(int) // i++
{
    if (it == pointerto->_prime.end())
    {
        throw std::runtime_error(" ");
    }
    PrimeIterator tmp = *this;
    ++it;
    return tmp;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &rhs) const
{
    if (this->pointerto != rhs.pointerto)
    {
        throw std::runtime_error(" not the same magic.");
    }
    return it == rhs.it;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &rhs) const
{
    return !(it == rhs.it);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &rhs) const
{
    if (this->pointerto != rhs.pointerto)
    {
        throw std::runtime_error(" not the same magic.");
    }
    return it > (rhs.it);
}
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &rhs) const
{
    if (this->pointerto != rhs.pointerto)
    {
        throw std::runtime_error(" not the same magic.");
    }
    return it < (rhs.it);
}
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::begin()
{

    it = pointerto->_prime.begin();
    return *this;
}
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::end()
{
    it = pointerto->_prime.end();
    return *this;
}
