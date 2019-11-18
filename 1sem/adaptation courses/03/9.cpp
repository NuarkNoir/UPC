// ac_3_9.cpp
// Горбацевич Андрей
#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

bool in_D(double x, double y)
{
    return ((y >= abs(x)) && (x*x+y*y <= 1));
}

int main()
{
    double x, y;
    cout << "x, y >>>";
    cin >> x >> y;
    double z = (in_D(x, y)? sin(x) : x + 2 * y );
    cout << "z(x,y)= " << z << endl;
}