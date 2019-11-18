// ac_11_35.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string get_short_name(const string &full_name) {
    string out[3];
    int i = 0;
    for (char c : full_name) {
        if (c == ' ') {
            i++;
            continue;
        }
        out[i] += c;
    }
    return out[0] + " " + out[1][0] + "." + out[2][0] + ".";
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
        if (s.size() < 2) continue;
        cout << get_short_name(s) << endl;
    }
    return 0;
}