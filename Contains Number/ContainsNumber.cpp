#include <iostream>
#include <string>
#define SPACES "					"
using namespace std;

// is this allowed? doesn't feel like a "hard" exercise
bool containsDigit(int digit, int number)
{
	return to_string(number).find(to_string(digit)) != string::npos;
}
bool containsDigit2(int digit, int number);

int main()
{
	int a, b;
	cout << "Enter a number: ";
	cin >> b;
	cout << "Enter a single digit: ";
	cin >> a;

	cout << b << (containsDigit(a, b) ? " contains" : " does not contain") << " the digit \"" << a << "\"" << endl;

}

// in case the solution above isn't allowed
bool containsDigit2(int digit, int number)
{
	string numberString = to_string(number);
	for (char c : numberString)
	{
		if (c == (char)digit + '0')
			return true;
	}
	return false;
}