// pb_12_100.cpp
// Горбацевич Андрей
#include <iostream>

using namespace std;

void print_mtx(int **mtx, int w, int h);
int **generate_mtx(int n);

int main()
{
	int n;
	cout << "n >>>";
	cin >> n;
	int **mtx = generate_mtx(n);
	print_mtx(mtx, n, n);
}

void print_mtx(int **mtx, int w, int h) {
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			cout << *(*(mtx + i) + j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int **generate_mtx(int n) {
	int **mtx = new int*[n];
	for (int i = 0; i < n; i++) {
		int *row = new int[n]();
		int pos = n;
		for (int j = -n+i; j < 0; j++) {
			*(row + pos--) = abs(j);
		}
		for (int j = 0; pos >= 0; j++) {
			*(row + pos--) = abs(j);
		}
		*(mtx + i) = row;
	}
	return mtx;
}
