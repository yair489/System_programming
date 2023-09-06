#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>
#include <limits>


using namespace ariel;


TEST_CASE("Removing elements from MagicalContainer") {
    MagicalContainer container;

    SUBCASE("Removing") {
        container.addElement(10);
        container.addElement(20);
        container.addElement(30);
        container.removeElement(20);
        CHECK(container.size() == 2);
    }

    SUBCASE("Removing ") {
        container.addElement(10);
        container.addElement(20);
        container.addElement(30);
        CHECK_NOTHROW(container.removeElement(40));
        CHECK_NOTHROW(container.removeElement(50));
        CHECK_NOTHROW(container.removeElement(60));
        CHECK_NOTHROW(container.removeElement(70));
        CHECK_NOTHROW(container.removeElement(80));
        CHECK_NOTHROW(container.removeElement(90));
        CHECK(container.size() == 3);
        container.addElement(1);
        container.addElement(2);
        container.addElement(32);
        CHECK(container.size() == 6);
    }
}

TEST_CASE("Equality and inequality operators") {
    MagicalContainer container1;
    container1.addElement(10);
    container1.addElement(20);
    container1.addElement(30);

    MagicalContainer container2;
    container2.addElement(10);
    container2.addElement(20);
    container2.addElement(30);

    MagicalContainer container3;
    container3.addElement(10);
    container3.addElement(30);

    CHECK(container1 == container2);
    CHECK(container1 != container3);
}

TEST_CASE("AscendingIterator") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);

    SUBCASE("Iterating through elements") {
        MagicalContainer::AscendingIterator id(container);
        auto it =id.begin();
        CHECK(*it == 10);
        ++it;
        CHECK(*it == 20);
        ++it;
        CHECK(*it == 30);
        ++it;
        CHECK(it == id.end());
        CHECK_NOTHROW(*it);
        // CHECK_NOTHROW(it);
        CHECK_THROWS(++it);
    }

    SUBCASE("Comparing iterators") {

        MagicalContainer::AscendingIterator id(container);
        auto it1 =id.begin();

        MagicalContainer::AscendingIterator id1(container);
        auto it2 =id1.begin();

        MagicalContainer::AscendingIterator id2(container);
        auto it3 =id2.end();

        CHECK(it1 == it2);
        CHECK(it1 != it3);
        CHECK(it2 != it3);
         it1++;
        CHECK(it1 != it2);
        CHECK(it2 != it3);

        while (it1 != it1.end()) {
            ++it1;
        }
        CHECK(it1 == it3);
        while (it2 != it2.end()) {
            ++it2;
        }
        CHECK(it2 == it3);
    }
}

TEST_CASE("PrimeIterator") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    SUBCASE("Iterating through prime elements") {

         MagicalContainer::PrimeIterator id(container);
        auto it =id.begin();

        // auto it = container.PrimeIterator().begin();
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == id.end());
    }
}

TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);


    SUBCASE("Iterating in a side-to-side pattern") {

        MagicalContainer::SideCrossIterator id(container);
        auto it =id.begin();

        CHECK(*it == 10);
        ++it;
        CHECK(*it == 20);
        ++it;
        CHECK(*it == 30);
        ++it;
        CHECK(it == id.end());
    }
}
TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);
    container.addElement(50);

    MagicalContainer container1;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);
    container.addElement(50);

    SUBCASE("Iterating in a side-to-side pattern") {

        MagicalContainer::SideCrossIterator id1(container);
        auto it1 =id1.begin();
        MagicalContainer::AscendingIterator id2(container);
        auto it2 =id2.begin();
         MagicalContainer::PrimeIterator id3(container);
        auto it3 =id3.begin();

        MagicalContainer::SideCrossIterator id4(container1);
        auto it4 =id4.begin();
        MagicalContainer::AscendingIterator id5(container1);
        auto it5 =id5.begin();
         MagicalContainer::PrimeIterator id6(container1);
        auto it6 =id6.begin();

        CHECK(id1==id4);
        CHECK(id2==it5);
        CHECK(id3==it6);

        CHECK_FALSE(id5==id2);
        // CHECK_THROWS(id1==id4);
        // CHECK_THROWS(id6==id3);

        it1++;
        CHECK_FALSE(it1<it4);
        CHECK_FALSE(it1==it4);
        CHECK(it1!=it4);

        it2++;
        CHECK_FALSE(it2<it5);
        CHECK_FALSE(it2==it5);
        CHECK(it2!=it5);

        it3++;
        CHECK_FALSE(it3<it6);
        CHECK_FALSE(it3==it6);
        CHECK(it3!=it6);

        it6++;
        CHECK_FALSE(it3<it6);
        CHECK(it3==it6);
        CHECK_FALSE(it3!=it6);

        
    }
}