// pb_4_2_40.cpp
// Горбацевич Андрей
#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double f1(double x)
{
    x = log(x*x) - 8.3e3;
    return x;
}
double f2(double x)
{
    x = 1 / (cbrt(3*x) + 1);
    return x;
}
int main()
{
    double x;
    cout << "X=?\n";
    cin >> x;
    if (x == 0) {
        cout << "err: x == 0" << endl;
        return 0;
    }
    cout << "y=" << f1(x) + f2(x) << endl;
}

// 1 -8299.59
// 2 -8298.26