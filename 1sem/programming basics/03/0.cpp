// pb_3_0.cpp
// Горбацевич Андрей
#include <stdio.h>
#include <cmath>
#include <clocale>
#include <afxres.h>
#include <iostream>

using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    double phi = 1.618033988749894848204586834365638117720309179805762862135;

    cout.width(20);
    cout << phi << endl;

    cout.precision(20);
    cout << phi << endl;

    cout.precision(3);
    cout.width(20);
    cout.fill('_');
    cout << phi << endl;

    cout.fill('_');
    cout.width(30);
    cout.setf(ios_base::left);
    cout << phi << endl;
    cout.fill('_');
    cout.width(30);
    cout.setf(ios_base::right);
    cout << phi << endl;
}