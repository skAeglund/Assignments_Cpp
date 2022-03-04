#include <iostream>
#include <string>
using namespace std;

double CelciusToFahrenheit(double celcius)
{
	return celcius * 9 / 5 + 32;
}
int main()
{
	double cel;
	cout << "					Celcius to Fahrenheit conversion \n\nCelcius: ";
	cin >> cel;
	printf("%.1f Celcius is %.1f Fahrenheit\n", cel, CelciusToFahrenheit(cel));

}