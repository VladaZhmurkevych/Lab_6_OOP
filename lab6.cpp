
#include "pch.h"
#include <iostream>
#include "Fraction.h"
#include "ActionWithFraction.h"
#include "Error.h"
using namespace std;

int main(void) {
	try {
		bool exit = false;
		int choice;
		ActionWithFraction act;
		while (!exit) {

			cout << "1: Finding increment\n"
				<< "2: Finding decrement(x/y)\n"
				<< "3: Add two fractions\n"
				<< "4: Subtract two fractions\n"
				<< "5: Multiply two fractions\n"
				<< "6: Divide two fractions\n"
				<< "7: Compare two fractions\n"
				<< "8: Finding unary minus\n"
				<< "9: Elevation to degree\n"
				<< "10: Exit\n\n"
				<< "> ";
			cin >> choice;
			switch (choice) {
			case 1: {
				act.findingIncrement();
				cout << endl;
				break;
			}
			case 2: {
				act.findingDecrement();
				cout << endl;
				break;
			}
			case 3: {
				act.addFractions();
				cout << endl;
				break;
			}
			case 4: {
				act.subtractFractions();
				cout << endl;
				break;
			}
			case 5: {
				act.multiplyFractions();
				cout << endl;
				break;
			}
			case 6: {
				act.divideFractions();
				cout << endl;
				break;
			}
			case 7: {
				act.compareFractions();
				cout << endl;
				break;
			}
			case 8: {
				act.unaryMinus();
				cout << endl;
				break;
			}
			case 9: {
				act.elevationToDegree();
				cout << endl;
				break;
			}
			case 10: {
				exit = true;
				break;
			}
			default: {
				cout << "Incorrect Input\n";
				cout << endl;
			}
			}
		}

	

	}
	catch (Error &err) {
		err.printError();
	}
return 0;
}

