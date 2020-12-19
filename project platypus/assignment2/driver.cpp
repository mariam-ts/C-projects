// assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "platypus.h"

using namespace std;

int main()
{
	platypus p1('m', 'F', 1.4, 5); //create platypus1
	cout << "platypus1" << endl;
	p1.print(cout);
	platypus p2;//create default platypus2
	cout << "platypus2" << endl;
	p2.print(cout);
	cout << "hatch platypus2" << endl;
	p2.hatch(); //hatch platypus2
	p2.print(cout);
	p2.age_me();
	p2.eat();
	cout << "fight results:" << endl;
	p1.fight(p2);//fight platypus1 and platypus2
	cout << "platypus1" << endl;
	p1.print(cout);
	cout << "platypus2" << endl;
	p2.print(cout);

	//you can increase age and feed alive platypus but not dead one
	cout << "increase age and feed platypus1:" << endl;
	cout << "platypus1"<<endl;
	p1.age_me();
	p1.eat();     
	p1.print(cout);
	cout << "increase age and feed platypus2:" << endl;
	cout << "platypus2" << endl;
	p2.age_me(); 
	p2.eat();
	p2.print(cout);

	cout << "fight each other dead platypus and alive one" << endl;
	p1.fight(p2); // you can't fight each other if one is dead platypus.
	p1.print(cout);
	p2.print(cout);


	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
