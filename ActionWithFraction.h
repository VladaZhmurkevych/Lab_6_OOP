#pragma once
#include "Fraction.h"
using namespace std;
class ActionWithFraction
{
public:
	ActionWithFraction() {};
	~ActionWithFraction() {};
	void convertDoubleToFraction(void) {
		Fraction fraction;
		double number;
		fraction.readFraction();
		fraction.convertDoubleToFraction(number);
		cout << fraction;
	}

	void convertFractionToDouble(void) {
		Fraction fraction;
		fraction.readFraction();
		cout << fraction.convertFractionToDouble();
	}

	void addFractions(void) {
		Fraction firstFraction;
		Fraction secondFraction;
		Fraction resultFraction;
		firstFraction.readFraction();
		secondFraction.readFraction();
		resultFraction = firstFraction + secondFraction;

		cout << "\nCalculation: " << firstFraction << " + " << secondFraction << " = " << resultFraction;

		if (true == resultFraction.reduce()) {
			cout << " = " << resultFraction;
		}
	}

	void subtractFractions(void) {
		Fraction firstFraction;
		Fraction secondFraction;
		Fraction resultFraction;
		firstFraction.readFraction();
		secondFraction.readFraction();
		resultFraction = firstFraction - secondFraction;

		cout << "\nCalculation: " << firstFraction << " - " << secondFraction << " = " << resultFraction;

		if (true == resultFraction.reduce()) {
			cout << " = " << resultFraction;
		}
	}

	void findingIncrement() {
		Fraction fraction;
		Fraction secondFraction;
		Fraction thirdFracrion;
		cout << "Enter the fraction (x/y): ";
		fraction.readFraction();
		thirdFracrion = ++fraction;
		cout << "After incrementing: " << thirdFracrion << endl;
		if (true == thirdFracrion.reduce()) {
			cout << " = " << thirdFracrion;
		}

	}

	void findingDecrement() {
		Fraction fraction;
		Fraction secondFraction;
		fraction.readFraction();
		secondFraction = --fraction;
		cout << "After decrementing: " << secondFraction << endl;
		if (true == secondFraction.reduce()) {
			cout << " = " << secondFraction;
		}
	}

	void multiplyFractions(void) {
		Fraction firstFraction;
		Fraction secondFraction;
		Fraction resultFraction;
		firstFraction.readFraction();
		secondFraction.readFraction();
		resultFraction = firstFraction * secondFraction;

		cout << "\nCalculation: " << firstFraction << " * " << secondFraction << " = " << resultFraction;

		if (true == resultFraction.reduce()) {
			cout << " = " << resultFraction;
		}
	}
	void unaryMinus() {
		Fraction fraction;
		Fraction frac;
		Fraction secondFraction;
		frac.setNumerator(0);
		frac.setDenominator(1);
		fraction.readFraction();
		secondFraction = frac - fraction;
		cout << "With unary minus: " << secondFraction;
		if (true == secondFraction.reduce()) {
			cout << " = " << secondFraction;
		}
	}

	void divideFractions(void) {
		Fraction firstFraction;
		Fraction secondFraction;
		Fraction resultFraction;
		firstFraction.readFraction();
		secondFraction.readFraction();
	
		resultFraction = firstFraction / secondFraction;
		cout << "\nCalculation: " << firstFraction << " / " << secondFraction << " = " << resultFraction;
		if (true == resultFraction.reduce()) {
			cout << " = " << resultFraction;
		}
	}

	void compareFractions(void) {
		Fraction firstFraction;
		Fraction secondFraction;
		firstFraction.readFraction();
		secondFraction.readFraction();
		if (firstFraction < secondFraction) {
			cout << "\nComparison: " << firstFraction << "  < " << secondFraction;
		}

		if (firstFraction > secondFraction) {
			cout << "\nComparison: " << firstFraction << "  > " << secondFraction;
		}

		if (firstFraction <= secondFraction) {
			cout << "\nComparison: " << firstFraction << " <= " << secondFraction;
		}

		if (firstFraction >= secondFraction) {
			cout << "\nComparison: " << firstFraction << " >= " << secondFraction;
		}

		if (firstFraction == secondFraction) {
			cout << "\nComparison: " << firstFraction << " == " << secondFraction;

		}

		if (firstFraction != secondFraction) {
			cout << "\nComparison: " << firstFraction << " != " << secondFraction;
		}
	}

	void complementOfFraction(void) {
		Fraction fraction;
		fraction.readFraction();
		fraction = ~fraction;
		cout << "\nComplement: " << fraction;
		cout << endl;
	}

	void elevationToDegree() {
		Fraction fraction;

		fraction.readFraction();
		cout << "Enter the number of degree (x/y): " << endl;
		Fraction degreeFrag;
		degreeFrag.readFraction();
		double degree;
		degree = degreeFrag.convertFractionToDouble();
		fraction = fraction ^ degree;
		cout << "\nElevation to degree: " << fraction;
		if (true == fraction.reduce()) {
			cout << " = " << fraction;
		}
	}
};

