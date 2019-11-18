// pb_z8_24.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

int splice_array(const int *arr1, const int *arr2, int len, int *arr_out)
{
    int out = 0;
    for (int i=0; i<len; i++)
    {
        *(arr_out + i*2) = *(arr1 + i);
        *(arr_out + i*2+1) = *(arr2 + i);
        out += 2;
    }
    return out;
}

int main()
{
    int n;
    cout << "n >>>";
    cin >> n;
    int *a1 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "a1[" << i << "] >>>";
        cin >> *(a1 + i);
    }

    int *a2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "a2[" << i << "] >>>";
        cin >> *(a2 + i);
    }
    int *a = new int[n * 2];
    int l = splice_array(a1, a2, n, a);
    cout << "length " << l << endl;
    for (int i = 0; i < l; i++) {
        cout << *(a + i) << " ";
    }
    delete[] a, a1, a2;
}