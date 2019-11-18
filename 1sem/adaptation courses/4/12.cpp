// ac_4_12.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
using namespace std;

double ak(double x, int k) {
    return sqrt(x*x + pow(sin(k*M_PI_4), 2));
}

double sum(double x, int N) {
    double out = 0;
    for (int k = 1; k <= N; k++) {
        out += ak(x, k);
    }
    return out;
}

int main() {
    double x;
    int N;
    cout << "x, N >>>";
    cin >> x >> N;
    cout << "S= " << sum(x, N) << endl;
}