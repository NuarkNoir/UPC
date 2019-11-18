// pb_5_1_40.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}


int main() {
    int a, b, c;
    cout << "a, b, c >>";
    cin >> a >> b >> c;
    cout << (gcd(gcd(a,b),c) == 1? "YES" : "NO") << endl;
}
