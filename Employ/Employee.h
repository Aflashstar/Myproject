#pragma once
/*



*/


#include <string>

// �Խ��������ռ�
namespace Records{
	

// �¹�Ա��Ĭ����н
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
	void display() const;  // const��ʾ�ú�������������ݳ�Ա�����޸�

	// Getters and Setters
	void setFirstName(const std::string& firstName);
	const std::string& getFirstName() const;  // ǰconst ������ֻ�ܵ���const��Ա����

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