// pb_z13_38.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>

using namespace std;

void rev_lines(istream &ist, ostream &ost);

int main() {
    ifstream inf("in.txt");
    ofstream fout("out.txt", ios::trunc);
    if (!inf.is_open() || !fout.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    rev_lines(inf, fout);
    return 0;
}

void rev_lines(istream &ist, ostream &ost) {
    string out;
    while (!ist.eof() && ist.good()) {
        string buf;
        getline(ist, buf);
        out.insert(0, buf + "\n");
    }
    ost << out.substr(0, out.size()-1);
}
