// ac_8_26.cpp
// Горбацевич Андрей
#include <iostream>
#include <vector>
using namespace std;

vector<int> count_less(const vector<int> &vec, int h) {
    vector<int> v;
    v.reserve(vec.size());
    for (size_t c = 0; c < vec.size(); c++) {
        if (vec[c] < h) {
            v.push_back(c);
        }
    }
    return v;
}

int main() {
    int N;
    cout << "N >>>";
    cin >> N;
    vector<int> heights;
    heights.reserve(N);
    cout << "heights[...] >>>";
    for (int i = 0; i < N; i++) {
        int j;
        cin >> j;
        heights.push_back(j);
    }
    int h;
    cout << "h >>>";
    cin >> h;
    vector<int> nv = count_less(heights, h);
    cout << "Lesser indexes: ";
    for (int ch : nv) {
        cout << ch << " ";
    }
    cout << endl;
    return 0;
}