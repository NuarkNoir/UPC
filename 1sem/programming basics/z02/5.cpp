// pb_z2_5.cpp
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

    double a1, a2, b1, b2;
    printf("[a1 a2] [b1, b2] >>");
    scanf("%lf %lf %lf %lf", &a1, &a2, &b1, &b2);
    if (fmin(a1, a2) == fmin(b1, b2) && fmax(a1, a2) == fmax(b1, b2)) {
        printf("А равно B");
    }
    else if (fmin(a1, a2) >= fmin(b1, b2) && fmax(a1, a2) <= fmax(b1, b2)) {
        printf("А внутри B");
    }
    else if (fmin(b1, b2) >= fmin(a1, a2) && fmax(b1, b2) <= fmax(a1, a2)) {
        printf("B внутри A");
    }
    else if ((fmin(b1, b2) <= fmin(a1, a2) && fmin(a1, a2) <= fmax(b1, b2)) || (fmin(b1, b2) <= fmax(a1, a2) && fmax(a1, a2) <= fmax(b1, b2))) {
        printf("Другое пересечение");
    }
    else {
        printf("Нет пересечения");
    }
}