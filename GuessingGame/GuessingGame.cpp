#include <iostream>
#include <string>
using namespace std;

const int minNumber = 1;
const int maxNumber = 10;
int inputNumber();

int main()
{
	bool wantsToPlay = true;
	do
	{
		srand(time(NULL));
		int secretNr = rand() % maxNumber + minNumber; // this random function is terrible
		int inputNr = 0, attempts = 0;
		string inputString{};
		char inputChar{};

		cout << "Guess the secret number between " << minNumber << " and " << maxNumber << ": ";
		while (inputNr != secretNr)
		{
			inputNr = inputNumber();
			attempts++;

			if (inputNr != secretNr)
			{
				cout << inputNr << " was not the secret number! Guess again: ";
			}
		}
		cout << "Correct! " << inputNr << " was the secret number. It took you " << attempts 
		     << " attempt" << (attempts > 1 ? "s " : " ") << "to get it right. \nDo you want to play again ? ";

		do
		{
			cout << "Enter Yes or No: ";
			cin >> inputString;
			inputChar = toupper(inputString[0]);
		} while (inputChar != 'Y' && inputChar != 'N'); 

	    wantsToPlay = inputChar == 'Y' ;
	} while (wantsToPlay);

	cout << "\nThank you for playing!" << endl;
}

int inputNumber()
{
	int number = 0;
	do
	{
		cin >> number;
		if (cin.fail() || number < 0 || number > maxNumber)
		{
			cout << "Enter a number between " << minNumber
				 << " and " << maxNumber << ": ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (number <= 0 || number > maxNumber);

	return number;
}