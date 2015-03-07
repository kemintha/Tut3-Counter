//Creating a class: Fraction
//Author: K Naidoo, Date: 07/03/2015
#include <iostream>
using namespace std;


class Fraction
{
private:
	int n, d; //Declares numerator and denominator variables
public:
	Fraction(int, int); //Declares constructor
	Fraction(); //Declares default constructor
	~Fraction(); //Declares destructor
	//Declares accessors:
	int getn();
	int getd();
	//Declares mutators with conditions:
	void setn(int);
	void setd(int);
	Fraction add(Fraction);
	Fraction sub(Fraction);
	Fraction mult(Fraction);
	Fraction div(Fraction);
	void print();
	
};

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
void Fraction::print()
{
	int k = gcd((n%d), d);
	if (n / d >= 1)
	{
		cout << n / d << " and " << (n%d) / k << "/" << d / k << endl;
	}
	else
	{
		cout << (n%d) / k << "/" << d / k << endl;
	}
}

int main()
{
	int gcd(int, int);
	system("pause");
	return 0;
}