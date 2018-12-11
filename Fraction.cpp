#include "pch.h"
#include "Fraction.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <cstdlib>
#include <exception>
#include "Fraction.h"
#include "Error.h"


Fraction::Fraction(void) {
	this->numerator = 0;
	this->denominator = 0;
}


// Double-convert constructor

Fraction::Fraction(double Number) {
	this->convertDoubleToFraction(Number);
}

// String-convert constructor

Fraction::Fraction(std::string FractionString) {
	this->convertStringToFraction(FractionString);
}


// Standard deconstructor

Fraction::~Fraction(void) {}

//Recursive gcd function for
// the greatest common divisor

long Fraction::gcd(long a, long b) {
	//return b == 0 ? a : this->gcd(b, a % b);
	if (a == 0L)
		return b;
	if (b == 0L)
		return a;
	if (a == b)
		return a;
	if (a == 1L || b == 1L)
		return 1L;
	if (a % 2L == 0L && b % 2L == 0L)
		return 2L * this->gcd(a / 2L, b / 2L);
	if (a % 2L == 0L && b % 2L != 0L)
		return this->gcd(a / 2L, b);
	if (a % 2L != 0L && b % 2L == 0L)
		return this->gcd(a, b / 2L);
	if (a < b)
		return this->gcd((b - a) / 2L, a);
	else
		return this->gcd((a - b) / 2L, b);
}


// Getter for the numerator

long Fraction::getNumerator(void) {
	return this->numerator;
}


// Getter for the denominator

long Fraction::getDenominator(void) {
	return this->denominator;
}


// Setter for the numerator

void Fraction::setNumerator(long Numerator) {
	 
	this->numerator = Numerator;
}


// Setter for the denominator

void Fraction::setDenominator(long Denominator) {
	//if (Denominator == 0) {
	//	throw DenominatorError();
	//}
	this->denominator = Denominator;
}

string Fraction::readFraction() {
	string num;
	cout << "Input numerator: ";
	cin >> num;
	for (int i = 0; i < num.length(); i++) {
		if (!(isdigit(num[i]))) {
		throw isIntNumerator();
		}	
	}
	string den;
	cout << "Input denominator: ";
	cin >> den;
	for (int i = 0; i < den.length(); i++) {
		if (!(isdigit(den[i]))) {
			throw isIntDenominator();
		}
	}
	string result = "" + num + "/" + den;
	convertStringToFraction(result);
	return result;
	
}
// Reduce the fraction as low as possible

bool Fraction::reduce(void) {
	long nod = this->gcd(this->numerator, this->denominator);

	if (1 < nod) {
		this->numerator /= nod;
		this->denominator /= nod;

		return true;
	}
	else {
		return false;
	}
}


void Fraction::convertDoubleToFraction(double Number) {
	this->denominator = 1;

	while (((double)(int)Number) != Number) {
		Number = Number * 10;
		this->denominator = this->denominator * 10;
	}

	this->numerator = (long)Number;

	this->reduce();
}


double Fraction::convertFractionToDouble(void) {
	return (double)this->numerator / (double)this->denominator;
}



bool Fraction::convertStringToFraction(std::string FractionString) {
	std::size_t pos = FractionString.find("/");

	if (pos != std::string::npos) {
		try {
			this->numerator = atol(FractionString.substr(0, pos).c_str());
			this->denominator = atol(FractionString.substr(pos + 1).c_str());
		}
		catch (...) {
			return false;
		}

		if (this->denominator == 0) {
			throw DenominatorError();
		}
	}

	return false;
}


//  Smaller than operator overloading

