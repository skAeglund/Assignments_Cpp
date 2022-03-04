#include <iostream>
#include <string>
using namespace std;

int AbsoluteDifference(int a, int b)
{
	return a-b < 0 ? -(a-b) : a-b;
}
int main()
{
	int a, b;
	cout << "Absolute Difference" << endl;
	cout << "Number A: ";
	cin >> a;
	cout << endl << "Number B: ";
	cin >> b;
	cout << "The absolute difference between " << a << " and " << b <<
		    " is " << AbsoluteDifference(a, b) << endl;
}