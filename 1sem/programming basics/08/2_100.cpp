// pb_8_2_100.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

int *read_array(int len)
{
    int *out = new int[len];
    for (int i = 0; i < len; i++)
    {
        cout << "arr[" << i << "] >>>";
        cin >> out[i];
    }
    return out;
}

void print_array(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int my_task(const int A[], int lenA, int B[], int lenB) {
    int actbs = 0;
    int indx = -1;
    int *p = new int[lenB];
    for (int i = lenA; i >= 0;) {
        i -= 1;
        if (A[i] >= 0) {
            indx = i;
            break;
        }
        p[actbs++] = A[i];
    }
    delete[] B;
    B = new int[actbs];
    for (int i = 0; i < actbs; i++) {
        B[i] = p[actbs-i-1];
    }
    return indx;
}

int main()
{
    int len;
    cout << "len >>>";
    cin >> len;
    int *a1 = read_array(len);
    int *b = new int[len];
    int indx = my_task(a1, len, b, len);
    if (indx > -1) {
        cout << "Last positive: " << indx;
    }
    else {
        cout << "No positive elements";
    }
    cout << endl << "B = ";
    print_array(b, len-1-indx);
}