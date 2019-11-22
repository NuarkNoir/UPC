// pb_z14_42.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>

using namespace std;

void write_filling_ones(ostream &ost, size_t N);

int main() {
    ifstream inf("in.txt");
    ofstream fout("out.bin", ios::trunc|ios::binary);
    if (!inf.is_open() || !fout.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    int N = 0;
    inf >> N;
    write_filling_ones(fout, N);
    return 0;
}

void write_filling_ones(ostream &ost, size_t N) {
    unsigned char cval = 0b00000000;
    unsigned char mval = 0b11111111;
    for (size_t i = 0; i < N; i +=2) {
        if (cval == mval) {
            cval = 0b00000000;
        }
        ost << cval;
        cval = (unsigned)(cval << 1u) | 1u;
    }
}
