#include <iostream>
#include <type_traits>
#define SPACES "					"
using namespace std;


template <typename T>
T largestNumber(T a, T b)
{
	if (!is_arithmetic_v<T>) // entering something other than a number
	{
		cout << "Error: Invalid type... ";
		return a;
	};
	return a > b ? a : b;
}

int main()
{
	int a, b;
	float f1, f2;
	long long long1, long2;
	cout << SPACES << "Find Largest Number \nEnter integer number A: ";
	cin >> a;
	cout << "Enter integer number B: ";
	cin >> b;
	cout << "Largest integer number = " <<largestNumber(a, b) << endl << endl;

	cout << "Enter floating-point number A: ";
	cin >> f1;
	cout << "Enter floating-point number B: ";
	cin >> f2;
	cout << "Largest floating-point number = " << largestNumber(f1, f2) << endl << endl;

	cout << "Enter long number A: ";
	cin >> long1;
	cout << "Enter long number B: ";
	cin >> long2;
	cout << "Largest long number = " << largestNumber(long1, long2) << endl;

	cout << endl << "Trying to compare strings - ";
	cout << largestNumber("string1", "string2") << endl;
}