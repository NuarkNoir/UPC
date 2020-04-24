// pb_19_100.cpp
// Горбацевич Андрей
#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

struct point {
    int x,y;
};
struct field {
    int field[8][8] = {};
};

void print_mtx(field&);
void traverse(point at, field&);
void draw_shortest(point at, field&);

auto comparePoints = [](const point &a, const point &b)
{
    return (a.x < b.x) || (a.y < b.y);
};
set<point, decltype(comparePoints)> visited;

char i2f(int p) {
    if (p < 0 || p > 8) {
        throw out_of_range("char should be in a..h");
    }
    return char(int('a') + p);
}
int f2i(char _c) {
    char c = char(tolower(_c));
    if (c < 'a' || c > 'h') {
        throw out_of_range("char should be in a..h");
    }
    return (c % 'a');
}

bool pif(point p) {
    return ((p.x < 8) && (p.x >= 0)) && ((p.y < 8) && (p.y >= 0));
}

int main() {
    cout << "Enter starting point (e.g. c3) >>>";
    point pos{};
    char xe;
    cin >> xe;
    pos.x = f2i(xe);
    cin >> pos.y;
    pos.y -= 1;
    if (pos.y < 0 || pos.y >= 8) {
        throw out_of_range("y pos should be in 1..8");
    }

    cout << "Enter end point (e.g. c3) >>>";
    point end{};
    cin >> xe;
    end.x = f2i(xe);
    cin >> end.y;
    end.y -= 1;
    if (end.y < 0 || end.y >= 8) {
        throw out_of_range("y pos should be in 1..8");
    }

    field f;
    f.field[pos.x][pos.y] = 1;
    //print_mtx(f);
    traverse(pos, f);
    //print_mtx(f);
    cout << "It takes " << f.field[end.x][end.y] << " steps to get here (inc. first pos.)." << endl;
    cout << "Possible route: ";
    draw_shortest(end, f);
    cout << i2f(end.x) << end.y+1;

    return 0;
}

void print_mtx(field &f) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << f.field[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void traverse(point at, field &f) {
    vector<point> pts = {
            {at.x+1, at.y-2}, {at.x+2, at.y-1},
            {at.x+2, at.y+1}, {at.x+1, at.y+2},
            {at.x-1, at.y+2}, {at.x-2, at.y+1},
            {at.x-2, at.y-1}, {at.x-1, at.y-2},
    };

    for (auto pt : pts) {
        if (!pif(pt) || f.field[pt.x][pt.y] != 0) {
            continue;
        }
        f.field[pt.x][pt.y] = f.field[at.x][at.y] + 1;
    }
    for (auto pt : pts) {
        if (!pif(pt) || f.field[pt.x][pt.y] != f.field[at.x][at.y]+1) {
            continue;
        }
        traverse(pt, f);
    }
}

void draw_shortest(point at, field &f) {
    vector<point> pts = {
            {at.x+1, at.y-2}, {at.x+2, at.y-1},
            {at.x+2, at.y+1}, {at.x+1, at.y+2},
            {at.x-1, at.y+2}, {at.x-2, at.y+1},
            {at.x-2, at.y-1}, {at.x-1, at.y-2},
    };

    for (auto pt : pts) {
        if (!pif(pt) || f.field[pt.x][pt.y] != f.field[at.x][at.y]-1) {
            continue;
        }
        draw_shortest(pt, f);
        cout << i2f(pt.x) << pt.y+1 << " -> ";
        break;
    }
}
