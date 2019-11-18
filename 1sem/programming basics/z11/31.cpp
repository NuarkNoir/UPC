// pb_z11_31.cpp
// Горбацевич Андрей
#include <iostream>

using namespace std;

int **read_matrix(size_t rows, size_t cols);
void print_matrix(int **matrix, size_t rows, size_t cols);
int **make2d(size_t nrows, size_t ncols, int val);

int main() {
    size_t rows, cols;
    int filler;
    cout << "rows, cols, filling_val >>>";
    cin >> rows >> cols >> filler;
    int **matrix = make2d(rows, cols, filler);
    print_matrix(matrix, rows, cols);
    return 0;
}

int **make2d(size_t nrows, size_t ncols, int val) {
    int **out = new int*[nrows];
    for(size_t i = 0; i < nrows; i++) {
        int *row = new int[ncols];
        for(size_t j = 0; j < ncols; j++)  {
            *(row + j) = val;
        }
        *(out + i) = row;
    }
    return out;
}

void print_matrix(int **matrix, size_t rows, size_t cols) {
    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < cols; j++)  {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}

