#include <iostream>
#include <stdexcept>
#include "DataBase.h"

using std::cout;
using std::endl;

using namespace Records;


int displayMenu();
void doHire(DataBase& db);
void doFire(DataBase& db);
void doPromote(DataBase& db);
void doDemote(DataBase& db);

int main()
{
	// TODO..
	DataBase employeeDB;
	bool done = false;
	while (!done) {
		int selection = displayMenu();
		switch (selection) {
			case 1:
				doHire(employeeDB);
				break;
			case 2:
				doFire(employeeDB);
				break;
			case 3:
				doPromote(employeeDB);
				break;
			case 4:
				doDemote(employeeDB);
				break;
			case 5:
				employeeDB.displayAll();
				break;
			case 6:
				employeeDB.displayCurrent();
				break;
			case 7:
				employeeDB.displayFormer();
				break;
			case 0:
				done = true;
				break;
			default:
				std::cerr << "Unkonw command." <<endl;
				break;
		}
	}
	getchar();
	return 0;
}

int displayMenu()
{
	int selection;
	cout << endl;
	cout << "employee DataBase" << endl;
	cout << "-----------------" << endl;
	cout << "1) Hire a new employee" << endl;
	cout << "2) Fire an employee" << endl;
	cout << "3) Promote an employee" << endl;
	cout << "4) Demote an employee" << endl;
	cout << "5) List all employee" << endl;
	cout << "6) List current employee" << endl;
	cout << "7) List former employee" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "--->";
	std::cin >> selection;
	return selection;
}

void doHire(DataBase& db)
{
	std::string firstName;
	std::string lastName;
	cout << "First name? ";
	std::cin >> firstName;
	cout << "Last name? ";
	std::cin >> lastName;
	try{
		db.addEmployee(firstName,lastName);
	} catch (const std::exception& exception) {
		std::cerr << "Unable to add new employee: " << exception.what() << endl;
	}
}

void doFire(DataBase& db)
{
	int employeeNumber;
	cout << "Employee number? ";
	std::cin >> employeeNumber;
	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.fire();
		cout << "Employee " << employeeNumber << "terminated." << endl;
	} catch (const std::exception& exception) {
		std::cerr << "Unable to terminate employee: " << exception.what() << endl;
	}
}

void doPromote(DataBase& db)
{
	int employeeNumber;
	int raiseAmount;
	cout << "Employee number? ";
	std::cin >> employeeNumber;
	cout << "How much of a raise? ";
	std::cin >> raiseAmount;
	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
	} catch (const std::exception& exception) {
		std::cerr << "Unable to promote employee: " << exception.what() << endl;
	}
}

void doDemote(DataBase& db)
{
	int employeeNumber;
	int demeritAmount;
	cout << "Employee number? ";
	std::cin >> employeeNumber;
	cout << "How much of a demerit? ";
	std::cin >> demeritAmount;
	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.demote(demeritAmount);
	} catch (const std::exception& exception) {
		std::cerr << "Unable to demote employee: " << exception.what() << endl;
	}
}




























