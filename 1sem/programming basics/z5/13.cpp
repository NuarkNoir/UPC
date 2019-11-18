// pb_z5_13.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

double ai(int);

int main() {
    int N;
    cout << "N >>>";
    cin >> N;
    cout << "S= " << ai(N);
}

double ai(int N) {
    double out = 0;
    for (int i = 1; i <= N; i++)
        out += (float)i/((float)i+1.f);
    return out;
}