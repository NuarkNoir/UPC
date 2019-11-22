// pb_z13_39.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>

using namespace std;

void wrap_text(istream &ist, ostream &ost, int max_line_len);

int main() {
    ifstream inf("in.txt");
    ofstream fout("out.txt", ios::trunc);
    if (!inf.is_open() || !fout.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    int max_line_len = 0;
    cout << "Maximal line length >>>";
    cin >> max_line_len;
    wrap_text(inf, fout, max_line_len);
    return 0;
}

void wrap_text(istream &ist, ostream &ost, int max_line_len) {
    int cl = 0;
    char c;
    while ((c = ist.get()) && !ist.eof() && ist.good()) {
        if (cl >= max_line_len) {
            cl = 0;
            ost << endl;
        }
        ost << c;
        cl++;
    }
}
