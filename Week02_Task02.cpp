#include<iostream>
using namespace std;

class Employee
{
public:
	virtual double calculateSalary() = 0;
};

class FullTimeEmployee : public Employee
{
private:
	double fixedSalary;

public:
	FullTimeEmployee(double fxdSalary = 0)
	{
		fixedSalary = fxdSalary;
	}
	double calculateSalary() 
	{
		return fixedSalary;
	}
};

class PartTimeEmployee : public Employee
{
private:
	double hoursWorked;
	double hourlyRate;

public:
	PartTimeEmployee(double hrsWorked = 0, double hrRate = 0)
	{
		hoursWorked = hrsWorked;
		hourlyRate = hrRate;
	}
	double calculateSalary()
	{
		return hoursWorked * hourlyRate;
	}
};

int main()
{
	FullTimeEmployee fe(649.6);
	PartTimeEmployee pe(40, 10.5);

	cout << "Salary of Full Time Employee: $" << fe.calculateSalary() << endl;
	cout << "Salary of Part Time Employee: $" << pe.calculateSalary() << endl;

	return 0;
}