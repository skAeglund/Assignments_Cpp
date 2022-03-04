#include <iostream>
#include <map>
#include <string>
#define SPACES "					"
using namespace std;

string toUpper(string str)
{
	for (char& c : str)
		c = toupper(c);
	return str;
}
map<char, int> updateCharacterMap(string text, map<char, int>& mapOfChars)
{
	text = toUpper(text);
	for (char c : text)
	{
		if (c == ' ') continue;
		mapOfChars[c]++;
	}
	return mapOfChars;
}

#pragma region Print
void printCharacters(map<char, int>& mapOfChars)
{
	map<char, int>::iterator iterator = mapOfChars.begin();
	while (iterator != mapOfChars.end())
	{
		cout << iterator->first << " = " << iterator->second << endl;
		iterator++;
	}
}
#pragma endregion

int main()
{
	string inputString;
	map<char, int> mapOfChars;
	cout << SPACES << "Occurences of characters in a string" << endl;
	cout << "Enter a text to scan: ";
	getline(cin, inputString);

	updateCharacterMap(inputString, mapOfChars);
	printCharacters(mapOfChars);
}