bool Fraction::operator<(Fraction fraction) {
	return (this->numerator * (this->denominator * fraction.getDenominator())) < (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}


// Smaller than or equal operator overloading

bool Fraction::operator<=(Fraction fraction) {
	return (this->numerator * (this->denominator * fraction.getDenominator())) <= (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}


// Bigger than operator overloading

bool Fraction::operator>(Fraction fraction) {
	return (this->numerator * (this->denominator * fraction.getDenominator())) > (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}


// Bigger than or equal operator overloading

bool Fraction::operator>=(Fraction fraction) {
	return (this->numerator * (this->denominator * fraction.getDenominator())) >= (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}


// Equal operator overloading

bool Fraction::operator==(Fraction fraction) {
	return (this->numerator * (this->denominator * fraction.getDenominator())) == (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}


// Non-Equal operator overloading

bool Fraction::operator!=(Fraction fraction) {
	return (this->numerator * (this->denominator * fraction.getDenominator())) != (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}


// Modulos operator overloading (a/b % x/y = (a*y % b*x) / (b*y))




// Double typecast operator overloading

Fraction::operator double() {
	return this->convertFractionToDouble();
}


// Float typecast operator overloading

Fraction::operator float() {
	return (float)this->convertFractionToDouble();
}


// Long typecast operator overloading

Fraction::operator long() {
	return (long)this->convertFractionToDouble();
}


// string typecast operator overloading

Fraction::operator std::string() {
	std::stringstream output;
	output << this->getNumerator() << "/" << this->getDenominator();

	return output.str();
}


// Addition operator overloading

Fraction Fraction::operator+(Fraction fraction) {
	Fraction resultFraction;

	if (this->denominator == fraction.getDenominator()) {
		resultFraction.setNumerator(this->numerator + fraction.getNumerator());
		resultFraction.setDenominator(this->denominator);
	}
	else {
		resultFraction.setNumerator((this->numerator * fraction.getDenominator()) + (fraction.getNumerator() * this->denominator));
		resultFraction.setDenominator(this->denominator * fraction.getDenominator());
	}

	return resultFraction;
}


//Assignment by Sum operator overloading

Fraction Fraction::operator+=(Fraction fraction) {
	if (this->denominator == fraction.getDenominator()) {
		this->numerator += fraction.getNumerator();
	}
	else {
		this->numerator = (this->numerator * fraction.getDenominator()) + (fraction.getNumerator() * this->denominator);
		this->denominator *= fraction.getDenominator();
	}

	return *this;
}


// Subtraction operator overloading

Fraction Fraction::operator-(Fraction fraction) {
	Fraction resultFraction;

	if (this->denominator == fraction.getDenominator()) {
		resultFraction.setNumerator(this->numerator - fraction.getNumerator());
		resultFraction.setDenominator(this->denominator);
	}
	else {
		resultFraction.setNumerator((this->numerator * fraction.getDenominator()) - (fraction.getNumerator() * this->denominator));
		resultFraction.setDenominator(this->denominator * fraction.getDenominator());
	}

	return resultFraction;
}


// Assignment by difference operator overloading

Fraction Fraction::operator-=(Fraction fraction) {
	if (this->denominator == fraction.getDenominator()) {
		this->numerator -= fraction.getNumerator();
	}
	else {
		this->numerator = (this->numerator * fraction.getDenominator()) - (fraction.getNumerator() * this->denominator);
		this->denominator *= fraction.getDenominator();
	}

	return *this;
}


// Multiply operator overloading

Fraction Fraction::operator*(Fraction fraction) {
	Fraction resultFraction;
	resultFraction.setNumerator(this->numerator * fraction.getNumerator());
	resultFraction.setDenominator(this->denominator * fraction.getDenominator());
	return resultFraction;
}


// Multiply Set operator overloading

Fraction Fraction::operator*=(Fraction fraction) {
	this->denominator *= fraction.getDenominator();
	this->numerator *= fraction.getNumerator();
	return *this;
}


// Division operator overloading

Fraction Fraction::operator/(Fraction fraction) {
	if (fraction.getNumerator() == 0) {
		throw zeroFraction();
	}
	Fraction resultFraction;

	resultFraction.setDenominator(this->denominator * fraction.getNumerator());
	resultFraction.setNumerator(this->numerator * fraction.getDenominator());

	return resultFraction;
}


// Division Set operator overloading

Fraction Fraction::operator/=(Fraction fraction) {
	if (fraction.getNumerator() == 0) {
		throw zeroFraction();
	}
	this->denominator *= fraction.getNumerator();
	this->numerator *= fraction.getDenominator();

	return *this;
}



// Increment operator overloading

Fraction Fraction::operator++() {
	this->numerator += this->denominator;

	return *this;
}

Fraction Fraction::operator++(int notused) {
	Fraction tmp = *this;
	this->numerator += this->denominator;
	//++this->numerator;
	return tmp;
}

// Decrement operator overloading

Fraction Fraction::operator--() {
	this->numerator -= this->denominator;

	return *this;
}

Fraction Fraction::operator--(int notused) {
	Fraction tmp = *this;
	this->numerator -= this->denominator;
	//--this->numerator;
	return tmp;
}

Fraction Fraction::operator^(double k) {
	this->numerator = pow(this->numerator, k);
	this->denominator = pow(this->denominator, k);
	return *this;
}

std::ostream& operator<<(std::ostream &out, Fraction &Fraction) {
	out << Fraction.getNumerator() << "/" << Fraction.getDenominator();

	return out;
}

/*
 Right shift operator overloading
 Calls convertStringToFraction function and throws an
 FractionInputFailException object on fail.
 (catchable as a std::exception)
*//*
std::istream& operator>>(std::istream &in, Fraction &Fraction) {
	std::string input;
	in >> input;
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i]) || input[i] != '/') {
			throw isIntDenominator();
			throw isIntNumerator();
		}
	}
	if (false == Fraction.convertStringToFraction(input)) {
		// Throw own exception object
		throw isIntDeterminator();
		throw isIntNumerator();
		//throw FractionInputFailException();
	}
	return in;
}
*/
