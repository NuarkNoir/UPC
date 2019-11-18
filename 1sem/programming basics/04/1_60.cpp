// pb_4_1_60.cpp
// Горбацевич Андрей
#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double f1(double x)
{
    x = x + 3.14;
    return x;
}
double f2(double x)
{
    x = sqrt(x*x + 2);
    return x;
}
int main()
{
    double x;
    cout << "X=?\n";
    cin >> x;
    cout << "y=" << f1(x) + f1(x*x) + f2(x) + f2(x-1) << endl;
}

// 1 11.4263
// 2 16.4615