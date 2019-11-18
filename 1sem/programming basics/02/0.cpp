// pb_2_0.cpp
// Горбацевич Андрей
#include <stdio.h>
using namespace std;

int main() {
    long a, b;
    printf("Input `a` and `b` >>>");
    scanf("%ld %ld", &a, &b);
    long sum = a + b;
    long diff = a - b;
    long multiplication = a * b;
    printf("Sum(%%ld): %ld \nMultiplication(%%10ld): %10ld \nDifference(%%-10ld): %-10ld\n",
           sum, multiplication, diff);
    double mean = (float)(a + b) / 2.f;
    printf("Mean:\n%%f: %f\n%%15.4f: %15.4f\n%%-15.4f: %-15.4f\n%%0.15f: %0.15f\n%%30.15f: %30.15f",
           mean, mean, mean, mean, mean);
}