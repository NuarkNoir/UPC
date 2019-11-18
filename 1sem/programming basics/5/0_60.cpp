// pb_5_0_60.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "N >>";
    cin >> N;
    cout << "With for(...)>>>" << endl;
    for (int i = 1; i <= N; i++) cout << i << endl;
    cout << endl;
    cout << "With while(...)>>>" << endl;
    int wi = 1;
    while (wi <= N) cout << wi++ << endl;
    cout << endl;
    cout << "With do{...}while(...)>>>" << endl;
    int dwi = 1;
    do { cout << dwi++ << endl; } while (dwi <= N);
}
