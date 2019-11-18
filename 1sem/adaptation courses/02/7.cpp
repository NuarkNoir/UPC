// ac_2_7.cpp
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
    double op1, op2;
    char f;
    printf("<first operand> <operator> <second operand> >>>");
    scanf("%lf %s %lf", &op1, &f, &op2);
    switch (f) {
        case '+':
            printf("%lf\n", op1 + op2);
            break;
        case '-':
            printf("%lf\n", op1 - op2);
            break;
        case '*':
            printf("%lf\n", op1 * op2);
            break;
        case '/':
            printf("%lf\n", op1 / op2);
            break;
        default:
            printf("Incorrect operator");
            break;
    }
}