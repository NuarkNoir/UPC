// pb_z10_30.cpp
// Горбацевич Андрей
#include <iostream>
#include <vector>
#include <cstring>

#define MAX_STR 5000
using namespace std;

size_t join(char*, size_t , const char*const*, size_t, const char*);
char* get_string();
char** get_string_list(size_t);
void println_string(const char*);

int main() {
    size_t n_in;
    cout << "Count of strings >>>";
    cin >> n_in;
    cout << "Strings:" << endl;
    char **s_in = get_string_list(n_in+1);
    cout << "Joiner separator >>>";
    char *sep = get_string();
    cout << "Max length >>>";
    size_t len;
    cin >> len;
    char *s_out = new char[len];
    size_t f_len = join(s_out, len, s_in, n_in, sep);
    cout << "Joined string:" << endl;
    println_string(s_out);
}

size_t join(char *s_out, size_t len, const char *const *s_in, size_t n_in, const char *sep) {
    string ps_out;
    ps_out += string(*(s_in + 1));
    for (size_t i = 2; i <= n_in; i++) {
        ps_out += string(sep) + string(*(s_in + i));
    }
    size_t mnl = min(len, ps_out.length());
    for (size_t i = 0; i < mnl; i++) {
        *(s_out + i) = ps_out.c_str()[i];
    }
    *(s_out + mnl) = '\0';
    return strlen(s_out);
}

char** get_string_list(size_t count) {
    char **arr = new char*[count];
    for (size_t i = 0; i < count; i++) {
        *(arr + i) = get_string();
    }
    return arr;
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