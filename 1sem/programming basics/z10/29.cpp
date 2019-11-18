// pb_z10_29.cpp
// Горбацевич Андрей
#include <iostream>
#include <vector>
#include <cstring>

#define MAX_STR 5000
using namespace std;

void strip(char*, const char*);
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
    strip(s, chars);
    cout << "String after:" << endl;
    println_string(s);
}

void strip(char *s, const char *chars) {
    int lpad = 0;
    int fi = 0;
    bool found;
    do {
        found = false;
        char cc = *(s + fi);
        for (size_t j = 0; j < strlen(chars); j++) {
            if (cc == *(chars + j)) {
                lpad += 1;
                found = true;
                break;
            }
        }
        fi++;
    } while(found && fi >= 0);
    if(lpad > 0)
    {
        size_t i;
        for (i = 0; i < strlen(s) - lpad; i++)
        {
            *(s + i) = *(s + i + lpad);
        }
        *(s + i) = '\0';
    }

    int rpad = 0;
    int ei = (int)strlen(s)-1;
    do {
        found = false;
        char cc = *(s + ei--);
        for (size_t j = 0; j < strlen(chars); j++) {
            if (cc == *(chars + j)) {
                rpad += 1;
                found = true;
                *(s + ei + 1) = '\0';
                break;
            }
        }
    } while (found && ei >= 0);
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