// pb_z4_12.cpp
// Горбацевич Андрей
#include <iostream>
using namespace std;

void print_rect(int x, int y, int sx, int sy) {
    cout << "<<<  printing rect  >>>" << endl;
    for (int i = 0; i < y; i++) cout << endl;
    for (int i = 0; i < sy; i++) {
        for (int j = 0; j < x; j++) cout << " ";
        for (int j = 0; j < sx; j++) cout << "@";
        cout << endl;
    }
    cout << "<<<done printing rect>>>" << endl;
}

int main() {
    int x, y, sx, sy;
    cout << "x, y, sx, sy >>";
    cin >> x >> y >> sx >> sy;
    print_rect(x, y, sx, sy);
}
