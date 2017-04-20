#include <iostream>
#include <stdexcept>
#include "DataBase.h"


namespace Records {

DataBase::DataBase()
	: mNextEmployeeNumber(kFirstEmployeeNumber)
{
}


DataBase::~DataBase()
{
}


Employee& DataBase::addEmployee(const std::string& firstName,
								const std::string& lastName)
{
	// TODO..
	Employee theEmployee;
	theEmployee.setFirstName(firstName);
	theEmployee.setLastName(lastName);
	theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
	theEmployee.hire();
	mEmployee.push_back(theEmployee);
	return mEmployee[mEmployee.size() - 1];
}


Employee& DataBase::getEmployee(int employeeNumber)
{
	for (auto& employee : mEmployee) {
		if (employee.getEmployeeNumber() == employeeNumber) {
			return employee;
		}
	}
	throw std::runtime_error("No employee found.");
}


void DataBase::displayAll() const
{
	for (const auto& employee : mEmployee) {
		employee.display();
	}
}

void DataBase::displayCurrent() const
{
	for (const auto& employee : mEmployee) {
		if (employee.getIsHired()) {
			employee.display();
		}
	}
}

void DataBase::displayFormer() const
{
	for (const auto& employee : mEmployee) {
		if (!employee.getIsHired()) {
			employee.display();
		}
	}
}















}