// pb_z6_17.cpp
// Горбацевич Андрей
#include <iostream>
#include <iomanip>
using namespace std;

double inline f(double x) 
{
	return 2 * x*x - 3 * x + 1;
}

void pp1(double x)
{
	cout.width(15);
	cout.fill(' ');
	cout.setf(ios_base::right);
	cout.setf(ios_base::fixed);
	cout << setprecision(3)<<x;
}

void pp2(double x)
{
	cout.width(15);
	cout.fill(' ');
	cout.setf(ios_base::right);
	cout << scientific << setprecision(5) << f(x);
}

int main()
{
	double a, b, s;
	cout << "a, b, s >>>\n"; 
	cin >> a >> b >> s;
	for (double _a = a; _a <= b; _a += s)
	{
		pp1(_a);
	}
	cout << endl;
	for (double _a = a; _a <= b; _a += s)
	{
		pp2(_a);
	}
	cout << endl;
}