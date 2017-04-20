#include <iostream>
#include "DataBase.h"
using std::cout;
using std::endl;

using namespace Records;

// int main()
int testDataBase()
{
	DataBase myDB;
	Employee& emp1 = myDB.addEmployee("Grep", "Wallis");
	emp1.fire();
	Employee& emp2 = myDB.addEmployee("Marc", "Gregoire");
	emp2.setSalary(10000);
	Employee& emp3 = myDB.addEmployee("John", "Doe");
	emp3.setSalary(9000);
	emp3.promote(200);
	cout << "all employees: " << endl << endl;
	myDB.displayAll();
	cout << endl << "current employee: " << endl << endl;
	myDB.displayCurrent();
	cout << endl << "former employee: " << endl << endl;
	myDB.displayFormer();
	getchar();
	return 0;
}