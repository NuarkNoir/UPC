// pb_14_100.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <string>
#define MAX_STRING 1000

using namespace std;

void my_task(istream &ist, ostream &ost);

int main()
{
    ifstream inf("in.txt");
    ofstream fout("out.txt", ios::trunc);
    if (!inf.is_open() || !fout.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }
	
	my_task(inf, fout);
}

void my_task(istream &ist, ostream &ost) {
	while (!ist.eof() && ist.good()) {
		string r;
		getline(ist, r);
		size_t i;
		while ((i = r.find("YES")) != string::npos) {
			r.replace(i, 3, "NO");
		}
		ost << r << endl;
	}
}
