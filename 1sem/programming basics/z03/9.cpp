// pb_z3_9.cpp
// Горбацевич Андрей
#include <cmath>
#include <iostream>
#include<algorithm>
using namespace std;

float min_or_max(float a, float b, float c)
{
    if (a > 0.5)
        return max(b, c);
    else
        return min(b, c);
}

int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    float d = min_or_max(a, b, c);
    cout << d << endl;
}