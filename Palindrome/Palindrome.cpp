#include <iostream>
#define SPACES  "						"
using namespace std;

// using iteration
bool isPalindrome(string word)
{
	for (size_t i = 0; i < word.length() /2; i++)
	{
		if (word[i] != word[word.length() - 1 - i])
			return false;
	}
	return true;
}
// using recursion
bool isPalindrome2(string word) 
{
	if (word.length() <= 1) return true;

	if (word[0] == word[word.length() - 1])
	{
		if (isPalindrome2(word.substr(1, word.length() - 2)))
			return true;
	}
	return false;
}
int main()
{
	string inputString;
	cout << SPACES << "Palindrome checker\nEnter a word: ";
	cin >> inputString;
	cout << inputString << " is " << (isPalindrome2(inputString) ? "a" : "not a") << " palindrome" << endl;
}