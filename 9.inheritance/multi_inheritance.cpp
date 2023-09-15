#include <iostream>
#include <string>

using namespace std;

class Dad {
	protected:
		string name;
	public:
		Dad(string n) : name(n) {}
		void print() { cout << name << endl; }
		void dad_call_son() { cout << "Son! I'm your dad!" << endl; }
};

class Mom {
	protected:
		string name;
	public:
		Mom(string n) : name(n) {}
		void print() { cout << name << endl; }
		void mom_call_son() { cout << "Son! I'm your mom!" << endl; }
};

class Son: public Dad, public Mom {
	public:
		Son(string n) : Dad(n), Mom(n) {}
};

int main(void) {
	Son son("John");
	son.dad_call_son();
	son.mom_call_son();
	return 0;
}
