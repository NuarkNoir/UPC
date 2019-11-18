// pb_z9_25.cpp
// Горбацевич Андрей
#include <iostream>
#include <cstdlib>

using namespace std;

void sort(double arr[], int len, bool asc);
void print_array(const double *arr, size_t len);
double *get_array(size_t len);
int comp_asc(const void* a, const void* b);
int comp_desc(const void* a, const void* b);

// 10 1 2 3 5 4 3 2 2 9 1 0
int main() {
    size_t len;
    cout << "Array length >>>";
    cin >> len;
    cout << "Enter array elements >>>";
    double *a = get_array(len);
    bool asc;
    cout << "Ascending sort? (1/0) >>>";
    cin >> asc;
    cout << "Array before: ";
    print_array(a, len);
    sort(a, len, asc);
    cout << "Array after: ";
    print_array(a, len);
}

void sort(double arr[], int len, bool asc) {
    qsort(arr, len, sizeof(double), asc? comp_asc : comp_desc);
}

void print_array(const double *arr, size_t len) {
    for (size_t i = 0; i < len; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

double *get_array(size_t len) {
    auto *a = new double[len];
    for (size_t i = 0; i < len; i++) {
        cin >> *(a + i);
    }
    return a;
}

int comp_asc(const void* a, const void* b) {
    double arg1 = *(const double*)(a);
    double arg2 = *(const double*)(b);

    if(arg1 < arg2) return -1;
    if(arg1 > arg2) return 1;
    return 0;
}

int comp_desc(const void* a, const void* b) {
    double arg1 = *(const double*)(a);
    double arg2 = *(const double*)(b);

    if(arg1 < arg2) return 1;
    if(arg1 > arg2) return -1;
    return 0;
}
