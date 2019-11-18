// pb_z5_14.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

double ai(int, double);
double spow(double, double);

int main() {
    int N;
    double x;
    cout << "N, x >>>";
    cin >> N >> x;
    cout << "P= " << ai(N, x);
}

double ai(int N, double x) {
    double out = 1;
    for (int i = 1; i <= N; i++)
        out *= 2 * spow(x, i);
    return out;
}

double spow(double f, double p) {
    double out = 1;
    for (int i = 0; i < p; i++) out *= f;
    return out;
}