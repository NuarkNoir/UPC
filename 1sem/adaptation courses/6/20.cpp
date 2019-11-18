// ac_6_20.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
using namespace std;

double inline funk(int i) {
    double out = 1;
    for (int k = 1; k <= i; k++) {
        out *= (1 - 1 / sqrt(k + i));
    }
    return out;
}

int main() {
    double eps;
    cout << "eps=";
    cin >> eps;
    int i = 0;
    double aip = funk(++i);
    double ai = funk(++i);
    while (abs(ai-aip)>=eps) {
        aip = ai;
        ai = funk(++i);
    }
    cout << "a(i=" << i << ")=" << ai;
    return 0;
}