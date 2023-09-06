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
        std::vector<int> _set;
        std::vector<int *> _prime;

        bool isPrime(int number);
        void update();

    public:
        MagicalContainer() {}
        ~MagicalContainer();
        MagicalContainer(const MagicalContainer &other);

        MagicalContainer &operator=(const MagicalContainer &other) noexcept = default;
        MagicalContainer(MagicalContainer &&other) = default;
        MagicalContainer &operator=(MagicalContainer &&other) = default;

        void addElement(int element);
        void removeElement(int element);
        size_t size() const
        {
            return _set.size();
        }

        bool operator==(const MagicalContainer &other) const;
        bool operator!=(const MagicalContainer &other) const;

        class AscendingIterator
        {

        private:
            std::vector<int>::iterator it;
            MagicalContainer *pointerto;
            int size_step = 0;

        public:
            AscendingIterator(MagicalContainer &pointer1)
                : it(pointer1._set.begin()), pointerto(&pointer1), size_step(0)
            {
            }
            // AscendingIterator() {}
            int operator*() const;
            AscendingIterator &operator++();         // ++i;
            const AscendingIterator operator++(int); // i++;
            bool operator==(const AscendingIterator &rhs) const;
            bool operator!=(const AscendingIterator &rhs) const;
            AscendingIterator &operator=(const AscendingIterator &other);

            AscendingIterator(const AscendingIterator &other) = default;
            AscendingIterator(AscendingIterator &&other) noexcept = default;
            AscendingIterator &operator=(AscendingIterator &&other) noexcept = default;
            ~AscendingIterator() = default;

            bool operator>(const AscendingIterator &rhs) const;
            bool operator<(const AscendingIterator &rhs) const;
            AscendingIterator &begin();
            AscendingIterator &end();
        };

        class SideCrossIterator
        {

        private:
            std::vector<int>::iterator it_s;
            std::vector<int>::iterator it_e;
            std::vector<int>::iterator current;
            std::vector<int>::iterator _end;
            MagicalContainer *pointerto;
            int size_step = 0;
            int count;

        public:
            SideCrossIterator(MagicalContainer &pointer1)
                : current(pointer1._set.begin()), it_s(pointer1._set.begin()), it_e(pointer1._set.end()),
                  pointerto(&pointer1), count(0), _end(pointer1._set.begin()), size_step(0)
            {
            }
            // SideCrossIterator() {}
            int operator*() const;
            SideCrossIterator &operator=(const SideCrossIterator &other);
            SideCrossIterator &operator++(); // ++i;

            const SideCrossIterator operator++(int); // i++;

            bool operator==(const SideCrossIterator &rhs) const;
            bool operator!=(const SideCrossIterator &rhs) const;

            SideCrossIterator(const SideCrossIterator &other) = default;
            SideCrossIterator(SideCrossIterator &&other) noexcept = default;
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept = default;
            ~SideCrossIterator() = default;

            bool operator>(const SideCrossIterator &rhs) const;
            bool operator<(const SideCrossIterator &rhs) const;
            SideCrossIterator &begin();
            SideCrossIterator &end();
        };

        class PrimeIterator
        {

        private:
            std::vector<int *>::iterator it;
            MagicalContainer *pointerto;

        public:
            PrimeIterator(MagicalContainer &pointer1)
                : it(pointer1._prime.begin()), pointerto(&pointer1)
            {
            }
            // PrimeIterator() {}
            int operator*() const;

            PrimeIterator &operator++(); // ++i;
            PrimeIterator &operator=(const PrimeIterator &other);
            const PrimeIterator operator++(int); // i++;

            bool operator==(const PrimeIterator &rhs) const;

            bool operator!=(const PrimeIterator &rhs) const;

            PrimeIterator(const PrimeIterator &other) = default;
            PrimeIterator(PrimeIterator &&other) noexcept = default;
            PrimeIterator &operator=(PrimeIterator &&other) noexcept = default;
            ~PrimeIterator() = default;
            bool operator>(const PrimeIterator &rhs) const;
            bool operator<(const PrimeIterator &rhs) const;
            PrimeIterator &begin();
            PrimeIterator &end();
        };
    };
}