// pb_z3_7.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

int find_most_frequent(int a, int b, int c, int d)
{
	int s;
	s = a + b + c + d;
	return (s == 2 ? -1 : (s > 2 ? 1 : 0));
}

int main()
{
	int a, d, c, b;
	cout << ("a,b,c,d=?");
	cin >> a >> b >> c >> d;
	cout << find_most_frequent(a, b, c, d);
}
