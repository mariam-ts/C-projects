// Staque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Staque.h"
using namespace std;
int main()
{
	int numberofNodes;
	Staque s;
	cout << "Check if my staque is constructed. \n" << boolalpha<<s.empty()<< endl;
	
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(9);
	s.push(6);
	s.push(8);
	cout << "display our staque s: \n" << endl;
	s.display(cout);
	cout << "delete one odd and two even number\n" << endl;
	s.pop('o');
	s.pop('e');
	s.pop('e');
	cout << "check if staque is empty" << endl;
	cout << s.empty() << endl;
	cout << "display our staque" << endl;
	s.display(cout);
	cout << "if we pass to pop function nor 'o' neither 'e', we get" << endl;
	s.pop('p');
	
	Staque t;
	cout << "How many elements do you want?" << endl;
	cin >> numberofNodes;
	for (int i = 1; i < numberofNodes; ++i)
	{
		t.push(i * 11);
	}
	
	cout << "display our staque t" << endl;
	t.display(cout);
	
	Staque m;
	m.push(1);
	m.push(3);
	m.push(4);
	m.push(1000);
	m.push(15);
	m.push(17);

	cout << "display Staque m" << endl;
	m.display(cout);
	cout << "remove leave one element" << endl;
	m.pop('e');
	m.pop('e');
	m.pop('o');
	m.pop('o');
	m.pop('o');
	
	cout << "check element" << endl;
	m.display(cout);
	
	


	return 0;

}
    

