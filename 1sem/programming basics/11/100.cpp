// pb_11_100.cpp
// Горбацевич Андрей
#include <iostream>
#include <cstring>

using namespace std;

struct RECORD {
    int dd, mm, yyyy;
    bool d_valid, m_valid, y_valid;
} rec;

void process(char input[]) {
    char s_dd[3], s_mm[3], s_yyyy[5];
    sscanf(input, "%2s-%2s-%4s", s_dd, s_mm, s_yyyy);
    int dd = stoi(s_dd),
        mm = stoi(s_mm),
        yyyy = stoi(s_yyyy);
    rec.dd = dd;
    rec.mm = mm;
    rec.yyyy = yyyy;
    rec.d_valid = (dd > 0) && (dd < 32);
    rec.m_valid = (mm > 0) && (mm < 13);
    rec.y_valid = (yyyy >= 0) && (strlen(s_yyyy) == 4);
}

int main()
{
    char str[11];
    scanf("%10s", str);
    process(str);
    if (!rec.d_valid) {
        printf("Invalid day! (%d)\n", rec.dd);
    }
    if (!rec.m_valid) {
        printf("Invalid month! (%d)\n", rec.mm);
    }
    if (!rec.y_valid) {
        printf("Invalid year! (%d)\n", rec.yyyy);
    }
    if (rec.d_valid && rec.m_valid && rec.y_valid) {
        int yy = rec.yyyy % 100;
        printf("%02d.%02d.%02d", rec.dd, rec.mm, yy);
    }
}
