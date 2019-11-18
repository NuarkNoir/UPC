// pb_z2_4.cpp
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

    double x, a, b, c, d;
    printf("x [a b] [c d] >>");
    scanf("%lf %lf %lf %lf %lf", &x, &a, &b, &c, &d);
    if ((fmin(a, b) <= x && x <= fmax(a, b)) || (fmin(c, d) <= x && x <= fmax(c, d))) {
        printf("Принадлежит");
    }
    else {
        printf("Не принадлежит");
    };
}