#pragma once
#include <iostream>
#include <string>


using namespace std;

class Fraction
{
	long numerator, denominator;
	// Euclidean algorithm for greatest common divisor
	long gcd(long a, long b);
public:
	Fraction(void);
	Fraction(double Number);
	Fraction(std::string FractionString);
	// Destructur
	~Fraction(void);

	// Getter and Setter
	long getNumerator(void);
	long getDenominator(void);
	void setNumerator(long Numerator);
	void setDenominator(long Denominator);

	// Fraction functions
	bool reduce(void);
	void convertDoubleToFraction(double Number);
	double convertFractionToDouble(void);
	bool convertStringToFraction(std::string FractionString);
	string readFraction();
	// Operator overloading functions
	bool operator<(Fraction fraction);
	bool operator<=(Fraction fraction);
	bool operator>(Fraction fraction);
	bool operator>=(Fraction fraction);
	bool operator==(Fraction fraction);
	bool operator!=(Fraction fraction);
	operator double();
	operator float();
	operator long();
	operator std::string();
	Fraction operator+(Fraction fraction);
	Fraction operator+=(Fraction fraction);
	Fraction operator-=(Fraction fraction);
	Fraction operator-(Fraction fraction);
	Fraction operator*(Fraction fraction);
	Fraction operator*=(Fraction fraction);
	Fraction operator/(Fraction fraction);
	Fraction operator/=(Fraction fraction);
	//Fraction operator~();
	Fraction operator++();
	Fraction operator++(int notused);
	Fraction operator--();
	Fraction operator--(int notused);
	Fraction operator^(double);
};

class FractionInputFailException : public std::exception {
public: virtual const char* what() const throw() { return "Incorrect Input"; }
};

/* Left Shift Operator overloading functions (need to be declared global) */
std::ostream& operator<<(std::ostream &out, Fraction &Fraction);
/** Right Shift Operator overloading functions (need to be declared global) */
std::istream& operator>>(std::istream &in, Fraction &Fraction);