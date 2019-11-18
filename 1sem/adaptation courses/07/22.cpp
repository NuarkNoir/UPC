// ac_7_22.cpp
// Горбацевич Андрей
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(nullptr) / 2);

    int N;
    cout << "N >>>";
    cin >> N;
    int *rez = new int[N];
    int *data = new int[100]();
    for (int i = 0; i < N; i++) {
        *(rez + i) = 1 + rand() % 100 + 1;
    }
    for (int i = 0; i < N; i++) {
        *(data + (*(rez + i) - 1)) += 1;
    }
    cout << "rez = ";
    for (int i = 0; i < N; i++) {
        cout << *(rez + i) << " ";
    }
    cout << endl << endl;
    for (int i = 0; i < 100; i++) {
         cout << "Count of `" << i + 1 << "`: " << *(data + i) << endl;
    }
    return 0;
}