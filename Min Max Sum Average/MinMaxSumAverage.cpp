#include <iostream>
#include <string>
#define SPACES  "						"
#define SIZE 5
using namespace std;

template<typename T, std::size_t S>
void minMaxSumAverage(T(&arr)[S], int& sum, int& min, int& max, int& average)
{
	min = INT_MAX, max = INT_MIN;
	for (int number : arr)
	{
		sum += number;
		if (number < min)
		{
			min = number;
		}
		if (number > max)
		{
			max = number;
		}
	}
	average = sum / size(arr);
}
#pragma region print
template<typename T, std::size_t S>
void printArray(T(&arr)[S])
{
	cout << "Collection: ";
	for (size_t i = 0; i < size(arr); i++)
	{
		cout << (i < size(arr) - 1 ? to_string(arr[i]) + ", " : to_string(arr[i]));
	}
	cout << endl << endl;
}
#pragma endregion
#pragma region Input
int inputNumber(int index)
{
	int number;
	bool successfulInput = false;
	do
	{
		cout << "Number " << index << ": ";
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			successfulInput = true;
		}
	} while (!successfulInput);

	return number;
}
#pragma endregion

int main()
{
	int arr[SIZE];
	int sum{}, min{}, max{}, average{};
	cout << SPACES << "Min Max Sum Average\nEnter "<< SIZE << " numbers:" << endl;
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = inputNumber(i + 1);
	}

	printArray(arr);
	minMaxSumAverage(arr, sum, min, max, average);
	printf("Sum = %i, Minimum number = %i, Highest number = %i, Average = %i\n", sum, min, max, average);

}


