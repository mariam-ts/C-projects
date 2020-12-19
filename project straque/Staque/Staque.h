#pragma once
#include <iostream>
#ifndef STAQUE
#define STAQUE
using namespace std;
typedef int Staqueelement;
class Staque
{
public:
	Staque();                        //constructor
	Staque(const Staque& original);  //definition of stack copy constructor
	~Staque();                       //destructor
	const Staque& operator= (const Staque& rightHandSide); //assignment operator
	bool empty()const;                     //check if stack is empty
	void push(const Staqueelement& value);//push odd push even
	void display(ostream& out) const;
	//display stack values
	Staqueelement top() const;           //retreive value at top
	void pop(char i);                          // delete top and end of staque
private:
	class Node
	{
	public:
		Staqueelement data;
		Node* next;
		Node* top;
		Node(Staqueelement value, Node * first = 0, Node* link = 0)
			:data(value), top(first),next(link)
		{}
	};
	typedef Node* NodePtr;
	NodePtr myTop;
	NodePtr myEnd;
};

ostream& operator<<(ostream& out, const Staque& aStaque);

#endif
