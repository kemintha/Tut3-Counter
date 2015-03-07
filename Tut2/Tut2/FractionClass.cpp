//Creating a class: Fraction
//Author: K Naidoo, Date: 07/03/2015
#include <iostream>
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
void Fraction::setn(int a)
{
	if (a < 0)
		return;
	n = a;
}
void Fraction::setd(int b)
{
	if (b <= 0)
		return;
	d = b;
}
//Definitions for other methods of class: add, sub, mult, div, print:
Fraction Fraction::add(Fraction other)
{
	int top = n*other.d + d*other.n;
	int bot = d*other.d;
		return Fraction(top, bot);
}
Fraction Fraction::sub(Fraction other)
{
	int top = n*other.d - d*other.n;
	int bot = d*other.d;
	return Fraction(top, bot);
}
Fraction Fraction::mult(Fraction other)
{
	int top = n*other.n;
	int bot = d*other.d;
	return Fraction(top, bot);
}
Fraction Fraction::div(Fraction other)
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

int main()
{
	int gcd();
	Fraction x(5, 2); //Values for test variables chosen such that all possible ways to print a number is shown
	Fraction y(1, 4);
	Fraction z;
	//The following tests compare expected answers with those calculated:
	z = x.add(y);
	cout << " 5/2 + 1/4 = 2 and 3/4 , add function gives: ";
	z.print();
	z = x.sub(y);
	cout << " 5/2 - 1/4 = 2 and 1/4 , subtract function gives: ";
	z.print();
	z = x.mult(y);
	cout << " 5/2 * 1/4 = 5/8 , multiply function gives: ";
	z.print();
	z = x.div(y);
	cout << " 5/2 / 1/4 = 10 , divide function gives: ";
	z.print();
	system("pause");
	return 0;
}