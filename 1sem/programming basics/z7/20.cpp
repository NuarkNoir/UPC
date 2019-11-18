// pb_z7_20.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

int count_equal(const int arr[], int len, int x)
{
    int count = 0;
    for (int i=0; i<len; i++)
    {
        count += arr[i] == x;
    }
    return count;
}

int main()
{

    int n, x;
    cout << "n >>>";
    cin >>n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] >>>";
        cin >> a[i];
    }
    cout << "x >>>";
    cin >> x;
    cout << "count of `" << x << "`: " << count_equal(a, n, x);
    delete[] a;
}