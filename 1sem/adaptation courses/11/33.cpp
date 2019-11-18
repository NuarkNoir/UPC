// ac_11_33.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void read_string(istream &reader, string &where, char delimiter) {
    char c;
    while ((c = reader.get()) != delimiter && reader.good()) {
        where += c;
    }
}

int main() {
    vector<string> strs;
    ifstream inf("in.txt");
    if (!inf.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    while (!inf.eof()) {
        string s;
        read_string(inf, s, '\n');
        strs.push_back(s);
    }
    for (auto it = strs.end(); it-- != strs.begin();) {
        cout << *it << endl;
    }
    return 0;
}