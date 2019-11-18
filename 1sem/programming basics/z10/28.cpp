// pb_z10_28.cpp
// Горбацевич Андрей
#include <iostream>
#include <vector>
#include <cstring>

#define MAX_STR 5000
using namespace std;

void rstrip(char*, const char*);
char* get_string();
void println_string(const char*);

int main() {
    char *s, *chars;
    cout << "Input string:" << endl;
    s = get_string();
    cout << "Input chars:" << endl;
    chars = get_string();
    cout << "String before:" << endl;
    println_string(s);
    rstrip(s, chars);
    cout << "String after:" << endl;
    println_string(s);
}

void rstrip(char *s, const char *chars) {
    int rpad = 0;
    int i = (int)strlen(s)-1;
    bool found;
    do {
        found = false;
        char cc = *(s + i--);
        for (size_t j = 0; j < strlen(chars); j++) {
            if (cc == *(chars + j)) {
                rpad += 1;
                found = true;
                *(s + i+1) = '\0';
                break;
            }
        }
    } while (found && i >= 0);
}

char* get_string() {
    int c = 0;
    char *s = new char[MAX_STR];
    char ch;
    while ((ch = cin.get()) != '\n') {
        *(s + c++) = ch;
    }
    *(s + c) = '\0';
    return s;
}

void println_string(const char* s) {
    for (size_t i = 0; i < strlen(s); i++) {
        cout << *(s + i);
    }
    cout << endl;
}