// ac_5_15.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

double df(int N) {
    double out = 1.;
    double os = 0.;
    for (int i = 1; i <= N; i++) {
        os += i*i;
        out *= os;
    }
    return out;
}

int main() {
    int N;
    cout << "N >>>";
    cin >> N;
    cout.setf(ios_base::fixed);
    cout << "PS= " << df(N) << endl;
}