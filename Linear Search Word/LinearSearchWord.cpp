#include <iostream>
#include <string>
#define SPACES "					"
using namespace std;

bool containsWord(string sentence, string word)
{
	size_t matchingCount{};
	for (size_t i = 0; i < sentence.length(); i++)
	{
		if (sentence[i] == word[matchingCount])
		{
			matchingCount++;
		}
		else if (matchingCount >= word.length())
		{
			return true;
		}
		else
		{
			matchingCount = 0;
		}
	}
	return matchingCount >= word.length();
}

int main()
{
	string sentence, word;
	cout << SPACES << "Linear Search Word" << endl << endl;
	cout << "Enter a sentence: ";
	getline(cin, sentence);
	cout << "Enter a word to search for: ";
	cin >> word;
	cout << "The sentence " << (containsWord(sentence, word) ? "contains " : "does not contain ")
		<< "the word \"" << word << "\"" << endl;
	
}