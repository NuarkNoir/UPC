// ac_3_11.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
using namespace std;

bool in_D(double x, double y)
{
    bool moreTwo = (y >= 2);
    bool inAbs = (y >= 2*abs(x));
    return moreTwo or inAbs;
}

int main()
{
    double x, y, a;
    cout << "x, y, a >>>";
    cin >> x >> y >> a;
    double S = ((in_D(x, y) and (a < 2))? (pow(a, -x)) : log(1 + x*x));
    cout << "S(x,y,a)= " << S << endl;
}