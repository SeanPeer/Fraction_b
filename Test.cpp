#include "doctest.h"
#include "sources/Fraction.hpp"
#include <limits>

using namespace std;
using namespace ariel;

Fraction a(1, 2);
Fraction b(2, 4);
Fraction c(3, 4);
Fraction d(4, 4);
Fraction f(0, 1);

TEST_CASE("Basic Arithmetic ")
{
    CHECK((a + b) == 1.0);
    CHECK((b + b) == 1.0);
    CHECK((a + b) == d);
    CHECK((b + b) == d);
    CHECK((c - a) == 0.25);
    CHECK((d - d) == 0.0);
    CHECK((d - d) == f);
    CHECK((f - f) == 0.0);
    CHECK((f - f) == f);
    CHECK((a * d) == 0.5);
    CHECK((d * d) == 1.0);
    CHECK((f * f) == 0.0);
    CHECK((f * f) == f);
    CHECK((a / b) == 1);
    CHECK((a / b) == d);
    CHECK((a / d) == a);
    CHECK((a / d) == 0.5);
}

TEST_CASE("Comperison boolean operators")
{
    CHECK((a > b) == false);
    CHECK((a == b) == true);
    CHECK((a >= d) == false);
    CHECK((a <= d) == true);
    CHECK((1.0 == d) == true);
    CHECK((a == 0.2) == false);
    CHECK((a == 0.5) == true);
}

TEST_CASE("equal 0")
{

    Fraction z1(0, 1);
    Fraction z2(0, 2);
    CHECK_EQ(z1, z2);
}
TEST_CASE("equal 1/2")
{
    Fraction h1(1, 2);
    Fraction h2(2, 4);
    CHECK_EQ(h1, h2);
    Fraction a1(-1, 2);
    Fraction a2(1, -2);
    CHECK_EQ(a1, a2);

    Fraction t3(3, 4);
    CHECK_FALSE(h1 == t3);
}

TEST_CASE("Addition")
{
    Fraction b1(1, 2);
    Fraction b2(1, 3);
    Fraction b3(5, 6);
    CHECK_EQ(b1 + b2, b3);

    Fraction h3(5, 2);
    CHECK_EQ(b1 + 2.000, h3);

    Fraction l1(1, 2);
    Fraction l2(-3, 2);
    CHECK_EQ(l1 + -2.000, l2);
}

TEST_CASE("substraction")
{
    Fraction c1(1, 2);
    Fraction c2(1, 3);
    Fraction c3(-1, 6);
    CHECK_EQ(c2 - c1, c3);

    Fraction i1(1, 2);
    Fraction i2(-3, 2);
    CHECK_EQ(i1 - 2, i2);

    Fraction m1(1, 2);
    Fraction m2(5, 2);
    CHECK_EQ(m1 - -2, m2);
}
TEST_CASE("Multiply")
{
    Fraction d1(1, 2);
    Fraction d2(2, 3);
    Fraction d3(1, 3);
    CHECK_EQ(d1 * d2, d3);

    Fraction f1(1, 2);
    Fraction f2(2, 2);
    Fraction f3(1, 1);
    CHECK_EQ(f1 * 2, f2);
    CHECK_EQ(f2, f3);

    Fraction j1(1, 2);
    Fraction j2(-1, 2);
    CHECK_EQ(j1 * -1, j2);

    Fraction n1(1, 2);
    Fraction n2(0, 1);
    CHECK_EQ(n1 * 0, n2);
}
TEST_CASE("Devide")
{
    Fraction e1(1, 2);
    Fraction e2(2, 3);
    Fraction e3(3, 4);
    CHECK_EQ(e1 / e2, e3);

    Fraction g2(2, 4);
    Fraction g3(1, 4);
    CHECK_EQ(e1 / 2, g3);

    Fraction k1(1, 2);
    Fraction k2(-1, 2);
    CHECK_EQ(k1 / -1, k2);
}

TEST_CASE("")
{
    Fraction o1(1, 2);
    Fraction o2(0, 1);
    CHECK_THROWS_AS(o1 / 0, std::runtime_error);

    CHECK_THROWS_AS(Fraction(1, 0), std::invalid_argument);

    Fraction f(1, 2);
    CHECK_THROWS_AS(f / 0, std::runtime_error);

;
}