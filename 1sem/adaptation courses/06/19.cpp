// ac_6_19.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

double inline funk(int i) {
    return 1./i;
}

int main() {
    double A;
    cout << "A=";
    cin >> A;
    int i = 1;
    double cur = funk(i);
    double prev = 1e6*1.;
    while (!((prev > A) && (A >= cur))) {
        prev = cur;
        cur = funk(++i);
    }
    cout << "a(i=" << i << ")=" << cur;
    return 0;
}