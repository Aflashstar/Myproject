#pragma once

/*
	// TODO..

*/

#include <vector>
#include "Employee.h"


namespace Records {

const int kFirstEmployeeNumber = 1000;

class DataBase
{
public:
	DataBase();
	~DataBase();


	Employee& addEmployee(const std::string& firstName,
						 const std::string& lastName);
	Employee& getEmployee(const int employeeNumber);
	Employee& getEmployee(const std::string& firstName,
						  const std::string& lastName);


	void displayAll() const;
	void displayCurrent() const;
	void displayFormer() const;


private:
	std::vector<Employee> mEmployee;
	int mNextEmployeeNumber;

};

















}