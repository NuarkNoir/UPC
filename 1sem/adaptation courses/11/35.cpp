// ac_11_35.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <string>
#define MAX_STRING 5000

using namespace std;

string get_short_name(const string &full_name) {
    char s[MAX_STRING], n[MAX_STRING], f[MAX_STRING], out[MAX_STRING];
    sscanf(full_name.c_str(), "%s %s %s", s, n, f);
    sprintf(out, "%s %c.%c.", s, n[0], f[0]);
    return string(out);
}

void read_string(istream &reader, string &where, char delimiter) {
    char c;
    while ((c = reader.get()) != delimiter && reader.good()) {
        where += c;
    }
}

int main() {
    ifstream inf("in.txt");
    if (!inf.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    while (!inf.eof()) {
        string s;
        read_string(inf, s, '\n');
        cout << get_short_name(s) << endl;
    }
    return 0;
}