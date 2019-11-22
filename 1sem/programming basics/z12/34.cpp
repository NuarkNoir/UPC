// pb_z12_34.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>

using namespace std;

void make2d(size_t nrows, size_t ncols, int val, ostream &ost);

int main() {
    ofstream fout("out.txt", ios::trunc);
    if (!fout.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    size_t rows, cols;
    int filler;
    cout << "rows, cols, filling_val >>>";
    cin >> rows >> cols >> filler;
    make2d(rows, cols, filler, fout);
    return 0;
}

void make2d(size_t nrows, size_t ncols, int val, ostream &ost) {
    for(size_t i = 0; i < nrows; i++) {
        for(size_t j = 0; j < ncols; j++)  {
            ost << val << " ";
        }
        ost << endl;
    }
}
