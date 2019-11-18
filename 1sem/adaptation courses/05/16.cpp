// ac_5_16.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
using namespace std;

int fk(int i) {
    if ((i == 0) || (i == 1))
        return 1;
    int out = 1;
    for (int j = 2; j <= i; j++) {
        out *= j;
    }
    return out;
}

double df(int N, int M) {
    double out = 0;
    int fak = fk(M);
    for (int k = M; k <= N; k++) {
        out += k*k*log(fak);
        fak *= k+1;
    }
    return out;
}

int main() {
    int N, M;
    cout << "N, M >>>";
    cin >> N >> M;
    cout << "S= " << df(N, M) << endl;
}