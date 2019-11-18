// pb_10_25.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const double EPS = 0.001;
const int RIGHT_UP = 1,
          RIGHT_DW = 2,
          LEFT_DW  = 3,
          LEFT_UP = 4;

double inline v_len(double x, double y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

int inline get_quad(double x, double y) {
    if (x >= 0 && y >= 0) {
        return RIGHT_UP;
    }
    if (x >= 0 && y <= 0) {
        return RIGHT_DW;
    }
    if (x <= 0 && y <= 0) {
        return LEFT_DW;
    }
    if (x <= 0 && y >= 0) {
        return LEFT_UP;
    }
}

double *read_array(int len) {
    auto *p = new double[len]();
    cout << "Input " << len << " numbers >>>";
    for (int i = 0; i < len; i++) {
        cin >> *(p + i);
    }
    return p;
}

void print_array(const double *p, int len) {
    cout << "array[] = ";
    for (int i = 0; i < len; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;
}

void sort(double *p, int len, bool asc) {
    bool mod;
    do {
        mod = false;
        for (int i = 0; i < len-1; i++) {
            if (*(p + i) > *(p + i + 1) && asc) {
                swap(*(p + i), *(p + i + 1));
                mod = true;
            }
            else if (*(p + i) < *(p + i + 1) && !asc) {
                swap(*(p + i), *(p + i + 1));
                mod = true;
            }
        }
    } while (mod);
}

double *my_task(const double *A, const double *B, int len) {
    auto *C = new double[len]();
    for (int i = 0; i < len; i++) {
        *(C + i) = v_len(*(A + i), *(B + i));
    }
    return C;
}

void find_nearest_triplet(const double *A, const double *B, int len) {
    double dist = 0;
    vector<int> triplet;
    for (int i = 0; i < len; i++) {
        dist = v_len(*(A + i), *(B + i));
        triplet.push_back(i);
        for (int j = 0; j < len; j++) {
            if (triplet.size() > 2) break;
            if (i == j) continue;
            if (abs(v_len(*(A + j), *(B + j)) - dist) < EPS) {
                if (get_quad(*(A + j), *(B + j)) != get_quad(*(A + i), *(B + i))) {
                    triplet.push_back(j);
                }
            }
        }
        if (triplet.size() == 3) {
            cout << "Three equally-distant dots:" << endl;
            for (int pos : triplet) {
                cout << "\t" << pos << "(" << *(A + pos) << ", " << *(B + pos) << ")" << endl;
            }
            cout << "With distance = " << dist << endl;
            return;
        }
        triplet.clear();
    }
    cout << "No three equally-distant dots found." << endl;
}

int main() {
    int len;
    bool asc;
    cout << "len >>>";
    cin >> len;
    cout << "asc[0, 1] >>>";
    cin >> asc;
    double *A = read_array(len);
    double *B = read_array(len);
    double *C = my_task(A, B, len);
    cout << "Before sort():" << endl;
    print_array(A, len);
    print_array(B, len);
    print_array(C, len);
    sort(A, len, asc);
    sort(B, len, asc);
    sort(C, len, asc);
    cout << "After sort():" << endl;
    print_array(A, len);
    print_array(B, len);
    print_array(C, len);

    find_nearest_triplet(A, B, len);
}