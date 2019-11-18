// pb_z2_6.cpp
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

    double a, b, c, d;
    printf("a b c >>");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a == 0) {
        printf("Недопустимое значение `a`");
        return 0;
    }
    d = b*b-4*a*c;
    if (d < 0) {
        printf("Действительных корней нет");
    }
    else if (d == 0) {
        printf("x= %lf", -b/(2*a));
    }
    else {
        printf("x1= %lf\nx2= %lf", (-b+sqrt(d))/(2*a), (-b-sqrt(d))/(2*a));
    }
}