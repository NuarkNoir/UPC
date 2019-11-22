// pb_z14_40.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>

using namespace std;

void write_aa_55(ostream &ost, size_t N);

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
    write_aa_55(fout, N);
    return 0;
}

void write_aa_55(ostream &ost, size_t N) {
    for (size_t i = 0; i < N; i +=2) {
        ost << (unsigned char)0xAA;
        if (i + 1 < N) {
            ost << (unsigned char)0x55;
        }
    }
}
