// pb_z15_43.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

void reverse_uchar(std::iostream &ost);

int main() {
    fstream iof("out.bin", ios::in|ios::out|ios::binary);
    if (!iof.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    reverse_uchar(iof);
    return 0;
}

void reverse_uchar(std::iostream &ost) {
    unsigned char cval = UCHAR_MAX;
    for (int i = 0; i <= cval; i++) {
        ost << cval--;
    }
}
