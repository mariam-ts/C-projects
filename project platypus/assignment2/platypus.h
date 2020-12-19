#pragma once
#include <iostream>
#include <string>
#include <ctime>


#ifndef PLATYPUS
#define PLATYPUS
using namespace std;

class platypus
{
private:
	// data members
	float weight;
	short age;
	char name;
	char gender;
	bool alive;
	bool mutant;
public:
	//constructors
	platypus();
	platypus(char name, char gender, float weight, short age);
	//mutators
	void age_me();
	void fight(platypus & other);
	void eat();
	void hatch();
	//output
	void print(ostream & out);

};
ostream& operator<<(ostream& out, platypus a);
#endif // !PLATYPUS

