/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;

int main()
{
    Fraction a(5, 3), b(14, 21);
    cout << "a: " << a << "b: " << b << endl;
    cout << "a+b" << a + b << endl;
    cout << "a-b" << a - b << endl;
    cout << "a/b" << a / b << endl;
    cout << "a*b" << a * b << endl;
    cout << "2.3*b" << 2.3 * b << endl;
    cout << "a+2.421" << a + 2.421 << endl;
    Fraction c = a + b - 1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1)
        cout << " a is bigger than 1.1" << endl;
    else
        cout << " a is smaller than 1.1" << endl;

    // my own demo
    Fraction z(0.3333);
    cout << z.getNumerator() << endl;
    cout << z.getDenominator() << endl;

    Fraction x(2, 5), y(4, 5);
    Fraction w = x - y;
    cout << w.getNumerator() << endl;
    cout << w.getDenominator() << endl;

    Fraction x3 = Fraction(0.4);

    Fraction w2 = x3 - y;
    cout << w2.getNumerator() << endl;
    cout << w2.getDenominator() << endl;

    std::stringstream ss_in("1 2 3 -4");
    Fraction frac1, frac2;
    ss_in >> frac1 >> frac2;

    cout << frac1 << frac2 << endl;
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    cout << max_int << endl;
    cout << min_int << endl;

    std::stringstream ss_out;
    ss_out << frac1 << " and " << frac2;
}
