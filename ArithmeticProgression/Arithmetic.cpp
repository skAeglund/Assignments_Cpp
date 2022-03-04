#include <iostream>
#include <string>
#define SPACES  "						"
#define SIZE 4
using namespace std;

int inputNumber(int index);
string numbersToString(int numbers[]);

bool arithmeticCheck(int numbers[])
{
	int initialDifference = numbers[1] - numbers[0];
	for (size_t i = 2; i < SIZE; i++)
	{
		if (numbers[i] - numbers[i - 1] != initialDifference)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int numbers[SIZE];
	cout << SPACES <<"Arithmetic Progression\nEnter " << SIZE << " numbers: " << endl;

	for (size_t i = 0; i < SIZE; i++)
	{
		numbers[i] = inputNumber(i +1);
	}

	string message = "\nThe chosen numbers " + numbersToString(numbers) + "are ";
	message += arithmeticCheck(numbers) ? "arithmetic, good job." : "not arithemtic..." ;

	cout << message << endl;
}

string numbersToString(int numbers[])
{
	string numberString;

	for (size_t i = 0; i < SIZE; i++)
	{
		numberString += to_string(numbers[i]) + " ";
	}
	return numberString;
}


int inputNumber(int index)
{
	int number = -1;
	bool successfulInput = false;
	do
	{
		cout << "Number " << index << ": ";
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else 
		{
			successfulInput = true;
		}
	} while (!successfulInput);

	return number;
}