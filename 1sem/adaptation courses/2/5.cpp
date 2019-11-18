// ac_2_5.cpp
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
    int h, m;
    scanf("%d %d", &h, &m);
    h += m > 59;
    if (h > 24) {
        printf("Exception: hours > 24");
        return 0;
    }
    printf("%02d:%02d\n", h, m);
    if (h >= 6 && h < 12) {
        printf("Доброе утро!");
    }
    else if (h >= 12 && h < 18) {
        printf("Добрый день!");
    }
    else if (h >= 18 && h < 24) {
        printf("Добрый вечер!");
    }
    else if (h >= 0 && h < 6){
        printf("Доброй ночи!");
    }
}