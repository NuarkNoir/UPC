// pb_2_2.cpp
// Горбацевич Андрей
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
    int deg;
    printf("deg >>>");
    scanf("%d", &deg);
    int elapsedHours = deg / 30;
    int elapsedMinutes = elapsedHours*60 + deg / 6;
    printf("Elapsed hours: %d \nElapsed minutes: %d", elapsedHours, elapsedMinutes);
}