// pb_15_100_v3.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>

using namespace std;

void text2bin(istream &ist, ostream &ost);

void my_task(istream &ist);

int main() {
    string path_in = "in.txt"; // путь до входного файла
    string path_out = "out.bin"; // путь до выходного файла

    ifstream ifs(path_in);
    ofstream ofs(path_out, ios::binary);
    if (!ifs.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    text2bin(ifs, ofs);
    ifs.close();
    ofs.close();

    ifstream binfs(path_out, ios::binary);
    my_task(binfs);

    return 0;
}

void text2bin(istream &ist, ostream &ost) {
    int N, M;
    ist >> N >> M;
    ost << char(N) << char(M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int cv;
            ist >> cv;
            ost << char(cv);
        }
    }
}

void my_task(istream &ist) {
    ist.seekg(0, ios::beg);
    int k;
    cout << "k >>>";
    cin >> k;
    int N = int(ist.get()),
        M = int(ist.get());
    int **mtx = new int*[N];
    for (int i = 0; i < N; i++) {
        int *row = new int[M]();
        for (int j = 0; j < M; j++) {
            *(row + j) = int(ist.get());
        }
        *(mtx + i) = row;
    }
    for (int i = 0; i < N; i++) {
        bool flag = true;
        int *row = mtx[i];
        for (int j = 1; j < M; j++) {
            if (row[j-1] > row[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            int l = 0,
                r = M-1;
            int m;
            while (l<=r) {
                m = (l+r) / 2;
                if (k > row[m]) {
                    l = m+1;
                }
                else if (k < row[m]) {
                    r = m-1;
                }
                else {
                    cout << "Line " << i + 1 << " is ascending and contains k(k==" << k << ")\n";
                    break;
                }
            }
        }
    }
}