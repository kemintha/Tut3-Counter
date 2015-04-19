//Source file for class Counter

#include <iostream>
#include <string>
#include "Counter.hpp"

using namespace std;

Counter::Counter() //Constructor, intialises variables to default values specified
{
	start = 0;
	stop = 255;
	incr = 1;
	decr = 1;
}
Counter::~Counter() //Destructor
{
}

void Counter::setStart(int a) //Accessor and mutators
{
	start = a;
}
void Counter::setStop(int a)
{
	stop = a;
}
void Counter::setIincr(int a)
{
	incr = a;
}
void Counter::setDecr(int a)
{
	decr = a;
}
int Counter::getStart()
{
	return start;
}
int Counter::getStop()
{
	return stop;
}
int Counter::getIncr()
{
	return incr;
}
int Counter::getDecr()
{
	return decr;
}



