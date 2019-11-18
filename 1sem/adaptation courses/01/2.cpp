// ac_1_2.cpp
// Горбацевич Андрей
#include <iostream>
#include <cstdio>
#include <clocale>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    double a;
    cin >> a;
    cout << a*a*a*sqrt(2.f)/12;
}
