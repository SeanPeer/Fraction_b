#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <stdbool.h>

using namespace std;
namespace ariel
{
    class Fraction
    {

    private:
        int _numerator;
        int _denominator;

    public:
        Fraction();
        Fraction(int numerator, int denominator);
        Fraction(float value);
        Fraction(const Fraction &frac);
        Fraction(Fraction &&other) noexcept;
        ~Fraction();

        double getFrac() const
        {
            return double(this->_numerator) / double(this->_denominator);
        }

        int getNumerator() const
        {
            return this->_numerator;
        }

        int getDenominator() const
        {
            return this->_denominator;
        }

        int gcd(int num1, int num2);
        void simplify();
        // Arithmetic operators
        Fraction operator+();
        Fraction operator+(const Fraction &frac);
        Fraction operator+(const float &num);
        friend Fraction operator+(const Fraction &frac1, const Fraction &frac2);
        friend Fraction operator+(const float &num1, const Fraction &frac2);
        friend Fraction operator+(const Fraction &frac1, const float &num2);
        //friend Fraction operator+(const int &num1, const Fraction &frac2);
        friend Fraction operator+(const Fraction &frac1, const int &num2);

        Fraction operator-();
        Fraction operator-(const Fraction &frac);
        Fraction operator-(const float &num);
        //Fraction operator-(const int &num);
        friend Fraction operator-(const Fraction &frac1, const Fraction &frac2);
        friend Fraction operator-(const float &num1, const Fraction &frac2);
        friend Fraction operator-(const Fraction &frac1, const float &num2);
        // friend Fraction operator-(const int &num1, const Fraction &frac2);
        //friend Fraction operator-(const Fraction &frac1, const int &num2);

        Fraction operator*();
        Fraction operator*(const Fraction &frac);
        Fraction operator*(const float &frac);
        //Fraction operator*(const int &frac);
        friend Fraction operator*(const Fraction &frac1, const Fraction &frac2);
        friend Fraction operator*(const float &num1, const Fraction &frac2);
        friend Fraction operator*(const Fraction &frac1, const float &num2);

        // Fraction operator/();
        Fraction operator/(const Fraction &frac);
        Fraction operator/(const float &frac);
        //Fraction operator/(const int &frac);
        friend Fraction operator/(const Fraction &frac1, const Fraction &frac2);
        friend Fraction operator/(const float &num1, const Fraction &frac2);
        friend Fraction operator/(const Fraction &frac1, const float &num2);

        // Comperison boolean operators
        friend bool operator>(const Fraction &frac1, const Fraction &frac2);
        friend bool operator>(const float &num1, const Fraction &frac2);
        friend bool operator>(const Fraction &frac1, const float &num2);

        friend bool operator<(const Fraction &frac1, const Fraction &frac2);
        friend bool operator<(const float &num1, const Fraction &frac2);
        friend bool operator<(const Fraction &frac1, const float &num2);

        friend bool operator>=(const Fraction &frac1, const Fraction &frac2);
        friend bool operator>=(const float &num1, const Fraction &frac2);
        friend bool operator>=(const Fraction &frac1, const float &num2);

        friend bool operator<=(const Fraction &frac1, const Fraction &frac2);
        friend bool operator<=(const float &num1, const Fraction &frac2);
        friend bool operator<=(const Fraction &frac1, const float &num);

        friend bool operator==(const Fraction &frac1, const Fraction &frac2);
        friend bool operator==(const float &num1, const Fraction &frac2);
        friend bool operator==(const Fraction &frac1, const float &num2);

        Fraction &operator=(const Fraction &frac);
        Fraction &operator=(Fraction &&frac) noexcept;

        // Increase / decreace by 1 operators
        Fraction &operator++();
        Fraction operator++(int num);
        Fraction &operator--();
        Fraction operator--(int num);

        // Stream operators
        friend std::ostream &operator<<(std::ostream &output, const Fraction &frac);
        friend std::istream &operator>>(std::istream &input, Fraction &frac);
    };
}
#endif
