#include "Fraction.hpp"
#include <iostream>
#include <sstream>
#include <utility>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <limits>

const double EPSILON = 1e-9;
const int max_limit = std::numeric_limits<int>::max();
const int min_limit = std::numeric_limits<int>::min();
using namespace std;

namespace ariel
{

    // Default constructor
    Fraction::Fraction()
    {
        this->_numerator = 0,
        this->_denominator = 1;
        simplify();
    }

    // Parameterized constructor
    Fraction::Fraction(int numerator, int denominator)
    {

        if (denominator == 0)
        {
            throw std::invalid_argument("cannot devide by 0");
        }
        if (numerator != denominator)
        {
            if (denominator < 0)
            {
                _numerator = numerator * -1;
                _denominator = denominator * -1;
            }
            else
            {
                _numerator = numerator;
                _denominator = denominator;
            }
            simplify();
        }
        else
        {
            _numerator = 1;
            _denominator = 1;
        }
    }
    Fraction::Fraction(float value)
    {
        int sign;
        if (value > 0)
        {
            sign = 1;
        }
        else
            sign = -1;

        value = abs(value);
        int complete = (int)value;
        float rest = value - complete;
        int denominator = 1;

        // Round frac to 3 decimal places
        rest = round(rest * 1000) / 1000.0;
        while (abs(rest - round(rest)) > EPSILON)
        {
            rest *= 10;
            denominator *= 10;
        }
        int r = round(rest);
        int numerator = sign * (complete * denominator + r);
        this->_numerator = numerator;
        this->_denominator = denominator;
        simplify();
    }

    // Copy constructor
    Fraction::Fraction(const Fraction &frac)
    {
        _numerator = frac._numerator,
        _denominator = frac._denominator;
        simplify();
    }
    // copy assignment operator
    Fraction &Fraction::operator=(const Fraction &frac)
    {
        if (this != &frac)
        {
            _numerator = frac._numerator;
            _denominator = frac._denominator;
        }
        return *this;
    }

    // Move constructor
    Fraction::Fraction(Fraction &&other) noexcept : _numerator(std::exchange(other._numerator, 0)),
                                                    _denominator(std::exchange(other._denominator, 1))
    {
    }

    // Move assignment operator
    Fraction &Fraction::operator=(Fraction &&frac) noexcept
    {
        if (this != &frac)
        {
            _numerator = std::exchange(frac._numerator, 0);
            _denominator = std::exchange(frac._denominator, 1);
        }
        return *this;
    }

    // Destructor
    Fraction::~Fraction() {}

    // Simplify the fraction
    void Fraction::simplify()
    {
        if (_numerator == 0)
        {
            _denominator = 1;
        }
        else
        {
            int divisor = gcd(_numerator, _denominator);
            _numerator /= divisor;
            _denominator /= divisor;
        }
        if (_denominator < 0)
        {
            _numerator *= -1;
            _denominator *= -1;
        }
    }
    // Euclid based gcd algorithm
    int Fraction::gcd(int num1, int num2)
    {
        if (num1 == 0)
        {
            return num2;
        }
        return gcd(num2 % num1, num1);
    }

    Fraction a(1, 1);
    // Fraction Fraction::operator+() { return a; }
    Fraction Fraction::operator+(const Fraction &frac)
    {

        int numerator = (_numerator * frac._denominator) + (frac._numerator * _denominator);
        int denominator = _denominator * frac._denominator;
        Fraction result = Fraction(numerator, denominator);
        if (frac._numerator > 0 && _numerator > max_limit - frac._numerator)
        {
            throw std::overflow_error("Number passes the limit");
        }
        if (frac._numerator < 0 && frac._numerator < min_limit - frac._numerator)
        {
            throw std::overflow_error("Number passes the limit");
        }

        return result;
    }
    Fraction Fraction::operator+(const float &num)
    {
        Fraction new_num = Fraction(num);
        int numerator = (_numerator * new_num._denominator) + (new_num._numerator * _denominator);
        int denominator = _denominator * new_num._denominator;
        Fraction result = Fraction(numerator, denominator);

        return result;
    }

    Fraction operator+(const float &num1, const Fraction &frac2)
    {
        Fraction new_num = Fraction(num1);
        int numerator = (frac2._numerator * new_num._denominator) + (new_num._numerator * frac2._denominator);
        int denominator = frac2._denominator * new_num._denominator;
        Fraction result = Fraction(numerator, denominator);

        return result;
    }

