// dsaa_03.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cmath>
#include <cassert>
#include <algorithm>

#undef IS_BIN_REQUIRED


inline void time_passed(std::chrono::system_clock::time_point start, double &holder) {
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    holder = duration.count();
}

typedef long long num_type;
typedef std::vector<num_type> num_list;

void test(const std::string& filename, int num);
void algo_01(const num_list &cont, const num_type &num, num_type &found);  // linear search
void algo_02(const num_list &cont, const num_type &num, num_type &found);  // interpolating search


int main() {
    for (auto num : {68, 288, 610, 666, 665, 73720, 95210, 99998, 0, -1}) {
        test("tests/snba1.txt", num);
    }

    for (auto num : {68, 288, 610, 666, 665, 73720, 95210, 99999, 1, 0}) {
        test("tests/snba2.txt", num);
    }

    for (auto num : {3, 69, 610, 6666, 6656, 73720, 95210, 99999, 0, 2}) {
        test("tests/snbb1.txt", num);
    }

    for (auto num : {3, 69, 610, 6666, 6656, 73720, 95210, 99998, 1, 0}) {
        test("tests/snbb2.txt", num);
    }

    for (auto num : {3, 69, 610, 6666, 6656, 73720, 95210, 99991, 1, 99999}) {
        test("tests/snbc1.txt", num);
    }

    for (auto num : {3, 69, 610, 6666, 6656, 73720, 95210, 99999, 4, 1}) {
        test("tests/snbc2.txt", num);
    }

    for (auto num : {1, 2, 3, 4}) {
        test("tests/snla1.txt", num);
        test("tests/snla2.txt", num);
        test("tests/snlb1.txt", num);
        test("tests/snlb2.txt", num);
        test("tests/snlc1.txt", num);
        test("tests/snlc2.txt", num);
    }

    return 0;
}

void test(const std::string& filename, int num) {
    std::ifstream data_file(filename);
    int elc;
    data_file >> elc;

    num_list data(elc);
    for (int i = 0; i < elc; i++) {
        data_file >> data[i];
    }

    double fft, sft = fft = 0;
    num_type fff, sff = fff = -1;

    {
        auto start = std::chrono::high_resolution_clock::now();
        algo_01(data, num, fff);
        time_passed(start, fft);
    }
    {
        auto start = std::chrono::high_resolution_clock::now();
        algo_02(data, num, sff);
        time_passed(start, sft);
    }
    {
        assert(fff == sff);
    }

    printf(
            "algo_01 is %s than algo_02 by %.0f microseconds\nFound %d at: %s in %s\n\n",
            (fft > sft? "slower" : "faster"), fabs(fft - sft), num,
            (fff == -1? "not found" : std::to_string(fff).c_str()), filename.c_str()
    );
}

void algo_01(const num_list &cont, const num_type &num, num_type &found) {  // O(n)
    for (int i = 0; i < cont.size(); i++) {
        num_type item = cont[i];
        if (item == num) {
            found = i;
            break;
        }
    }
}

void algo_02(const num_list &cont, const num_type &num, num_type &found) {  // O(log(log(n))); worst O(n)
    num_type c,
            l = 0,
            r = cont.size()-1;
    while (cont[l] < num && cont[r] > num) {
        num_type rv = cont[r];
        num_type lv = cont[l];
        if (rv == lv) {
            break;
        }

#ifdef IS_BIN_REQUIRED
        c = (l + r) / 2;
#else
        c = l + ((num - lv) * (r - l)) / (rv - lv);
#endif
        if (cont[c] < num) {
            l = c + 1;
        }
        else if (cont[c] > num) {
            r = c - 1;
        }
        else {
            found = c;
            return;
        }
    }

    if (cont[l] == num) {
        found = l;
    }
    else if (cont[r] == num) {
        found = r;
    }
}
