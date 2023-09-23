#include "Employee.h"

int main(void) {
	Employee e[3] = { 
		Employee("John", 10000), 
		Employee("Mary", 20000), 
		Employee("Bob", 30000) 
	};

	cout << "Before adding salary: \n" << endl;
	for (Employee& emp : e) {
		emp.description();
	}
	for (Employee& emp : e) {
		emp.addSalary(10000);
	}
	cout << "After adding salary: \n" << endl;
	for (Employee& emp : e) {
		emp.description();
	}
}