    // Fraction operator+(const int &num1, const Fraction &frac2)
    // {
    //     Fraction new_num = Fraction(num1, 1);
    //     int numerator = (frac2._numerator * new_num._denominator) + (new_num._numerator * frac2._denominator);
    //     int denominator = frac2._denominator * new_num._denominator;
    //     Fraction result = Fraction(numerator, denominator);
    //     return result;
    // }

    Fraction Fraction::operator-(const Fraction &frac)
    {
        int numerator = (_numerator * frac._denominator) - (frac._numerator * _denominator);
        int denominator = _denominator * frac._denominator;
        Fraction result = Fraction(numerator, denominator);
        if (_numerator > 0 && frac._numerator < 0 && _numerator > max_limit + frac._numerator)
        {
            throw std::overflow_error("Number passes the limit");
        }
        if (_numerator < 0 && frac._numerator > 0 && _numerator < min_limit + frac._numerator)
        {
            throw std::overflow_error("Number passes the limit");
        }

        return result;
    }
    Fraction Fraction::operator-(const float &num)
    {
        Fraction new_num = Fraction(num);
        int numerator = (_numerator * new_num._denominator) - (new_num._numerator * _denominator);
        int denominator = _denominator * new_num._denominator;
        Fraction result = Fraction(numerator, denominator);

        return result;
    }
    // Fraction Fraction::operator-(const int &num)
    // {
    //     Fraction new_num = Fraction(num, 1);
    //     int numerator = (_numerator * new_num._denominator) - (new_num._numerator * _denominator);
    //     int denominator = _denominator * new_num._denominator;
    //     Fraction result = Fraction(numerator, denominator);
    //     return result;
    // }

    Fraction operator-(const float &num1, const Fraction &frac2)
    {
        Fraction new_num = Fraction(num1);
        int numerator = (new_num._numerator * frac2._denominator) - (frac2._numerator * new_num._denominator);
        int denominator = frac2._denominator * new_num._denominator;
        Fraction result = Fraction(numerator, denominator);

        return result;
    }

    Fraction Fraction::operator*(const Fraction &frac)
    {
        if (_numerator > 0 && frac._numerator > max_limit - _numerator)
        {
            throw std::overflow_error("Number passes the limit");
        }
        if (_denominator > 0 && frac._numerator > max_limit - _denominator)
        {
            throw std::overflow_error("Number passes the limit");
        }

        int numerator = _numerator * frac._numerator;
        int denominator = _denominator * frac._denominator;
        Fraction result = Fraction(numerator, denominator);
        return result;
    }
    Fraction Fraction::operator*(const float &num)
    {
        Fraction new_num = Fraction(num);
        int numerator = _numerator * new_num._numerator;
        int denominator = _denominator * new_num._denominator;
        Fraction result = Fraction(numerator, denominator);
        return result;
    }

    Fraction operator*(const float &num1, Fraction const &frac2)
    {
        Fraction new_num = Fraction(num1);
        int numerator = frac2._numerator * new_num._numerator;
        int denominator = frac2._denominator * new_num._denominator;
        Fraction result = Fraction(numerator, denominator);
        return result;
    }

    Fraction Fraction::operator/(const Fraction &frac)
    {
        if (frac._numerator == 0)
            throw std::runtime_error("Cannot devide by zero");
        if (_numerator > 0 && frac._numerator > max_limit - _numerator)
        {
            throw std::overflow_error("Number passes the limit");
        }
        if (_denominator > 0 && _denominator - 1 > max_limit - frac._denominator)
        {
            throw std::overflow_error("Number passes the limit");
        }
        int numerator = _numerator * frac._denominator;
        int denominator = _denominator * frac._numerator;
        Fraction result = Fraction(numerator, denominator);

        return result;
    }
    // Fraction Fraction::operator/(const int &num)
    // {
    //     if (num == 0)
    //     {
    //         throw("cannot devide with 0");
    //     }
    //     else
    //     {
    //         int numerator = _numerator * 1;
    //         int denominator = _denominator * num;
    //         Fraction result = Fraction(numerator, denominator);

    //         return result;
    //     }
    // }
    Fraction Fraction::operator/(const float &num)
    {
        if (num == 0.0)
            throw std::runtime_error("Cannot devide by zero");
        Fraction new_num = Fraction(num);
        int numerator = _numerator * new_num._denominator;
        int denominator = _denominator * new_num._numerator;
        Fraction result = Fraction(numerator, denominator);
        return result;
    }

    Fraction operator/(const float &num1, const Fraction &frac2)
    {
        Fraction new_num = Fraction(num1);
        int numerator = new_num._numerator * frac2._denominator;
        int denominator = new_num._denominator * frac2._numerator;
        Fraction result = Fraction(numerator, denominator);
        return result;
    }

