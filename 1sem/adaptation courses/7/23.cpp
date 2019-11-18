// ac_7_23.cpp
// Горбацевич Андрей
#include <iostream>

using namespace std;

int *get_array(size_t size);
void print_array(const int *arr, size_t size);
size_t remove_zeros(int *arr, size_t n);

int main()
{
    size_t len;
    cout << "Input length >>>";
    cin >> len;
    cout << "Input array >>>";
    int *arr = get_array(len);
    size_t zc = remove_zeros(arr, len);
    cout << "Zeros count: " << zc << endl;
    cout << "Resulting array: ";
    print_array(arr, len-zc);
}

int *get_array(size_t size) {
    int *array = new int[size]();
    for (size_t i = 0; i < size; i++) {
        cin >> *(array + i);
    }
    return array;
}

void print_array(const int *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

size_t remove_zeros(int *arr, size_t n) {
    size_t out = 0;
    bool flag;
    do {
        flag = false;
        for (size_t i = 0; i < n-1; i++) {
            if (*(arr + i) == 0 && *(arr + i + 1) != 0) {
                swap(*(arr + i), *(arr + i + 1));
                out++;
                flag = true;
                break;
            }
        }
    } while (flag);
    return out;
}
