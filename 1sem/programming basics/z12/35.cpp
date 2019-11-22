// pb_z12_35.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>

using namespace std;

int **read_matrix(size_t nrows, size_t ncols);
void fliplr(int **matrix, size_t nrows, size_t ncols, ostream &ost);

int main() {
    ofstream fout("out.txt", ios::trunc);
    if (!fout.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    size_t rows, cols;
    cout << "rows, cols >>>";
    cin >> rows >> cols;
    int **matrix = read_matrix(rows, cols);
    fliplr(matrix, rows, cols, fout);
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

void fliplr(int **matrix, size_t nrows, size_t ncols, ostream &ost) {
    for(size_t i = 0; i < nrows; i++) {
        for(size_t j = ncols; j > 0; j--)  {
            ost << *(*(matrix + i) + j - 1) << " ";
        }
        ost << endl;
    }
}
