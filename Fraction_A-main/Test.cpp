#include <iostream>
#include <fstream>
#include <sstream>

#include <stdexcept>
using namespace std;
#include "sources/Fraction.hpp"
using namespace ariel;

#include "doctest.h"
/*https://github.com/doctest/doctest*/

TEST_SUITE("constructors") {

    TEST_CASE("constructors with a positive number in the denominator ") {
        CHECK_NOTHROW(Fraction con(0, 4));
        CHECK_NOTHROW(Fraction con(-1, 4));
        CHECK_NOTHROW(Fraction con(2, 4));
        // CHECK(allcards);
    }
    TEST_CASE("constructors with a negative number in the denominator ") {
        CHECK_NOTHROW(Fraction con(2, -4));
        CHECK_NOTHROW(Fraction con(0, -4));
        CHECK_NOTHROW(Fraction con(-5, -4));
    }
    TEST_CASE("constructors with a zero number in the denominator ") {
        CHECK_THROWS_AS(Fraction con(2, 0),invalid_argument);
        CHECK_THROWS_AS(Fraction con(0, 0),invalid_argument);
        CHECK_THROWS_AS(Fraction con(-10, 0),invalid_argument);
    }
    TEST_CASE("constructors") {
        Fraction f1(3, 4);
        Fraction f3(3, 4);
        Fraction f2(30, -60);

        CHECK_EQ(f1, f3);
        CHECK_NE(f1, f2);
    }

    TEST_CASE("equal fraction") {
        Fraction f1(1, 2);
        Fraction f2(3, 6);
        Fraction f3(1, -2);
        Fraction f4(-3, 6);
        Fraction f5(-1, -2);
        Fraction f6(-3, -6);
        Fraction f7(100, 200);
        CHECK_EQ(f1, f2);
        CHECK_EQ(f3, f4);
        CHECK_EQ(f5, f6);
        CHECK_EQ(f6, f1);
        CHECK_EQ(f7, f1);
    }

}
TEST_SUITE("operators <=  >=  > < ==") {
    TEST_CASE("compare ==") {
        Fraction f1(1, 2);
        Fraction f2(1, 4);
        Fraction f3(1, 8);
        Fraction f4(1, -2);
        Fraction f5(5, 10);
        Fraction f6(1, 17);
        Fraction f7(0, 50);

        CHECK(f1==f5);
        CHECK_FALSE(f1==f2);
        CHECK_FALSE(f1==f4);
    }
    TEST_CASE("compare > < ") {
        Fraction f1(1, 2);
        Fraction f2(1, 4);
        Fraction f3(1, 8);
        Fraction f4(1, -2);
        Fraction f5(5, 10);
        Fraction f6(1, 17);
        Fraction f7(0, 50);

        bool gr= f1>f2;
        CHECK(gr);

         gr= f1>f3;
        CHECK(gr);

         gr= f7>f4;
        CHECK(gr);

         gr= f6< f2;
        CHECK(gr);

         gr= f7 <f6;
        CHECK(gr);

         gr= f1<= f5;
        CHECK(gr);

    }

    TEST_CASE("compare !=") {
        Fraction f1(1, 2);
        Fraction f2(1, 4);
        Fraction f3(1, 8);

        CHECK_NE(f1, f2);
        CHECK_NE(f1, f3);
        CHECK_NE(f3, f2);

    }

    TEST_CASE("compare >= ") {
        Fraction f1(1, 2);
        Fraction f2(1, 4);
        Fraction f3(1, 8);
        Fraction f4(1, -2);
        Fraction f5(5, 10);
        Fraction f6(1, 17);
        Fraction f7(0, 50);
        
        CHECK_GE(f1, f2);
        CHECK_GE(f2, f3);
        CHECK_GE(f3, f4);
        CHECK_GE(f6, f7);
        CHECK_GE(f5, f6);
        CHECK_GE(1.1, f2);
        CHECK_GE(0.5, f3);
        CHECK_GE(0.0, f4);
        CHECK_GE(0.6, f7);
        CHECK_GE(0.3, f6);
    }

    TEST_CASE("compare <= ") {
        Fraction f1(1, 2);
        Fraction f2(1, 4);
        Fraction f3(1, 8);
        Fraction f4(1, -2);
        Fraction f5(5, 10);
        Fraction f6(1, 17);
        Fraction f7(0, 50);
        
        CHECK_LE(f2, f1);
        CHECK_LE(f3, f2);
        CHECK_LE(f4, f3);
        CHECK_LE(f7, f6);
        CHECK_LE(f6, f5);
        CHECK_LE(f7, 0.001);
        CHECK_LE(f6, 0.1);
    }


TEST_SUITE(" +  -  / * operator ") {
    TEST_CASE("+ - OPERATOR") {
        CHECK_EQ(Fraction(1,4) +Fraction(1,4), Fraction(1,4)+Fraction(1,4));
        CHECK_EQ(Fraction(8,4) + Fraction(6,7), Fraction(20, 7));

        CHECK_EQ(Fraction(8,4) - Fraction(6,7), Fraction(8, 7));
        CHECK_EQ(Fraction(48,101) + Fraction(2,7), Fraction(538, 707));
        CHECK_EQ(Fraction(48,101) - Fraction(2,7), Fraction(134, 707));
        CHECK_EQ(Fraction(48,101) + Fraction(-2,7), Fraction(134, 707));


    }

    TEST_CASE("/ * OPERATOR") {
        CHECK_EQ(Fraction(1,4) /Fraction(1,4), Fraction(1,1));
        CHECK_EQ(Fraction(8,4) / Fraction(6,7), Fraction(7, 3));
        CHECK_EQ(Fraction(8,4) / Fraction(6,5), Fraction(5, 3));
        CHECK_EQ(Fraction(48,101) / Fraction(2,7), Fraction(168, 101));
        CHECK_EQ(Fraction(48,101) / Fraction(2,11), Fraction(264, 101));
        CHECK_EQ(Fraction(48,101) / Fraction(-2,7), Fraction(168, -101));

        CHECK_EQ(Fraction(1,4) *Fraction(1,4), Fraction(1,16));
        CHECK_EQ(Fraction(8,4) * Fraction(6,7), Fraction(12, 7));
        CHECK_EQ(Fraction(8,4) * Fraction(6,5), Fraction(12, 5));
        CHECK_EQ(Fraction(48,101) * Fraction(2,7), Fraction(96, 707));
        CHECK_EQ(Fraction(48,101) * Fraction(2,11), Fraction(96, 1111));
        CHECK_EQ(Fraction(48,101) * Fraction(-2,7), Fraction(-96, 707));


    }
    TEST_CASE("0 * OPERATOR") {
        CHECK_EQ(Fraction(1,4) *Fraction(0,4), Fraction(0,16));
        CHECK_EQ(Fraction(8,4) * Fraction(-0,7), Fraction(0, 7));
        CHECK_EQ(Fraction(8,4) * Fraction(0,-5), Fraction(0, 5));
    }
}

TEST_SUITE("prefix AND postfix increment") {

    TEST_CASE("prefix++") {
        Fraction f1(1, 2);
        Fraction f2(3, 2);
        Fraction f3(1, 8);
        Fraction f4(9, 8);
        
        
        CHECK_EQ(++f1, f2);
        CHECK_EQ(++f3, f4);
        CHECK_EQ(++f2, 2.5);
        CHECK_EQ(++f2, 3.5);
        CHECK_NE(++f1, f3);
        CHECK_NE(++f2, f4);
    }
    TEST_CASE("postfix++") {
        Fraction f1(1, 2);
        Fraction f2(1, 2);
        Fraction f3(1, 8);
        Fraction f4(9, 8);
        
        CHECK_EQ(f1, f2);
        CHECK_EQ(++f3, f4);
        CHECK_NE(f1++, f1);
        CHECK_EQ(f3++, f4);
    }
        TEST_CASE("prefix--") {
        Fraction f1(1, 2);
        Fraction f2(3, 2);
        Fraction f3(1, 8);
        Fraction f4(9, 8);
        Fraction f5(5, 2);
        
        CHECK_EQ(f1, --f2);
        CHECK_EQ(f3, --f4);
        CHECK_NE(--f1, f3);
        CHECK_EQ(f4, --f4);
        CHECK_NE(f3, --(--f5));
    }
    TEST_CASE("postfix--") {
        Fraction f1(1, 2);
        Fraction f2(1, 2);
        Fraction f3(1, 8);
        Fraction f4(9, 8);
         

        CHECK_EQ(f1, f2--);
        CHECK_EQ(f3, (--f4)--);
        
        CHECK_NE(f3, f1);
        CHECK_NE(f3--, f4);
    }
}

TEST_SUITE("input") {
    TEST_CASE("input ") {
        stringstream in1("1 1");
        Fraction f1;
        in1 >> f1;
         CHECK_NE(Fraction(1,1), f1);

        stringstream in2("101 17");
        Fraction f2;
        in2 >> f2;
         CHECK_NE(Fraction(101,17), f2);
    }
}
}