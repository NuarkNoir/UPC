// ac_9_28.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

float nearest_int_dist(float x) {
    return abs(round(x) - x);
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
    size_t index = 0;
    float smallest = v[index];
    for (size_t i = 1; i < v.size(); i++) {
        if (nearest_int_dist(v[i]) < smallest) {
            smallest = nearest_int_dist(v[i]);
            index = i;
        }
    }
    cout << "Nearest to decimal form: " << v[index] << endl;
    return 0;
}