#include <iostream>
#include <new>
#include "Staque.h"
using namespace std;
Staque::Staque()
	:myTop(NULL), myEnd(NULL)
{};
ostream& operator<<(ostream& out, const Staque& aStaque) {
	aStaque.display(out);
	return out;
};
Staque::Staque(const Staque& original)
{
	myTop = NULL; myEnd = NULL;
	if (!original.empty())
	{
		myTop = new Node(original.top());
		Staque::NodePtr lastPtr = myTop,
			origPtr = original.myTop->next;
		while (origPtr != 0)
		{
			lastPtr->next = new Staque::Node(origPtr->data, NULL, lastPtr);
			lastPtr = lastPtr->next;
			origPtr = origPtr->next;

		}
		myEnd = lastPtr;
	}
}
Staque::~Staque()
{
	Staque::NodePtr currPtr = myTop,
		nextPtr;
	while (currPtr != 0)
	{
		nextPtr = currPtr->next;
		delete currPtr;
		currPtr = nextPtr;
	}
	delete myEnd;
	delete myTop;
}

const Staque& Staque :: operator=(const Staque& rightHandSide)
{
	if (this != &rightHandSide)
	{
		this->~Staque();
		if (rightHandSide.empty())
			myTop = 0;
		else
		{
			myTop = new Staque::Node(rightHandSide.top());
			Staque::NodePtr lastPtr = myTop,
				rhsPtr = rightHandSide.myTop->next;
			while (rhsPtr != 0)
			{
				lastPtr->next = new Staque::Node(rhsPtr->data, NULL, lastPtr);
				lastPtr = lastPtr->next;
				rhsPtr = rhsPtr->next;

			}
			myEnd = lastPtr;
		}
	}
	return *this;
}

bool Staque::empty() const
{
	return(myTop == 0);
}
void Staque::push(const Staqueelement& value)
{

	if (!empty()) {
		if (value % 2 == 0)
		{

			myTop->top = new Staque::Node(value, NULL, myTop);
			myTop = myTop->top;
		}

		else
		{
			myEnd->next = new Staque::Node(value, myEnd, NULL);
			myEnd = myEnd->next;
		}
	}

	else
	{

		myTop = myEnd = new Staque::Node(value, NULL, NULL);

	}
}
void Staque::display(ostream& out) const
{
	Staque::NodePtr ptr;
	if (!empty()) {
		for (ptr = myTop; ptr != 0; ptr = ptr->next)
			out << ptr->data << endl;
	}
	else
	{
		cerr << "staque is empty\n";
	}
}


Staqueelement Staque::top()const
{
	if (!empty())
		return (myTop->data);
	else
	{
		cerr << "staque is empty ";
		return 0;


	}
}
void Staque::pop(char i) 
{	
	if (!empty())
	{
		if (myTop->next == NULL)
		{
			delete myTop;
			myTop = NULL;
			cout << "the staque is empty" << endl;
		}
		else if (i == 'e')
		{
			Staque::NodePtr ptr = myTop;
			myTop = myTop->next;
			delete ptr;

		}
		else if(i == 'o')
		{
			Staque::NodePtr ptr1 = myTop;
			while (ptr1->next->next != NULL)
			{
				ptr1 = ptr1->next;
			}
			delete ptr1->next;
			ptr1->next = NULL;
		}
		else
		{
			cout << "you should press 'o' for odd removal and 'e' for even removal" << endl;
		}
	}
	else
	{
		cout << "Empty list" << endl;
	}
}