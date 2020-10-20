// dsaa_05.cpp
// Горбацевич Андрей
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <cassert>
#include <algorithm>


inline void time_passed(std::chrono::system_clock::time_point start, double &holder) {
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    holder = duration.count();
}

typedef double num_type;
typedef std::vector<num_type> num_list;

void test();
void algo_01(num_list &cont);  // Stupid sort
void algo_02(num_list &cont);  // Shell sort


int main() {
    test();

    return 0;
}

void test() {
    int n;
    std::cout << "Count of items:\n";
    std::cin >> n;
    num_list data;
    data.reserve(n);
    for (int i = 0; i < n; i++) {
        int d;
        std::cin >> d;
        data.push_back(d);
    }


    num_list copy_1(data);
    num_list copy_2(data);

    double fft, sft = fft = 0;

    {
        auto start = std::chrono::high_resolution_clock::now();
        algo_01(copy_1);
        time_passed(start, fft);
    }
    {
        auto start = std::chrono::high_resolution_clock::now();
        algo_02(copy_2);
        time_passed(start, sft);
    }
    {
        assert(copy_1 == copy_2);
    }

    printf(
            "algo_01 (%.0f) is %s than algo_02 (%.0f) by %.0f microseconds\n",
            fft, (fft > sft? "slower" : "faster"), sft, fabs(fft - sft)
    );
}

void algo_01(num_list &cont) {  // Stupid sort
    auto vit_b = cont.begin() + 1;

    while (vit_b != cont.end()) {
        auto vit_p = vit_b - 1;
        if (*vit_p > *vit_b) {
            std::swap(*vit_p, *vit_b);
            vit_b = cont.begin() + 1;
        }
        else {
            vit_b += 1;
        }
    }
}

void algo_02(num_list &cont) {  // Shell sort
    auto vit_first = cont.begin();
    auto vit_last = cont.end();
    for(auto d = (vit_last - vit_first) / 2; d != 0; d /= 2) {
        for(auto i = vit_first + d; i != vit_last; ++i) {
            for(auto j = i; j - vit_first >= d; j -= d) {
                if (*j < *(j - d)) {
                    std::swap( *j, *( j - d ) );
                }
            }
        }
    }
}
