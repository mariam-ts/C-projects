#include <iostream>
#include <string>
#include "employee.h"
using namespace std;

#ifndef WAITER
#define WAITER
class waiter : public employee
{
public:
	waiter(long employeeID = 0, string last = "", string first = "",
		char employeeType = ' ', double salary = 3000, double profit = 0, double tip = 0, string experience = "");
	virtual void display(ostream& out) const;
	virtual double Calculate_salary(double profit, double tip);
private:
	string experience;
	double sal = getSalary(); //accessor
};
inline waiter::waiter
(long employeeID, string last, string first, char employeeType,
	double salary,  double profit, double tip, string experience)
	:employee(employeeID, last, first, employeeType, salary, profit, tip), experience(experience)
{}
inline void waiter::display(ostream& out)const
{
	out << "employID " << "last name " << "first name " << "status " << "salary " << "profit " << "tip " <<"experience" << endl;
	employee::display(out);
	out << experience << endl;
}
inline double waiter::Calculate_salary(double profit, double tip) // waiter only have tip as additional salary
{
	sal = sal + tip;
	return sal;
};

#endif

