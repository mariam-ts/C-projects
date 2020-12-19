#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

#include "platypus.h"
platypus::platypus()                              //create default constructor
	:alive(0),mutant(0), weight(0.0), age(0), name('0'), gender('0')
{
}
platypus:: platypus(char name, char gender, float weight, short age) //create constructor
{
	this->name = name;
	this->age = age;
	this->weight = weight;
	this->gender = gender;
	this->alive = 1;
	this->mutant = 0;
	
}

ostream& operator<<(ostream& out, platypus a)
{
	a.print(out);
	return out;
}
void platypus::print(ostream& out)//create output
{
	cout << "name  " << "age  " << "gender   " << "weight   " << "mutant  "<<"alive  "<< endl;
	out << name << "      " << age << "      " << gender << "       " << weight << "        " <<mutant<<"      "<<alive<< endl;
}
void platypus::age_me()
{
	float deadChance;
	if (this->alive == 1)   // if platypus dead you can't increase age.
	{
		srand(time(NULL));
		this->age = this->age + 1;
		if ((rand() % 100 + 1) <= 2) //2% chance to become mutant
			this->mutant = 1;
		else
			this->mutant = 0;
		deadChance = 10 * weight;//dead chance is ten times platypus weight
		if ((rand() % 100 + 1) <= deadChance)
		{
			this->alive = 0;
		}
		else
		{
			this->alive = 1;
		}
			


	}
}
void platypus::fight(platypus& other)
{
	if (this->alive == 1 && other.alive == 1)
	{
		srand(time(NULL));
		float ratio;
		ratio = (this->weight / other.weight) * 50;
		if ((rand() % 100 + 1) < ratio) //if random number is less then ratio then "other" wins
		{
			other.alive = 1;
			this->alive = 0;
		}
		else
		{
			other.alive = 0;
			this->alive = 1;
		}


	}
}
void platypus ::eat()
{    
	srand(time(NULL));
	if (this->alive == 1)
	{
	   float randomNum;
	   randomNum = (rand() % 50 + 1) / 10;
	   this->weight = this->weight + this->weight * (randomNum / 100);
	}
	
}
void platypus::hatch()
{
	this->alive = 1;
	this->age = 0;
	this->mutant = 0;
	srand(time(NULL));
	if (rand() % 1 == 0)
		this->gender = 'M';
	else
		this->gender = 'F';
	this->weight = (float)(rand() % 10 + 1) / 10;
	this->name = 'a' + rand() % 26;
}

