// ac_1_4.cpp
// Горбацевич Андрей
#include <iostream>
#include <cstdio>
#include <clocale>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    int d,h,m;
    cin >> m;
    d = m / (60 * 24);
    m = m - (d * 60 * 24);
    h = m / 60;
    m = m - (h * 60);
    printf("%d сутки(ок), %d часа(ов), %d минут(а)", d, h, m);
}
