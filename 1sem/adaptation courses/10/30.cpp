// ac_10_30.cpp
// Горбацевич Андрей
#include <iostream>
#include <cstring>
#define MAX_STRING 5000

using namespace std;

bool is_palindrome(const char *s) {
    bool flag = true;
    size_t i = 0;
    while (flag && i < strlen(s)/2) {
        char cc = *(s + i);
        char lc = *(s + strlen(s)-i-1);
        flag = (cc == lc);
        i++;
    }
    return flag;
}

void read_string(istream &reader, char *where, char delimiter) {
    char c;
    size_t i = 0;
    while ((c = reader.get()) != delimiter && reader.good()) {
        *(where + i++) = c;
    }
    *(where + i) = '\0';
}

int main() {
    char *s = new char[MAX_STRING];
    cout << "Input >>>";
    read_string(cin, s, '\n');
    cout << "String is" << (is_palindrome(s)? "" : "n't") << " palindrome" << endl;
    return 0;
}