#include <iostream>
#define SPACES "					"
using namespace std;

class A
{
private:
	string name;
public:
	A(string name)
	{
		this->name = name;
		cout << name << " is - Inside Base Constructor" << endl;
	}
};

class B : A
{
public:
	B(string name) : A(name)
	{
		cout << name << " is - Inside B Class Constructor" << endl;
	}
};

class C : A
{
public:
	C(string name) : A(name)
	{
		cout << name << " is - Inside C Class Constructor" << endl;
	}
};

int main()
{
	cout << SPACES << "Constructor order in inheritance\n\n";
	A base{ "A-Class" };
	cout << endl;
	B derivedB{ "B-class" };
	cout << endl;
	C derivedC{ "C-class" };
	cout << endl;
}