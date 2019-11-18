// pb_z9_27.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>

using namespace std;

void sort(double arr[], int len, double x);
void print_array(const double *arr, size_t len);
double *get_array(size_t len);

// 8 1 2 3.5 4 3 2 2.9 1 2.5
int main() {
    size_t len;
    cout << "Array length >>>";
    cin >> len;
    cout << "Enter array elements >>>";
    double *a = get_array(len);
    double x;
    cout << "x >>>";
    cin >> x;
    cout << "Array before: ";
    print_array(a, len);
    sort(a, len, x);
    cout << "Array after: ";
    print_array(a, len);
    auto *dist = new double[len];
    for (size_t i = 0; i < len; i++) {
        *(dist + i) = abs(*(a + i) - x);
    }
    cout << "Array dist: ";
    print_array(dist, len);
}

void sort(double arr[], int len, double x) {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < len-1; i++) {
            double cv = *(arr + i),
                    nv = *(arr + i + 1),
                    cvd = abs(cv - x),
                    nvd = abs(nv - x);
            if (cvd > nvd) {
                swap(*(arr + i), *(arr + i + 1));
                swapped = true;
            }
        }
    } while (swapped);
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