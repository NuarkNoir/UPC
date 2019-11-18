// pb_6_2_100.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
using namespace std;

double arctg(double, double);
double mant(double);

int main() {
    double x, d;
    cout << "x, d >>>";
    cin >> x >> d;
    if ((x < -1) or (x > 1)) {
        cout << "err: x not in range";
        return 0;
    }

    double oarctg = arctg(x, d);
    double carctg = atan(x);
    cout << "  own arctg(x) = " << oarctg << endl;
    cout << "cmath arctg(x) = " << carctg << endl;
    cout << "          diff = " << oarctg - carctg << endl;
}

double arctg(double x, double delta) {
    double out = x;
    double px = x;
    int den = 1;
    bool neg = false;
    double pout = out + 0.1f;
    while (abs(mant(out)-mant(pout)) > delta) {
        pout = out;
        neg = !neg;
        x *= px*px;
        den += 2;
        out += x/den * (neg? -1 : 1);
    }
    return out;
}

double mant(double num) {
    return num - (int)num;
}