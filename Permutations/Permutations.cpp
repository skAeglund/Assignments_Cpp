#include <iostream>
#define SPACES "					"
using namespace std;


string swapCharacters(string word, int i, int i2)
{
	char temp = word[i];
	word[i] = word[i2];
	word[i2] = temp;
	return word;
}

void printPermutation(string word, int index = 0)
{
	int length = (int)word.length();
	if (index == length) cout << word << endl;

	for (int i = index; i < length; i++)
	{
		string swapped = swapCharacters(word, i, index);
		printPermutation(swapped, index + 1);
	}
}

int main()
{
	string word;
	cout << SPACES << "Permutations \nEnter a word: ";
	cin >> word;
	printPermutation(word);
}