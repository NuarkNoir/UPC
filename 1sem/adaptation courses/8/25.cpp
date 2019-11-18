// ac_8_25.cpp
// Горбацевич Андрей
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> max_diff(const vector<int> &vec) {
    vector<int> v = vec;
    sort(begin(v), end(v));\
    swap(*(v.end() - 1), v[1]);
    v.resize(2);
    return v;
}

int main() {
    int N;
    cout << "N >>>";
    cin >> N;
    vector<int> v;
    v.reserve(N);
    cout << "v[...] >>>";
    for (int i = 0; i < N; i++) {
        int j;
        cin >> j;
        v.push_back(j);
    }
    vector<int> nv = max_diff(v);
    cout << "Biggest diff is between " << nv[0] << " and " << nv[1] << " (eq. " << nv[0] - nv[1] << ")" << endl;
    return 0;
}