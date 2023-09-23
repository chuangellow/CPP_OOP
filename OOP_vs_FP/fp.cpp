#include <string>
#include <iostream>

using namespace std;

int* addSalary(int* salary, int size, int amount) {
	int* newSalary = new int[size];
	for (int i = 0; i < size; i++) {
		newSalary[i] = salary[i] + amount;
	}
	return newSalary;
}

int main(void) {
	string employeeName[3] = {"John", "Mary", "Jason"};
	int employeeSalary[3] = {3000, 4000, 5000};
	cout << "Before addSalary" << endl;
	for (int i = 0; i < 3; i++) {
		cout << employeeName[i] << " " << employeeSalary[i] << endl;
	}
	int *happierEmployeeSalary = addSalary(employeeSalary, 3, 1000);
	cout << "After addSalary" << endl;
	for (int i = 0; i < 3; i++) {
		cout << employeeName[i] << " " << happierEmployeeSalary[i] << endl;
	}
	return 0;
}
