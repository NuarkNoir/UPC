// ac_2_6.cpp
// Горбацевич Андрей
#include <stdio.h>
#include <cmath>
#include <clocale>
#include <afxres.h>
using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int c;
    scanf("%d", &c);
    int ln = c % 10;
    if ((ln == 0) || (ln >= 5 && ln <= 9) || (c % 100 == 11)) {
        printf("В аудитории %d студентов", c);
    }
    else if (ln == 1) {
        printf("В аудитории %d студент", c);
    }
    else if (ln > 1 && ln < 5) {
        printf("В аудитории %d студента", c);
    }
}