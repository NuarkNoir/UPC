// ac_8_24.cpp
// Горбацевич Андрей
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> two_mins(const vector<int> &vec) {
    vector<int> v = vec;
    sort(begin(v), end(v));
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
    vector<int> nv = two_mins(v);
    cout << "Two minimals is " << nv[0] << " and " << nv[1] << endl;
    return 0;
}