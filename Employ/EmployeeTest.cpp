#include <iostream>
#include "Employee.h"

using std::cout;
using std::endl;

using namespace Records;

//int main()
int test()
{
	// TODO
	cout << "Testing the Employee class." << endl;
	Employee emp;
	emp.setFirstName("jason");
	emp.setLastName("Lin");
	emp.setEmployeeNumber(9906);
	emp.setSalary(6000);
	emp.promote();
	emp.promote(1000);
	emp.hire();
	emp.display();
	getchar();
	return 0;
}