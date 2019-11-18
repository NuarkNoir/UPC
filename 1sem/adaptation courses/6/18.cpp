// ac_6_18.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
using namespace std;

double inline funk(int i) {
    return 1./i;
}

int main() {
    double eps;
    cout << "eps=";
    cin >> eps;
    int i = 1;
    double cur = funk(i);
    double prev = 1e6*1.;
    while (abs(cur-prev)>=eps) {
        prev = cur;
        cur = funk(++i);
    }
    cout << "a(i=" << i << ")=" << cur;
    return 0;
}