#include <iostream>
#define SPACES  "						"
using namespace std;

int main()
{
	cout << SPACES << "Reversed Collection\nEnter a word: ";
	string input{};
	cin >> input;
	string reversedString{};

	
	for (size_t i = input.length() -1; i < input.length(); i--)
	{
		reversedString += input[i];
	}
	cout << input << " reversed is: " << reversedString << endl;
}