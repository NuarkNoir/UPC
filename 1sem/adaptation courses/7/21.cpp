// ac_7_21.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "N >>>";
    cin >> N;
    int *A = new int[N];
    for (int i = 0; i < N; i++) {
        cout << "A[" << i << "] >>>";
        cin >> *(A + i);
    }

    cout << "A = ";
    for (int i = 0; i < N; i++) {
        cout << *(A + i) << " ";
    }
    return 0;
}