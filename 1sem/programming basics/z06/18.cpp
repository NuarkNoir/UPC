// pb_z6_18.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
using namespace std;

double f(double);
void plot(double, double, int);

int main() {
    double a, b, s;
    int scale;
    cout << "a, b, s, scale >>>";
    cin >> a >> b >> s >> scale;
    while (a < b) {
        double y = f(a);
        int v = (int)(y * scale);
        plot(a, y, v);
        a += s;
    }
}

static const double PI = acos(-1);
double f(double x) {
    return pow(sin(PI * x), 2);
}

void plot(double x, double y, int v) {
    for (int i = 0; i < v; ++i) {
        cout << " ";
    }
    cout << "$(" << x << ", " << y << ")" << endl;
}