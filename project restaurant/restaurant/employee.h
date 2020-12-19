#ifndef EMPLOYEE
#define EMPLOYEE

#include <iostream>
#include <string>
using namespace std;

class employee
{
public:
	employee(long employeeID = 0, string last = "", string first = "",
		char employeeType = ' ', double salary = 0, double profit = 0, double tip = 0);
	virtual void display(ostream& out) const;
	double getSalary();
	virtual double Calculate_salary(double profit, double tip) = 0; // every employee has their own salary

private:
	long IDnum;
	string firstName, lastName;
	char employeeT;
	double sal;
	double prof;
	double tp;

};
inline ostream & operator<<(ostream& out, const employee& empl)
{
	empl.display(out);
	return out;
}
inline void employee::display(ostream& out)const
{
	out << IDnum << "    " << lastName << ",     " <<
		firstName << "     " << employeeT << "   $"
		<< sal <<"  $"<< prof << "  $" << tp<<"  ";
}
inline employee::employee(long employeeID, string last, string first, char employeeType, double salary, double profit, double tip)
	: IDnum(employeeID), lastName(last), firstName(first),
	employeeT(employeeType), sal(salary), prof(profit), tp(tip)
{ }
inline double employee::getSalary() //accessor
{
	return sal;
}
#endif
