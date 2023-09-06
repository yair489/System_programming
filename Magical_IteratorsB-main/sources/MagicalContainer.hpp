#pragma once

#include <vector>
#include <iterator>
#include <set>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>

namespace ariel
{
    class MagicalContainer
    {
        std::vector<int> _set;              // Private member variable to store elements
        std::vector<int *> _prime;          // Private member variable to store pointers to prime numbers
        std::vector<int *> Acsend;          // Private member variable to store pointers to elements in ascending order


        bool isPrime(int number);           // Private helper function to check if a number is prime
        void update();                      // Private helper function to update the container



    public:

         MagicalContainer() {}               // Default constructor
        ~MagicalContainer();                // Destructor
        MagicalContainer(const MagicalContainer &other);   // Copy constructor

        MagicalContainer &operator=(const MagicalContainer &other) noexcept = default;   // Copy assignment operator
        MagicalContainer(MagicalContainer &&other) = default;                           // Move constructor
        MagicalContainer &operator=(MagicalContainer &&other) = default;                // Move assignment operator

        void addElement(int element);       // Add an element to the container
        void insertElement(int element);    // Insert an element to the container
        void removeElement(int element);    // Remove an element from the container
        size_t size() const {               // Return the size of the container
            return _set.size();
        }

        bool operator==(const MagicalContainer &other) const;   // Equality comparison operator
        bool operator!=(const MagicalContainer &other) const;   // Inequality comparison operator


        class AscendingIterator
        {

        private:
            std::vector<int *>::iterator it;        // Iterator for traversing the container
            MagicalContainer *_p_m;                  // Pointer to the MagicalContainer object
            int size_step = 0;                       // Size step counter


        public:

            AscendingIterator(MagicalContainer &pointer1)   // Constructor
            : it(pointer1.Acsend.begin()), _p_m(&pointer1), size_step(0)
            {
            }
            int operator*() const;                          // Dereference operator
            AscendingIterator &operator++();                 // Pre-increment operator (++i)
            const AscendingIterator operator++(int);         // Post-increment operator (i++)


            bool operator==(const AscendingIterator &rhs) const;
            bool operator!=(const AscendingIterator &rhs) const;
            AscendingIterator &operator=(const AscendingIterator &other);

            AscendingIterator(const AscendingIterator &other) = default;
            AscendingIterator(AscendingIterator &&other) noexcept = default;
            AscendingIterator &operator=(AscendingIterator &&other) noexcept = default;
            ~AscendingIterator() = default;


            bool operator>(const AscendingIterator &rhs) const;   // Greater than comparison operator
            bool operator<(const AscendingIterator &rhs) const;   // Less than comparison operator
            AscendingIterator &begin();                            // Iterator pointing to the beginning of the container
            AscendingIterator &end();                              // Iterator pointing to the end of the container
        };

        class SideCrossIterator
        {

        private:
            std::vector<int>::iterator it_s;             // Iterator for traversing the set in SideCrossIterator
            std::vector<int>::iterator it_e;             // Iterator pointing to the end of the set in SideCrossIterator
            std::vector<int>::iterator current;          // Current iterator position
            std::vector<int>::iterator _end;             // Iterator pointing to the end of the container
            MagicalContainer *_p_m;                      // Pointer to the MagicalContainer object
            int size_step = 0;                           // Size step counter
            int count;                                   // Counter for SideCrossIterator


        public:
            SideCrossIterator(MagicalContainer &pointer1)
                : current(pointer1._set.begin()), it_s(pointer1._set.begin()), it_e(pointer1._set.end()),
                  _p_m(&pointer1), count(0), _end(pointer1._set.begin()), size_step(0)
            {
                //  std::cout << "++SideCrossIterator"<<std::endl;
            }

            int operator*() const;                           // Dereference operator
            SideCrossIterator &operator=(const SideCrossIterator &other);    // Assignment operator
            SideCrossIterator &operator++();                  // Pre-increment operator (++i)
            const SideCrossIterator operator++(int);          // Post-increment operator (i++)
            bool operator==(const SideCrossIterator &rhs) const;    // Equality comparison operator
            bool operator!=(const SideCrossIterator &rhs) const;    // Inequality comparison operator

            // Rule of Five
            SideCrossIterator(const SideCrossIterator &other) = default;           // Copy constructor
            SideCrossIterator(SideCrossIterator &&other) noexcept = default;       // Move constructor
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept = default;   // Move assignment operator
            ~SideCrossIterator() = default;                                        // Destructor

            bool operator>(const SideCrossIterator &rhs) const;    // Greater than comparison operator
            bool operator<(const SideCrossIterator &rhs) const;    // Less than comparison operator
            SideCrossIterator &begin();                             // Iterator pointing to the beginning of the container
            SideCrossIterator &end();                               // Iterator pointing to the end of the container

   

        };

        class PrimeIterator
        {

        private:
            std::vector<int *>::iterator it;         // Iterator for traversing the _prime vector
            MagicalContainer *_p_m;                   // Pointer to the MagicalContainer object

        public:
            PrimeIterator(MagicalContainer &pointer1)
                : it(pointer1._prime.begin()), _p_m(&pointer1)
            {
            }


            int operator*() const;                        // Dereference operator
            PrimeIterator &operator++();                   // Pre-increment operator (++i)
            PrimeIterator &operator=(const PrimeIterator &other);    // Assignment operator
            const PrimeIterator operator++(int);           // Post-increment operator (i++)
            bool operator==(const PrimeIterator &rhs) const;    // Equality comparison operator
            bool operator!=(const PrimeIterator &rhs) const;    // Inequality comparison operator

            // Rule of Five
            PrimeIterator(const PrimeIterator &other) = default;             // Copy constructor
            PrimeIterator(PrimeIterator &&other) noexcept = default;         // Move constructor
            PrimeIterator &operator=(PrimeIterator &&other) noexcept = default;   // Move assignment operator
            ~PrimeIterator() = default;                                      // Destructor

            bool operator>(const PrimeIterator &rhs) const;    // Greater than comparison operator
            bool operator<(const PrimeIterator &rhs) const;    // Less than comparison operator
            PrimeIterator &begin();                             // Iterator pointing to the beginning of the _prime vector
            PrimeIterator &end();                               // Iterator pointing to the end of the _prime vector

 
        };
    };
}