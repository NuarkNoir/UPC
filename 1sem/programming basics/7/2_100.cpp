// pb_7_2_100.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
using namespace std;

double f(double);
void pp (double, double);

int main() {
    double a, b, h;
    bool mono_decreasing = true;
    cout << "a, b, h >>>";
    cin >> a >> b >> h;
    double last_y = f(a);
    for (; a < b; a += h) {
        double y = f(a);
        pp(a, y);
        if (last_y < y) {
            mono_decreasing = false;
        }
        else {
            last_y = y;
        }
    }
    cout << "Monotonously decreasing? " << (mono_decreasing? "YES" : "NO") << endl;
}

double f(double x) {
    return x * cos(3 * x ) - 2;
}

void pp (double x, double y) {
    cout.setf(ios_base::right);
    cout.fill(' ');
    cout.width(10);
    cout << x;
    cout.width(15);
    cout << y << endl;
}

// -99 -98.5 0.02 for yes
// 0 0.5 0.02 for no