    // Comperison boolean operators
    bool operator>(const Fraction &frac1, const Fraction &frac2)
    {
        float f1 = (float)frac1._numerator / frac1._denominator;
        float f2 = (float)frac2._numerator / frac2._denominator;
        bool result = f1 > f2;
        return result;
    }
    bool operator>(const float &num1, const Fraction &frac2)
    {
        float f2 = (float)frac2._numerator / frac2._denominator;
        bool result = num1 > f2;
        return result;
    }
    bool operator>(const Fraction &frac1, const float &num2)
    {
        float f1 = (float)frac1._numerator / frac1._denominator;
        bool result = f1 > num2;
        return result;
    }

    bool operator<(const Fraction &frac1, const Fraction &frac2)
    {
        float f1 = (float)frac1._numerator / frac1._denominator;
        float f2 = (float)frac2._numerator / frac2._denominator;
        bool result = f1 < f2;
        return result;
    }
    bool operator<(const float &num1, const Fraction &frac2)
    {
        float f2 = (float)frac2._numerator / frac2._denominator;
        bool result = num1 < f2;
        return result;
    }
    bool operator<(const Fraction &frac1, const float &num2)
    {
        float f1 = (float)frac1._numerator / frac1._denominator;
        bool result = f1 < num2;
        return result;
    }

    bool operator>=(const Fraction &frac1, const Fraction &frac2)
    {
        float f1 = (float)frac1._numerator / frac1._denominator;
        float f2 = (float)frac2._numerator / frac2._denominator;
        bool result = f1 >= f2;
        return result;
    }
    bool operator>=(const float &num1, const Fraction &frac2)
    {
        float f2 = (float)frac2._numerator / frac2._denominator;
        bool result = num1 >= f2;
        return result;
    }
    bool operator>=(const Fraction &frac1, const float &num2)
    {
        float f1 = (float)frac1._numerator / frac1._denominator;
        bool result = f1 >= num2;
        return result;
    }

    bool operator<=(const Fraction &frac1, const Fraction &frac2)
    {
        float f1 = (float)frac1._numerator / frac1._denominator;
        float f2 = (float)frac2._numerator / frac2._denominator;
        bool result = f1 <= f2;
        return result;
    }
    bool operator<=(const float &num1, const Fraction &frac2)
    {
        float f2 = (float)frac2._numerator / frac2._denominator;
        bool result = num1 <= f2;
        return result;
    }
    bool operator<=(const Fraction &frac1, const float &num2)
    {
        float f1 = (float)frac1._numerator / frac1._denominator;
        bool result = f1 <= num2;
        return result;
    }

    bool operator==(const Fraction &frac1, const Fraction &frac2)
    {
        float f1 = (float)frac1._numerator / frac1._denominator;
        float f2 = (float)frac2._numerator / frac2._denominator;
        bool result = f1 == f2;
        return result;
    }
    bool operator==(const float &num1, const Fraction &frac2)
    {
        float f2 = (float)frac2._numerator / frac2._denominator;
        bool result = num1 == f2;
        return result;
    }
    bool operator==(const Fraction &frac1, const float &num2)
    {
        float f1 = (float)frac1._numerator / frac1._denominator;
        bool result = f1 == num2;
        return result;
    }

    // Increase / decreace by 1 operators
    Fraction &Fraction::operator++()
    {
        _numerator += _denominator;
        return *this;
    }
    Fraction Fraction::operator++(int num)
    {
        Fraction before_inc = Fraction(_numerator, _denominator);
        _numerator += _denominator;
        return before_inc;
    }
    Fraction &Fraction::operator--()
    {
        _numerator -= _denominator;
        return *this;
    }
    Fraction Fraction::operator--(int num)
    {
        Fraction before_dec = Fraction(_numerator, _denominator);
        _numerator -= _denominator;
        return before_dec;
    }
    std::ostream &operator<<(std::ostream &output, const Fraction &frac)
    {
        if (frac._denominator < 0)
        {
            output << -1 * frac._numerator << "/" << -1 * frac._denominator;
        }
        else
        {
            output << frac._numerator << "/" << frac._denominator;
        }
        return output;
    }
    std::istream &operator>>(std::istream &input, Fraction &frac)
    {
        if (!(input >> frac._numerator >> frac._denominator))
        {
            throw std::runtime_error("Invalid input");
        }
        else if (frac._denominator == 0)
        {
            throw std::runtime_error("invalid input");
        }

        return input;
    }
}