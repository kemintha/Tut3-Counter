//Creating a class: Fraction
//Author: K Naidoo, Date: 07/03/2015
#include <iostream>
#include <string>
#include "Fraction.hpp"
using namespace std;

Fraction::Fraction(int a, int b) //Defines constructor
{
	n = a;
	d = b;
}

Fraction::Fraction() //Defines default constructor to a fraction of 0/1
{
	n = 0;
	d = 1;
}
Fraction::~Fraction() //Defines destructor
{
}
//Defines accessors:
int Fraction::getn() { return n; }
int Fraction::getd() { return d; }
//Defines mutators:
void Fraction::setn(int a) //Doesnt allow a negative value for numerator
{
	if (a < 0)
		return;
	n = a;
}
void Fraction::setd(int b) //Doesnt allow a negative or zero value for denominator
{
	if (b <= 0)
		return;
	d = b;
}
//Definitions for other methods of class: add, sub, mult, div, print:
//Changed to operator overloading:
Fraction Fraction::operator+(Fraction other)
{
	int top = n*other.d + d*other.n;
	int bot = d*other.d;
		return Fraction(top, bot);
}
Fraction Fraction::operator-(Fraction other)
{
	int top = n*other.d - d*other.n;
	int bot = d*other.d;
	return Fraction(top, bot);
}
Fraction Fraction::operator*(Fraction other)
{
	int top = n*other.n;
	int bot = d*other.d;
	return Fraction(top, bot);
}
Fraction Fraction::operator/(Fraction other)
{
	int top = n*other.d;
	int bot = d*other.n;
	return Fraction(top, bot);
}
int gcd(int a, int b) //Euclidean subtraction based method to find greatest common divisor of numerator and divisor
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
void Fraction::print() //Displays the fraction as a mixed number
{
	if (n % d == 0) //Displays as a whole number if no remainder
	{
		cout << n / d << endl;
	}
	else
	{
		int k = gcd((n%d), d); //Displays as a whole number and fraction if greater than 1
		if (n / d >= 1)
		{
			cout << n / d << " and " << (n%d) / k << "/" << d / k << endl;
		}
		else //Displays as only a fraction if less than 1
		{
			cout << (n%d) / k << "/" << d / k << endl;
		}
	}
}
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
	int gcd();
	Fraction x(5, 2); //Values for test variables chosen such that all possible ways to print a number is shown
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