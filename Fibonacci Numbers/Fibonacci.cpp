#include <iostream>
#include <tuple>
#define SPACES "					"
using namespace std;

void iterativeFibonacci(int count)
{
	tuple<int, int> prevTwo{}; // previous two numbers

	for (int i = 0; i < count; i++)
	{
		int sum = i > 1 ? get<0>(prevTwo) + get<1>(prevTwo) : i; // sum rule doesn't apply for case 0 & 1
		prevTwo = tie(get<1>(prevTwo), sum);
		cout << sum << (i < count -1 ? ", " : "");
	}
}
// is there a way to solve this without index (i) ?
void recursiveFibonacci(int count, int i = 0, tuple<int, int> prevTwo = { 0,0 })
{
	if (i == count) return;
	int sum = i > 1 ? get<0>(prevTwo) + get<1>(prevTwo) : i;
	cout << sum << ( i < count -1 ? ", " : "");
	recursiveFibonacci(count, ++i, tie(get<1>(prevTwo), sum));
}
int main()
{
	int length;
	cout << SPACES << "Fibonacci Numbers\nEnter length: ";
	cin >> length;
	recursiveFibonacci(length);
	cout << endl;
}