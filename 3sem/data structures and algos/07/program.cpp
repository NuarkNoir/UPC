// dsaa_07.cpp
// Горбацевич Андрей
#include <iostream>
#include <chrono>
#include <valarray>


inline void time_passed(std::chrono::high_resolution_clock::time_point start, double& holder) {
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    holder = duration.count();
}

class matrix {
private:
    int _rows = 0;
    int _cols = 0;
    std::valarray<int> data;

public:
    matrix()  = default;
    matrix(int32_t rows, int32_t cols) : _rows(rows), _cols(cols), data(rows*cols) {}

    int& operator()(int i, int j) {
        return this->data[i * this->_cols + j];
    }

    int operator()(int i, int j) const {
        return this->data[i * this->_cols + j];
    }

    [[nodiscard]] int cols() const {
        return this->_cols;
    }

    [[nodiscard]] int rows() const {
        return this->_rows;
    }
};

class levenstein{
private:
    std::string ls;
    std::string rs;

    matrix D;

public:
    levenstein(const std::string &ls, const std::string &rs) {
        this->ls = ls;
        this->rs = rs;
        this->D = matrix(ls.length() + 1, rs.length() + 1);

        D(0, 0) = 0;
        for (int j = 1; j <= D.cols(); j++) {
            D(0, j) = D(0, j - 1) + 1;
        }
        for (int i = 1; i <= D.rows(); i++) {
            D(i, 0) = D(i - 1, 0) + 1;
            for (int j = 1; j <= D.cols(); j++) {
                D(i, j) = std::min({
                    D(i - 1, j) + 1,
                    D(i, j - 1) + 1,
                    D(i - 1, j - 1) + (ls[i] == rs[j]? 0 : 2)
                });
            }
        }
    }

    int distance() {
        return this->D(ls.length(), rs.length());
    }

    void print() {
        printf("\t\t");
        for (int j = 0; j < D.cols(); j++) {
            printf("%c\t", rs[j]);
        }
        printf("\n");

        for (int i = 0; i < D.rows(); i++) {
            for (int j = 0; j < D.cols(); j++) {
                if (j == 0) {
                    if (i > 0) {
                        printf("%c\t", ls[i - 1]);
                    }
                    else {
                        printf("\t");
                    }
                }
                printf("%d\t", D(i, j));
            }
            printf("\n");
        }

        printf("\n");
    }
};

int main() {
    std::string f_word, s_word;
    std::cout << "Enter two words, separated by space symbol:\n";
    std::cin >> f_word >> s_word;

    double ellapsed_time = 0;
    auto start = std::chrono::high_resolution_clock::now();
    auto l = levenstein(f_word, s_word);
    time_passed(start, ellapsed_time);

    l.print();
    std::cout << l.distance() << " action(s) need to be done, found in " << 0 << " microseconds\n";

    return 0;
}
