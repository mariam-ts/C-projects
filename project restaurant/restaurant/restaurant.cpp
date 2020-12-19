
#include <iostream>
#include "employee.h"
#include "chef.h"
#include "owner.h"
#include "waiter.h"
#include <list>
using namespace std;
int main()
{
	double profit1, tip1;
	cout << "please enter the profit and tip:" << endl;
	cin >> profit1;
	cin >> tip1;
	employee* p;                   
	list<employee*> empList;
	p = new owner(11111, "tsire", "mariami",'o', 15000, profit1, tip1);
	empList.push_back(p);
	p = new chef(22222, "Gordon", "Ramsey", 'c', 10000, "french", profit1, tip1);
	empList.push_back(p);
	p = new chef(22222, "Oliver", "Jamie", 'c', 10000, "Italian", profit1, tip1);
	empList.push_back(p);
	p = new waiter(33333, "Oliver", "Anne", 'w', 3000, profit1, tip1, "1w");
	empList.push_back(p);
	p = new waiter(33333, "Puck", "Marrie", 'w', 3000, profit1, tip1 , "3w");
	empList.push_back(p);
	p = new waiter(33333, "Rayolds", "Nina", 'w', 3000, profit1, tip1, "2w");
	empList.push_back(p);

	for (list<employee*>::iterator it = empList.begin();
		it != empList.end(); it++)
	{
		p = *it;
		cout << *p << endl;
		cout << "total salary" << endl;
		cout << p->Calculate_salary(profit1, tip1) << endl << endl;
	}
	

}


