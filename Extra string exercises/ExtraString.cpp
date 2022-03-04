#include <iostream>
#include <vector>
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzåäöABCDEFGHIJKLMNOPQRSTUVWXYZÅÖÄ01234567890_."
using namespace std;

string upperCased(string str)
{
	for (char& c : str) c = toupper(c);
	return str;
}
string lowerCased(string str)
{
	for (char& c : str) c = tolower(c);
	return str;
}
string switchCase(string str)
{
	for (char& c : str)
	{
		c = isupper(c) ? tolower(c) : toupper(c);
	}
	return str;
}
bool isEmailValidated(string str)
{
	if (count(str.begin(), str.end(), '@') != 1) return false;
	int atIndex = str.find('@');
	string firstPart = str.substr(0, atIndex);
	string lastPart = str.substr(atIndex + 1);

	// check for any unallowed characters in first part
	if (firstPart.find_first_not_of(ALLOWED_CHARACTERS) != string::npos) return false;

	// the first and last letter of last part needs to be letters
	if (!isalpha(lastPart[0]) || !isalpha(lastPart[lastPart.size() - 1])) return false;

	// last part needs to contain a dot
	if (lastPart.find('.') == string::npos) return false;

	// looks for a dot and checks if the dot is surrounded by text characters
	for (size_t i = 0; i < lastPart.size(); i++)
	{
		if (lastPart[i] == '.')
		{
			if (isalpha(lastPart[i - 1]) && isalpha(lastPart[i + 1]))
				break;
		}
		else if (i == lastPart.size() - 1)
		{
			return false; // reached the end without finding '.' surrounded with text
		}
	}
	return true;
	cout << "first part: " << firstPart << endl <<  "Last part: " << lastPart << endl;
}
int main()
{
	vector<string> emails{
		"coolguy98@hotmail.com", // true
		"retardhotmail.com",	 // false
		"abc@hotmailcom.",		 // false
		"retarded94@hotmailcom", // false
		"%%&#%@hotmail.com",	 // false
		"anders.hagglund@hotmail.com", // true
		"|o|@failmail.com",		 // false
		"this_should@betrueco.m" // true
	};
	for (string email : emails)
	{
		cout << email + " " << (isEmailValidated(email) == 1 ? "True" : "False") << endl;
	}

	return 0;
	string str{ "I'm rEtARDed PLS hALP" };

	cout << "Original: " << str << endl << endl;
	cout << "Upper: " << upperCased(str) << endl;
	cout << "Lower: " << lowerCased(str) << endl;
	cout << "opposite case: " << switchCase(str) << endl;
}