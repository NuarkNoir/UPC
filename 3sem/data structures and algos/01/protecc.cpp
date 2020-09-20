// dsaa_01_prot.cpp
// Горбацевич Андрей
#include <iostream>
#include <map>

#ifdef DEBUG
#define printf_d printf
#else
#define printf_d(...);
#endif

class FS {
public:
    typedef double long_type;

    long_type sum_factor(int N) {
        long_type sum = 1;
        this->find_val(N, sum);
        return sum;
    }

private:
    std::map<int, long_type> cache_vals = { {0, 0} };
    void find_val(int N, long_type &out) {  // O(log(cache_vals.size()))^2)
        auto it = this->cache_vals.find(N);  // O(log(cache_vals.size())))
        if (it == this->cache_vals.end()) {
            printf_d("[Need to calculate sum(1..%d)!]\n", N);
            long_type _out, _fac;
            this->find_val(N-1, _out);
            this->find_factorial(N, _fac);
            out = _out + _fac;
            cache_vals[N] = out;  // O(log(cache_vals.size())))
        }
        else {
            out = it->second;
        }
    }

    std::map<int, long_type> cache_factorials = { {0, 1} };
    void find_factorial(int N, long_type &out) {  // O(log(cache_factorials.size()))^2)
        auto it = this->cache_factorials.find(N);  // O(log(cache_factorials.size())))
        if (it == this->cache_factorials.end()) {
            printf_d("[Need to calculate %d!]\n", N);
            long_type _out;
            this->find_factorial(N-1, _out);
            out = _out * N;
            cache_factorials[N] = out;  // O(log(cache_factorials.size())))
        }
        else {
            out = it->second;
        }
    }
};

int main() {
    FS _fs;

    do {
        int i;
        std::cout << "N=";
        std::cin >> i;

        if (i == 0) {
            std::cout << "Goodbye" << std::endl;
            break;
        }

        std::cout << "sum (i=1..N) N! = " << _fs.sum_factor(i) << std::endl;
    } while (true);

    return 0;
}


