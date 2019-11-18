// pb_z1_2.cpp
// Горбацевич Андрей
#include <stdio.h>
using namespace std;

int main() {
    int num_people, num_seats, num_buses, num_free_seats;
    printf("People count seats count >>>");
    scanf("%d %d", &num_people, &num_seats);
    num_buses = num_people / num_seats;
    bool additional_seats = num_people % num_seats > 0;
    num_buses += additional_seats;
    num_free_seats = num_buses * num_seats - num_people;
    printf("Busses count: %d\nFree seats: %d\n", num_buses, num_free_seats);
}