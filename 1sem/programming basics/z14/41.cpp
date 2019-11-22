// pb_z14_41.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>

using namespace std;

void write_cyclic_one(ostream &ost, size_t N);

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
    write_cyclic_one(fout, N);
    return 0;
}

void write_cyclic_one(ostream &ost, size_t N) {
    unsigned char cval = 0x01;
    unsigned char mval = 0x80;
    for (size_t i = 0; i < N; i +=2) {
        if (cval >= mval) {
            cval = 0x01;
        }
        ost << cval;
        cval <<= 1u;
    }
}
