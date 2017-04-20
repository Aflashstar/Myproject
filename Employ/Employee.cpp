#include <iostream>
#include "Employee.h"

using std::cout;
using std::endl;

namespace Records{


/*
	默认情况：
	新雇员没有名字
	雇员号为－1
	薪水为默认值
	状态为未雇佣
*/
Employee::Employee()
	: mFirstName("")
	, mLastName("")
	, mEmployeeNumber(-1)
	, mSalary(kDefaultStartingSalary)
	, mHired(false)
{
	// TODO..
}


Employee::~Employee()
{
	// TODO..
}


void Employee::promote(int raiseAmount) 
{
	setSalary(getSalary() + raiseAmount);
}

void Employee::demote(int demeritAmount) 
{
	setSalary(getSalary() - demeritAmount);
}


void Employee::setFirstName(const std::string& firstName)
{
	mFirstName = firstName;
}

const std::string& Employee::getFirstName() const
{
	return mFirstName;
}


void Employee::setLastName(const std::string& lastName)
{
	mLastName = lastName;
}

const std::string& Employee::getLastName() const
{
	return mLastName;
}


void Employee::setEmployeeNumber(int employeeNumber)
{
	mEmployeeNumber = employeeNumber;
}

int Employee::getEmployeeNumber() const
{
	return mEmployeeNumber;
}

void Employee::setSalary(int newSalary)
{
	mSalary = newSalary;
}

int Employee::getSalary() const
{
	return mSalary;
}


bool Employee::getIsHired() const
{
	if (mHired) {
		return true;
	} 
	else {
		return false;
	}
}


void Employee::hire()
{
	mHired = true;
}

void Employee::fire()
{
	mHired = false;
}


void Employee::display() const
{
	cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
	cout << "---------------------------------------------" << endl;
	cout << (mHired ? "Current Employee" : "Former Employee") << endl;
	cout << "Employee Number: " <<  getEmployeeNumber() << endl;
	cout << "Salary: $" << getSalary() << endl;
	cout << "isHired? " << (getIsHired() ? "isHired" : "not isHired") << endl;
	cout << endl;
}


























}