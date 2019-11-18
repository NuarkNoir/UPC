// ac_9_29.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void move_positive_first(vector<float> &vec) {
    bool flag;
    do {
        flag = false;
        for (size_t i = 0; i < vec.size() - 1; i++) {
            if (vec[i] < 0 && vec[i+1] > 0) {
                swap(vec[i], vec[i+1]);
                flag = true;
            }
        }
    } while (flag);
}

vector<float> read_vec(istream &reader) {
    vector<float> out;
    while (!reader.eof() && reader.good()) {
        float i;
        reader >> i;
        out.push_back(i);
    }
    return out;
}

// 0.1 -0.1 0.4 4.0
int main() {
    ifstream inf("in.txt");
    if (!inf.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    vector<float> v = read_vec(inf);
    move_positive_first(v);
    cout << "Resulting vector: ";
    for (float f : v) {
        cout << f << " ";
    }
    cout << endl;
    return 0;
}