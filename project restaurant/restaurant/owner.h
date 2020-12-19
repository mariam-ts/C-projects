#include <iostream>
#include "employee.h"
#include <string>
using namespace std;

#ifndef OWNER
#define OWNER
class owner : public employee
{
public:
	owner(long employeeID = 0, string last = "", string first = "",
		char employeeType = ' ', double salary = 15000, double profit = 0, double tip = 0);
	virtual void display(ostream& out) const;
	virtual double Calculate_salary(double profit, double tip);
private:
	double sal = getSalary(); // accessor
};
inline owner::owner
(long employeeID, string last, string first, char employeeType,
	double salary, double profit, double tip)
	:employee(employeeID, last, first, employeeType, salary, profit, tip)
{}
inline void owner::display(ostream& out)const
{
	out << "employID " << "last name " << "first name " << "status " << "salary " << "profit " << "tip" << endl;
	employee::display(out);
	out << endl;
}
inline double owner::Calculate_salary(double profit, double tip)  // owner has 60 % of the profit as the additional slary 
{
	if (profit >= -25000)
		sal = sal + 0.6 * profit;
	else
		sal = 0;
	return sal;
};

#endif


