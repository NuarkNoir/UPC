// pb_z13_37.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#define MAX_STRING 500

using namespace std;

void join(const char *sep, istream &ist, ostream &ost);

int main() {
    ifstream inf("in.txt");
    ofstream fout("out.txt", ios::trunc);
    if (!inf.is_open() || !fout.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    string sep;
    cout << "Enter separator >>>";
    getline(cin, sep, '\n');
    join(sep.c_str(), inf, fout);
    return 0;
}

void join(const char *sep, istream &ist, ostream &ost) {
    while (!ist.eof() && ist.good()) {
        char buf[MAX_STRING];
        ist >> buf;
        ost << buf;
        if (!ist.eof()) {
            ost << sep;
        }
    }
}
