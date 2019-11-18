// ac_5_17.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

double df(int N) {
    double out = 0.;
    double i_ = 1;
    for (int i = 1; i <= N; i++) {
        i_ *= i;
        double j_ = 1.;
        double out_ = 1.;
        for (int j = 1; j <= i; j++) {
            j_ *= j;
            out_ *= j_/i_;
        }
        out += out_;
    }
    return out;
}

int main() {
    int N;
    cout << "N >>>";
    cin >> N;
    cout << "SP= " << df(N) << endl;
}