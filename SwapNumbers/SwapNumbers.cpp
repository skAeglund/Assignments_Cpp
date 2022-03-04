#include <iostream>
#include <tuple>
using namespace std;

void RefSwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void PointSwap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void MathSwap(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
void TupleMathSwap(int& a, int& b)
{
	tie(a, b) = make_tuple(-(a - (a + b)), -(b - (a + b)));
}

int main()
{
	int a, b;
	cout << "Number A: ";
	cin >> a;
	cout << endl << "Number B: ";
	cin >> b;
	RefSwap(a, b);
	//PointSwap(&a, &b);
	//MathSwap(a,b);
	//TupleMathSwap(a, b);
	cout << endl << "Swapped values: \nNumber A: " << a << "\nNumber B: " << b;
}