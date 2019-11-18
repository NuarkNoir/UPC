// pb_z9_26.cpp
// Горбацевич Андрей
#include <iostream>

using namespace std;

void sort(int arr[], int len, bool even_greater);
void print_array(const int *arr, size_t len);
int *get_array(size_t len);

// 8 1 2 3 4 3 2 6 5 1
int main() {
    size_t len;
    cout << "Array length >>>";
    cin >> len;
    cout << "Enter array elements >>>";
    int *a = get_array(len);
    bool even_greater;
    cout << "Is even greater? (1/0) >>>";
    cin >> even_greater;
    cout << "Array before: ";
    print_array(a, len);
    sort(a, len, even_greater);
    cout << "Array after: ";
    print_array(a, len);
}

void sort(int arr[], int len, bool even_greater) {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < len - 1; i++) {
            int cv = *(arr + i),
                nv = *(arr + i + 1);
            if (cv % 2 == nv % 2) {
                if (cv > nv) {
                    swap(*(arr + i), *(arr + i + 1));
                    swapped = true;
                }
            }
            if (even_greater) {
                if (cv % 2 == 0 && nv % 2 != 0) {
                    swap(*(arr + i), *(arr + i + 1));
                    swapped = true;
                }
            }
            else {
                if (cv % 2 != 0 && nv % 2 == 0) {
                    swap(*(arr + i), *(arr + i + 1));
                    swapped = true;
                }
            }
        }
    } while (swapped);
}

void print_array(const int *arr, size_t len) {
    for (size_t i = 0; i < len; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int *get_array(size_t len) {
    int *a = new int[len];
    for (size_t i = 0; i < len; i++) {
        cin >> *(a + i);
    }
    return a;
}