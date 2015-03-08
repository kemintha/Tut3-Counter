//Source file for class "Fraction"

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
	else
		d = b;
}
//Definitions for other methods of class: add, sub, mult, div, print:
//Changed to operator overloading:
Fraction Fraction::operator+(Fraction other)
{
	return Fraction(n*other.d + d*other.n, d*other.d);
}
Fraction Fraction::operator-(Fraction other)
{
	return Fraction(n*other.d - d*other.n, d*other.d);
}
Fraction Fraction::operator*(Fraction other)
{
	return Fraction(n*other.n, d*other.d);
}
Fraction Fraction::operator/(Fraction other)
{
	return Fraction(n*other.d, d*other.n);
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
//Displays the fraction as a mixed number
void Fraction::print() 
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