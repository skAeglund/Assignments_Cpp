#include <iostream>
#include <string>
#define SPACES  "						"
using namespace std;

template<typename T, size_t S>
string findPositions(int number, T (&arr)[S])
{
	string positions{};
	for (int i = 0; i < size(arr); i++)
	{
		if (arr[i] == number)
		{
			positions += positions.length() == 0 ? to_string(i) : ", " + to_string(i);
		}
	}
	return positions;
}
template<typename T, size_t S>
void printArray(T (&arr)[S])
{
	cout << "Collection: ";
	for (size_t i = 0; i < size(arr); i++)
	{
		cout << (i < size(arr) - 1 ? to_string(arr[i]) + ", " : to_string(arr[i]));
	}
	cout << endl << endl;
}
int main()
{
	int arr[]{ 5, 3, 7, 10, 1, 6, 8, 17, 3, 5, 3, 13, 6, 11};
	printArray(arr);
	int numberToFind;
	cout << "Enter a number to search for: ";
	cin >> numberToFind;
	string foundPositions = findPositions(numberToFind, arr);
	cout << numberToFind << (foundPositions.length() > 0 ? 
			" can be found at index: " + foundPositions : " wasn't found...") << endl;
}