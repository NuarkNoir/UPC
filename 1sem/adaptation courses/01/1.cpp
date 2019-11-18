// ac_1_1.cpp
// Горбацевич Андрей
#include <iostream>
#include <cstdio>
#include <clocale>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    string n, d;
    cin >> n >> d;
    cout << "Привет, " << d << " " << n << "!";
}
