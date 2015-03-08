#ifndef FRACTION_H
#define FRACTION_H

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
	//Declares member functions of class fraction: (operation functions replaced by operator overloading)
	Fraction operator+(Fraction);
	Fraction operator-(Fraction);
	Fraction operator*(Fraction);
	Fraction operator/(Fraction);
	void print();//Declares function to display fraction variable
	
};

#endif