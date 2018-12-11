#pragma once
#include <iostream>
using namespace std;

class Error
{
public:
	virtual void printError() {
		cout << "Error! " << endl;
	}
};

class DenominatorError : public Error {
public:
	//DenominatorError();
	virtual void printError() {
		Error::printError();
		cout << "Denominator can not be equal to 0" << endl;
	}
};

class zeroFraction : public Error {
public:
	virtual void printError()
	{
		Error::printError();
		cout << "Fraction in denominator can not be equal to 0" << endl;
	}
};

class isIntDenominator : public Error {
public:
	virtual void printError()
	{
		Error::printError();
		cout << "Number in denominator must be integer" << endl;
	}
};

class isIntNumerator : public Error {
public:
	virtual void printError()
	{
		Error::printError();
		cout << "Number in numerator must be integer" << endl;
	}
};
