#include <string>
#include <iostream>

using namespace std;

class Employee {
	private:
		string name;
		int salary;
	public:
		Employee();
		Employee(string name, int salary);
		void setName(string name);
		string getName();
		void addSalary(int salary);
		void description();
};

Employee::Employee() {
	name = "";
	salary = 0;
};

Employee::Employee(string name, int salary) {
	this->name = name;
	this->salary = salary;
};

void Employee::setName(string name) {
	this->name = name;
};

string Employee::getName() {
	return name;
};

void Employee::addSalary(int salary) {
	this->salary += salary;
};

void Employee::description() {
	cout << "Name: " << name << endl;
	cout << "Salary: " << salary << endl;
};
