// pb_z4_10.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    cout << a << endl;
    do {
        int b;
        cin >> b;
        if (a > b) break;
        cout << b << endl;
        a = b;
    } while (true);
}
