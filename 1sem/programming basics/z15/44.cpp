// pb_z15_44.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>

using namespace std;

void uchar_add(std::iostream &ost, unsigned char v);

int main() {
    fstream iof("out.bin", ios::in|ios::out|ios::binary);
    if (!iof.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    unsigned char v;
    cout << "Char >>>";
    cin >> v;
    uchar_add(iof, v);
    return 0;
}

void uchar_add(std::iostream &ost, unsigned char v) {
    while (!ost.eof() && ost.good()) {
        unsigned int out = (unsigned char)ost.get() + v;
        ost << (unsigned char)(out > 255? char(255) : char(out));
    }
}
