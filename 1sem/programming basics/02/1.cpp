// pb_2_1.cpp
// Горбацевич Андрей
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3;
    printf("x1 y1 x2 y2 x3 y3 >>>");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double S = ((x1 - x3)*(y2 - y3) - (x2 - x3)*(y2 - y3)) / 2.f;
    //       1  | x1-x3    y1-y3 |
    //  S = --- |                |
    //       2  | x2-y3    y2-y3 |
    printf("S=%f", abs(S));
}