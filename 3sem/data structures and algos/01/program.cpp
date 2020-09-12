// dsaa_01.cpp
// Горбацевич Андрей
#include <iostream>
#include <cmath>
#include <chrono>

typedef double long_type;

void time_passed(std::chrono::system_clock::time_point start, long_type& holder);
void test(int N);
void algo_01(int N, long_type& out_val);  // Naive way
void algo_02(int N, long_type& out_val);  // Somewhat efficient way

int main() {
    int i;
    std::cout << "N=";
    std::cin >> i;

    test(i);

    return 0;
}

inline void time_passed(std::chrono::system_clock::time_point start, long_type& holder) {
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    holder = duration.count();
}

void test(int N) {
    long_type fft, sft = fft = 0;
    long_type ffv, sfv = ffv = 0;

    {
        auto start = std::chrono::high_resolution_clock::now();
        algo_01(N, ffv);
        time_passed(start, fft);
    }
    {
        auto start = std::chrono::high_resolution_clock::now();
        algo_02(N, sfv);
        time_passed(start, sft);
    }

    printf(
        "algo_01 is %s than algo_02 by %.0f microseconds (%.0f against %.0f; N=%d; %.0f; %.0f)\n"
        "Sum of i! from 1 to %d = %.0f",
        (fft > sft? "slower" : "faster"), fabs(fft - sft), fft, sft, N, ffv, sfv, N, ffv
    );
}

void algo_01(int N, long_type& out_val) {  // O(N^2)
    long_type sum = 0;

    for (int k = 1; k <= N; k++) {  // O(N)
        long_type acc = 1;
        for (int i = 1; i <= k; i++) {  // O(N)
            acc *= i;
        }
        sum += acc;
    }

    out_val = sum;
}

void algo_02(int N, long_type& out_val) {  // O(N)
    long_type sum = 0;
    long_type acc = 1;

    for (int k = 1; k <= N; k++) {  // O(N)
        sum += (acc *= k);
    }

    out_val = sum;
}
// Вычислить суммы факториалов K первых целых чисел для K=1..N
