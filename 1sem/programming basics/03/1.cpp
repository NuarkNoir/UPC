// pb_3_1.cpp
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

    double x1, y1, x2, y2, x3, y3;
    printf("x1 y1 x2 y2 x3 y3 >>>");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    bool ool = ((x2-x1)*(y3-y1) == (y2-y1)*(x3-x1));
    printf(ool? "YES" : "NO");
}