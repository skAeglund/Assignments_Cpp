#include <iostream>
#include <string>
#include <vector>
#define SPACES "					"
using namespace std;

bool isLuckyNumber(int number)
{
	vector<char> digits;
	string nrString = to_string(number);
	for (size_t i = 0; i < nrString.length(); i++)
	{
		if (count(digits.begin(), digits.end(), nrString[i]) == 0)
		{
			digits.push_back(nrString[i]);
		}
		else 
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cout << "(-1 to quit)			" << "Lucky Number" << endl;
	int number{};
	while (number != -1)
	{
		cout << "Enter a number: ";
		cin >> number;
		if (number == -1) break;
		cout << number << (isLuckyNumber(number) ? " is a lucky number!" : " is not a lucky number...") << endl << endl;
	}
}