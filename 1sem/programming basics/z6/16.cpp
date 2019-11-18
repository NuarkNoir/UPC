// pb_z6_16.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

double f(double x) 
{
	return 2 * x*x - 3 * x + 1;
}

void pp(double x)
{
	cout.width(10);
	cout.fill(' ');
	cout.setf(ios_base::fixed);
	cout.setf(ios_base::right);
	cout << x;
	cout.width(15);
	cout.fill(' ');
	cout.setf(ios_base::right);
	cout << scientific << f(x);
	cout << endl;
	cout.unsetf(ios_base::scientific);
}

int main()
{
	double a, b, s;
	cout << "a, b, s >>>\n"; 
	cin >> a >> b >> s;
	while (a <= b)
	{
		pp(a);
		a += s;
	}
}