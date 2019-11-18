// pb_z11_32.cpp
// Горбацевич Андрей
#include <iostream>

using namespace std;

int **read_matrix(size_t nrows, size_t ncols);
void print_matrix(int **matrix, size_t nrows, size_t ncols);
void fliplr(int **matrix, size_t nrows, size_t ncols);

int main() {
    size_t rows, cols;
    cout << "rows, cols >>>";
    cin >> rows >> cols;
    int **matrix = read_matrix(rows, cols);
    cout << "Before:" << endl;
    print_matrix(matrix, rows, cols);
    fliplr(matrix, rows, cols);
    cout << "After:" << endl;
    print_matrix(matrix, rows, cols);
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

void fliplr(int **matrix, size_t nrows, size_t ncols) {
    for(size_t i = 0; i < nrows; i++) {
        for(size_t j = 0; j < ncols/2; j++)  {
            swap(*(*(matrix + i) + j), *(*(matrix + i) + ncols - j - 1));
        }
    }
}
