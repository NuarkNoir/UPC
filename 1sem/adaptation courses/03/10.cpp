// ac_3_10.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
using namespace std;

bool in_D(double x, double y)
{
    double R = x*x + y*y;
    bool up = (y >= 0);
    bool l = (x <= 0);
    bool r = (x >= 0);
    bool fp = l and (R <= 1);
    bool sp = r and (R >= 0.36) and (R <= 1);
    return up and (fp or sp);
}

int main()
{
    double x, y;
    cout << "x, y >>>";
    cin >> x >> y;
    double P = (in_D(x, y)? x+y : 0 );
    cout << "P(x,y)= " << P << endl;
}