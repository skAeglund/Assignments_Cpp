#include <iostream>
#include <string>
#include <tuple>
using namespace std;


string EvenOrOdd(long number)
{
	return to_string(number) + " is an " + (string)(number % 2 == 0 ? "even" : "odd") + " number";
}

int LastDigit(int number)
{
	string nrString = to_string(number);
	return nrString[nrString.length()-1] - '0'; // - '0' to get the actual number instead of char value
}
int LastDigit2(int number)
{
	return (((float)number) * 0.1f - floor(((float)number) * 0.1f)) * 10;
}
void PrintNumberSeperated(int number)
{
	string nrString = to_string(number);
	for (int i = 0; i < nrString.length(); i++)
	{
		cout << nrString[i] << " ";
	}
}
void PrintNumberReversed(int number)
{
	string nrString = to_string(number);
	for (int i = nrString.length() -1; i >= 0; i--)
	{
		cout << nrString[i] << " ";
	}
}

int main()
{
	int number = 12343;
	PrintNumberSeperated(number);
	cout << endl;
	PrintNumberReversed(number);
	cout << endl << EvenOrOdd(3) << "\n" << EvenOrOdd(6) << endl;
	cout << "Last digit of "<< number << " is: " << LastDigit(number) << endl;
}

