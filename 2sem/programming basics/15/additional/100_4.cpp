// pb_15_100_v4.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>

using namespace std;

int readBinInt(istream &ist);

void writeBinInt(int num, ostream &ost);

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

int readBinInt(istream &ist) {
    int x = 0;
    ist.read(reinterpret_cast<char*>(&x), sizeof(int));
    return x;
}

void writeBinInt(int num, ostream &ost) {
    ost.write(reinterpret_cast<char*>(&num), sizeof(int));
}

void text2bin(istream &ist, ostream &ost) {
    int N, M;
    ist >> N >> M;
    writeBinInt(N, ost);
    writeBinInt(M, ost);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int cv;
            ist >> cv;
            writeBinInt(cv, ost);
        }
    }
}

void my_task(istream &ist) {
    int k;
    cout << "k >>>";
    cin >> k;
    int N = readBinInt(ist),
        M = readBinInt(ist);
    if (k-1 > M) {
        return;
    }
    int **mtx = new int*[N];
    for (int i = 0; i < N; i++) {
        int *row = new int[M]();
        for (int j = 0; j < M; j++) {
            *(row + j) = readBinInt(ist);
        }
        *(mtx + i) = row;
    }
    for (int i = 0; i < N; i++) {
        int *row = mtx[i];
        bool flag = true;
        for (int sk = 1; sk <= k; sk++) {
            bool cc = false;
            for (int j = 0; j < M; j++) {
                if (row[j] == sk) {
                    cc = true;
                    break;
                }
            }
            if (!cc) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Line " << i+1 << " contains every number in 1..." << k << endl;
        }
    }
}