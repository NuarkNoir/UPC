// pb_z8_22.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

const int al = 100;

int min(int a, int b) {
    return (a < b? a : b);
}

void print_array(int *arr, int len)
{
    for (int i = 0; i < min(al, len); i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main()
{
    int count;
    cout << "count >>>";
    cin >> count;
    int *a = new int[al];
    for (int i = 0; i < al; i++)
    {
        *(a + i) = rand() % 100 + 1;
    }
    print_array(a, count);
}