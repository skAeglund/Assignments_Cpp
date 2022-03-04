#include <iostream>
#include <string>
#define SPACES "					"
using namespace std;

int getFullNumber(string str);

void compress(string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		int count{ 1 }; // repetitions of each character
		for (size_t j = i + 1; j <= str.length(); j++)
		{
			if (str[j] == str[i])
			{
				count++;
			}
			else
			{
				if (count > 1)
				{
					str.replace(i + 1, count - 1, to_string(count));
					i++; // to avoid the digit next loop
				}
				break;
			}
		}
	}
}

void decompress(string& str)
{
	for (size_t i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i])) continue;

		size_t charCount = getFullNumber(str.substr(i)) -1;
		int length = to_string(charCount).length();
		str.replace(i, length, charCount, str[i - 1]);
		i += charCount;
	}
}

int main()
{
	string inputString;
	cout << SPACES << "Compress String \nEnter a string: ";
	cin >> inputString;
	compress(inputString);
	cout << "Compressed string: " << inputString << endl;
	decompress(inputString);
	cout << "Decompressed string: " << inputString << endl;
}




int getFullNumber(string str) // in case of 2+ digit numbers
{
	int count{};
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			count++;
		else
			break;
	}
	return stoi(str.substr(0, count));
}