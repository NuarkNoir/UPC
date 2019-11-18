// ac_10_32.cpp
// Горбацевич Андрей
#include <iostream>
#include <cstring>
#define MAX_STRING 5000

using namespace std;

void capitalize(char *s) {
    *s = (char)toupper(*s);
    for (size_t i = 1; i < strlen(s); i++) {
        if (*(s + i) == ' ') {
            *(s + i + 1) = (char)toupper(*(s + i + 1));
        }
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
    capitalize(s);
    cout << "After: " << s << endl;
    return 0;
}