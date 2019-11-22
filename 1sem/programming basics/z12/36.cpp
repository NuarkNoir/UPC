// pb_z12_36.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>

using namespace std;

int **read_matrix(size_t nrows, size_t ncols);
void transpose(int **matrix, size_t size, ostream &ost);

int main() {
    ofstream fout("out.txt", ios::trunc);
    if (!fout.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    size_t size;
    cout << "size >>>";
    cin >> size;
    int **matrix = read_matrix(size, size);
    transpose(matrix, size, fout);
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

void transpose(int **matrix, size_t size, ostream &ost) {
    for(size_t i = 0; i < size; i++) {
        for(size_t j = 0; j < size; j++)  {
            ost << *(*(matrix + j) + i) << " ";
        }
        ost << endl;
    }
}
