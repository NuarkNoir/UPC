// pb_z5_15.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

double ai(int);
double s(int);

int main() {
    int N;
    cout << "N >>>";
    cin >> N;
    cout << "S= " << ai(N);
}

double ai(int N) {
    double out = 0;
    for (int i = 1; i <= N; i++)
        out += i * s(i);
    return out;
}

double s(int i) {
    return (i % 2? -1 : 1);
}