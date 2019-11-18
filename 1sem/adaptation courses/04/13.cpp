// ac_4_13.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
using namespace std;

double xmi(double x, int N) {
    double out = 0;
    for (int i = 1; i <= N; i++) {
        out += 1/pow(x, i);
    }
    return out;
}

double xi(double x, int N) {
    double out = 1;
    for (int i = 0; i <= N; i++) {
        out *= (x - i);
    }
    return out;
}

int main() {
    double x;
    int N;
    cout << "x, N >>>";
    cin >> x >> N;
    cout << "S= " << xmi(x, N) << endl;
    cout << "P= " << xi(x, N) << endl;
}