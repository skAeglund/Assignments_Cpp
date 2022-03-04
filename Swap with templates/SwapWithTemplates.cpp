#include <iostream>
#include <type_traits>
#define SPACES "					"
using namespace std;

template <typename T>
void swapThese(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
template <typename int>
void swapThese (int& a, int& b)
{
	// "using only mathematics" - but I don't see the point of the template this way?
	a = a + b;
	b = a - b;
	a = a - b;
};

int main()
{
	int a, b;
	string strA, strB;
	cout << SPACES << "Swap With Template\nEnter number A: ";
	cin >> a;
	cout << "Enter number B: ";
	cin >> b;
	swapThese(a,b);
	cout << "Swapped A: " << a << endl << "Swapped B: " << b << endl;

	cout << endl << "Enter word A: ";
	cin >> strA;
	cout << "Enter word B: ";
	cin >> strB;
	swapThese(strA, strB);
	cout << "Swapped A: " << strA << endl << "Swapped B: " << strB << endl;

}