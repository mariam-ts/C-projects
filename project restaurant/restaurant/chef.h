#include <iostream>
#include <string>
#include "employee.h"
using namespace std;

#ifndef CHEF
#define CHEF
class chef : public employee
{
public:
	chef(long employeeID =0, string last = "", string first = "",
		char employeeType = ' ', double salary = 10000, string cuisine = "", double profit = 0, double tip = 0);
	virtual void display(ostream& out) const;
	virtual double Calculate_salary(double profit, double tip);
private:
	string cuis;
	double sal = getSalary(); //accessor
};
inline chef::chef
(long employeeID, string last, string first, char employeeType,
	double salary, string cuisine, double profit, double tip)
	:employee(employeeID, last, first, employeeType, salary, profit, tip), cuis(cuisine)
{}
inline void chef::display(ostream& out)const // 
{
	out << "employID " << "last name " << "first name " << "status " << "salary " << "profit " << "tip  " << "cuisine" << endl;
	employee::display(out);
	out << cuis << endl;
}
inline double chef::Calculate_salary(double profit, double tip) // chef has 20% additional salary from the profit
{
	if (profit >= -25000)
		sal = sal + 0.2 * profit;
	else
		sal = 5000;
	return sal;
};

#endif
