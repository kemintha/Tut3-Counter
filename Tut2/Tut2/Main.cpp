//Creating a class: Fraction
//Author: K Naidoo, Date: 07/03/2015
#include <iostream>
#include <string>
#include "Fraction.hpp"
using namespace std;

Fraction readFraction()
{
	Fraction input;
	int x, y, z;
	cout << "Please enter a fraction as a mixed number, one part at a time:" << endl << endl;
	cout << "Enter whole number:" << endl;
	cin >> x;
	cout << "Enter numerator:" << endl;
	cin >> y;
	cout << "Enter denominator:" << endl;
	cin >> z;
	input.setn(x * z + y);
	input.setd(z);
	return input;
}

int main()
{
	Fraction x(5, 2); //Values for test variables chosen such that all possible ways to display a number is shown
	Fraction y(1, 4);
	Fraction z;
	//The following tests compare expected answers with those calculated:
	//Function calls replaced by operators:
	cout << "-------" << endl <<  "Test 1: (Compares expected and calculated answers)" << endl << "-------" << endl;
	z = x + y;
	cout << " 5/2 + 1/4 = 2 and 3/4 , add function gives: ";
	z.print();
	z = x - y;
	cout << " 5/2 - 1/4 = 2 and 1/4 , subtract function gives: ";
	z.print();
	z = x * y;
	cout << " 5/2 * 1/4 = 5/8 , multiply function gives: ";
	z.print();
	z = x / y;
	cout << " 5/2 / 1/4 = 10 , divide function gives: ";
	z.print();
	//Test for function to input a fraction:
	cout << endl << "-------" << endl << "Test 2: (Tests acceptance of user input)" << endl << "-------" << endl;
	Fraction frac = readFraction();
	cout << "The fraction you have entered is: ";
	frac.print();
	system("pause");
	return 0;
}