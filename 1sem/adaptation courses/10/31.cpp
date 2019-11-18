// ac_10_31.cpp
// Горбацевич Андрей
#include <iostream>
#include <cstring>
#define MAX_STRING 5000

using namespace std;

void del_first_last(char *s) {
    if (strlen(s) < 2) {
        *s = '\0';
    }
    else {
        strncpy(s, s + 1, strlen(s) - 2);
        *(s + strlen(s) - 2) = '\0';
    }
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
    cout << "Before: " << s << endl;
    del_first_last(s);
    cout << "After: " << s << endl;
    return 0;
}