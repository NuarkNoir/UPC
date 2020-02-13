// pb_15_100.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>

using namespace std;

void text2bin(istream &ist, ostream &ost);

void my_task(istream &ist);

int main() {
    ifstream ifs("in.txt");
    ofstream ofs("out.bin", ios::trunc|ios::binary);
    if (!ifs.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    text2bin(ifs, ofs);
    my_task(ifs);

    return 0;
}

void text2bin(istream &ist, ostream &ost) {
    int N, M;
    ist >> N >> M;
    ost << N << ' ' << M;
    for (int i = 0; i < N; i++) {
        ost << endl;
        for (int j = 0; j < M; j++) {
            int cv;
            ist >> cv;
            ost << cv << ' ';
        }
    }
}

void my_task(istream &ist) {
    ist.seekg(0, ios::beg);
    int k;
    cout << "k >>>";
    cin >> k;
    int N, M;
    ist >> N >> M;
    int **mtx = new int*[N];
    for (int i = 0; i < N; i++) {
        int *row = new int[M]();
        for (int j = 0; j < M; j++) {
            int cv;
            ist >> cv;
            *(row + j) = cv;
        }
        *(mtx + i) = row;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (mtx[i][j-1] < mtx[i][j]) {
                bool flag = false;
                for (int v = 0; v < M; v++) {
                    if (mtx[i][v] == k) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    cout << "Line " << i + 1 << " contains k(k==" << k << ")\n";
                }
                break;
            }
        }
    }
}