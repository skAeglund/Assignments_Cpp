#include <iostream>
#include <bitset>
#define SPACES  "						"
using namespace std;

int inputNumber();

int main()
{
	cout << SPACES << "NTH bit of a number\n";
	int number = inputNumber();
	cout << "Enter the bit to check" << endl;
	int bit = inputNumber();
	int bitState = (number >> bit) &1;
	cout << "The " << bit << " bit is set to " << bitState << endl;
	//cout << "Entire bit: " << bitset<sizeof(number)>(number) << endl;
}


int inputNumber()
{
	int number = 0;
	bool success;
	do
	{
		success = true;
		cout << "Enter a number: ";
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			success = false;
		}
	} while (!success);

	return number;
}