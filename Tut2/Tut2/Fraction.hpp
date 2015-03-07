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
	Fraction add(Fraction);
	Fraction sub(Fraction);
	Fraction mult(Fraction);
	Fraction div(Fraction);
	void print();
};

#endif