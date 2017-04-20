#pragma once
/*



*/


#include <string>

// 自建的命名空间
namespace Records{
	

// 新雇员的默认起薪
const int kDefaultStartingSalary = 5000;


class Employee
{
public:
	Employee();
	~Employee();

	void promote(int raiseAmount = 500);
	void demote(int demeritAmount = 200);
	void hire();
	void fire();
	void display() const;  // const表示该函数不对类的数据成员进行修改

	// Getters and Setters
	void setFirstName(const std::string& firstName);
	const std::string& getFirstName() const;  // 前const 常对象只能调用const成员函数

	void setLastName(const std::string& lastName);
	const std::string& getLastName() const;

	void setEmployeeNumber(int employeeNumber);
	int getEmployeeNumber() const;

	void setSalary(int newSalary);
	int getSalary() const;

	bool getIsHired() const;


private:
	float version = 0.0;
	std::string mFirstName;
	std::string mLastName;
	int mEmployeeNumber;
	int mSalary;
	bool mHired;
};















}