// pb_z4_11.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

void print_diag(int s) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << "*" << endl;
    }
}

int main() {
    int a;
    cout << "a >>";
    cin >> a;
    print_diag(a);
}
