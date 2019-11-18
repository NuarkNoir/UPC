// ac_9_27.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

inline int sign(int i) {
    return (i < 0? -1 : 1);
}

int count_sign_changes(const vector<int> &vec) {
    int c = 0;
    for (size_t i = 1; i < vec.size(); i++) {
        c += sign(vec[i-1]) != sign(vec[i]);
    }
    return c;
}

vector<int> read_vec(istream &reader) {
    vector<int> out;
    while (!reader.eof() && reader.good()) {
        int i;
        reader >> i;
        out.push_back(i);
    }
    return out;
}

// -5 1 1 -5 1
int main() {
    ifstream inf("in.txt");
    if (!inf.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    vector<int> v = read_vec(inf);
    int c = count_sign_changes(v);
    cout << "Count of changes: " << c << endl;
    return 0;
}