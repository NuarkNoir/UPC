// pb_z1_1.cpp
// Горбацевич Андрей
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    printf("a b >>>");
    scanf("%d %d", &a, &b);
    swap(a, b);
    printf("a=%d \nb=%d", a, b);
}