// pb_z11_33.cpp
// Горбацевич Андрей
#include <iostream>

using namespace std;

int **read_matrix(size_t nrows, size_t ncols);
void print_matrix(int **matrix, size_t nrows, size_t ncols);
void transpose(int **matrix, size_t size);

int main() {
    size_t size;
    cout << "size >>>";
    cin >> size;
    int **matrix = read_matrix(size, size);
    cout << "Before:" << endl;
    print_matrix(matrix, size, size);
    transpose(matrix, size);
    cout << "After:" << endl;
    print_matrix(matrix, size, size);
    return 0;
}

int **read_matrix(size_t nrows, size_t ncols) {
    int **out = new int*[nrows];
    for(size_t i = 0; i < nrows; i++) {
        int *row = new int[ncols];
        for(size_t j = 0; j < ncols; j++)  {
            cin >> *(row + j);
        }
        *(out + i) = row;
    }
    return out;
}

void print_matrix(int **matrix, size_t nrows, size_t ncols) {
    for(size_t i = 0; i < nrows; i++) {
        for(size_t j = 0; j < ncols; j++)  {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}

void transpose(int **matrix, size_t size) {
    for(size_t i = 0; i < size; i++) {
        for(size_t j = i; j < size; j++)  {
            swap(*(*(matrix + i) + j), *(*(matrix + j) + i));
        }
    }
}
