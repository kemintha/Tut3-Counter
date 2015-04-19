//Header file for class Counter

#pragma once
#ifndef COUNTER_H
#define COUNTER_H
using namespace std;

class Counter
{
private:
	int start;
	int stop;//Value to stop counting at, inclusive
	int incr;
	int decr;
	int current;

public:
	Counter(); //Constructor
	~Counter(); //Destructor

	void setStart(int); //Accessor and mutators
	void setStop(int);
	void setIincr(int);
	void setDecr(int);
	void setCurrent(int);
	int getStart();
	int getStop();
	int getIncr();
	int getDecr();
	int getCurrent();

	Counter operator++(); //Operator overloads
	Counter operator--();


};
#endif