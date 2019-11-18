// ac_4_14.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
using namespace std;

double inline ai(int i) {
    return ((i%3 == 0)? (i / 3.) : (i / (i - 3.)));
}

double sai(int i) {
    double out = 0;
    for (int k = 1; k <= i; k++) {
        auto fr = ai(k);
        out += pow(fr, 2);
    }
    return out;
}

int main() {
    int N;
    cout << "N >>>";
    cin >> N;
    cout << "S= " << sai(N) << endl;
}