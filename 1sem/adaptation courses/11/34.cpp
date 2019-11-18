// ac_11_34.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count_words(const string &str) {
    bool inSpaces = true;
    int numWords = 0;
    auto it = begin(str);
    while (*it != '\0')
    {
        if (isspace(*it))
        {
            inSpaces = true;
        }
        else if (inSpaces)
        {
            numWords++;
            inSpaces = false;
        }

        ++it;
    }
    return numWords;
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
        cout << count_words(s) << " words: " << s << endl;
    }
    return 0;
}