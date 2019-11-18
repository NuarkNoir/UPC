// pb_z3_8.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
using namespace std;

float inline sqr(float i) 
{
	return i * i;
}

float dist(float x1, float y1, float x2, float y2)
{
	float d = sqrt(sqr(x2 - x1) + sqr(y2 - y1));
	return d;
}

int main()
{
	float x1, y1, x2, y2;
	cout << "x1,y1,x2,y2\n";
	cin >> x1>> y1 >> x2 >> y2;
	cout << dist(x1, y1, x2, y2);
}