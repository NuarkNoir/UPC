// pb_z1_3.cpp
// Горбацевич Андрей
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    double d;
    printf("d >>>");
    scanf("%lf", &d);
    d = ((int)(abs(d) * 10)) % 10;
    printf("%d", (int)d);
}