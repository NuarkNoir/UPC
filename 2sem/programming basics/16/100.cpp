// pb_16_100.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

enum scholarship {
    HI_ED = 0, SC_ED = 1, SV_RD = 2
};

struct DB_record {
    char surname[32];
    unsigned short age;
    char city[32];
    scholarship scs;

    bool operator < (const DB_record& rhs) const {
        string l = string(surname);
        transform(l.begin(), l.end(), l.begin(), [](unsigned char c){ return tolower(c); });
        string r = string(rhs.surname);
        transform(r.begin(), r.end(), r.begin(), [](unsigned char c){ return tolower(c); });
        return l < r;
    }
};

vector<DB_record> parseDB(ifstream &ifs);

int main() {
    string path_in = "in.txt"; // путь до входного файла
    string path_out = "out.bin"; // путь до выходного файла

    ifstream ifs(path_in);
    ofstream ofs(path_out, ios::binary);
    if (!ifs.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    vector<DB_record> records = parseDB(ifs);
    for (auto record : records) {
        ofs.write(reinterpret_cast<char*>(&record), sizeof(record));
    }

    ifs.close();
    ofs.close();

    vector<DB_record> records_fb;
    ifstream binfs(path_out, ios::binary);
    while (!binfs.eof() && !binfs.fail()) {
        DB_record record{};
        binfs.read(reinterpret_cast<char*>(&record), sizeof(record));
        if (record.age == 0) {
            continue;
        }
        records_fb.push_back(record);
    }
    sort(records_fb.begin(), records_fb.end());
    for (auto record : records_fb) {
        cout << record.surname << endl;
        cout << "\tAge: " << record.age << endl;
        cout << "\tCity: " << record.city << endl;
        cout << "\tScholarship: ";
        switch (record.scs) {
            case HI_ED:
                cout << "higher";
                break;
            case SC_ED:
                cout << "secondary";
                break;
            case SV_RD:
                cout << "secondary vocational";
                break;
        }
        cout << endl;
    }

    return 0;
}

vector<DB_record> parseDB(ifstream &ifs) {
    vector<DB_record> out;
    while (!ifs.fail() && !ifs.eof()) {
        DB_record record{};
        ifs >> record.surname;
        ifs >> record.age;
        ifs >> record.city;
        {
            string comp_str;
            ifs >> comp_str;
            if (comp_str[0] == '"') {
                string sub_comp_str;
                ifs >> sub_comp_str;
                comp_str += " " + sub_comp_str;
            }
            if (comp_str == "higher") {
                record.scs = HI_ED;
            }
            else if (comp_str == "secondary") {
                record.scs = SC_ED;
            }
            else if (comp_str == "\"secondary vocational\"") {
                record.scs = SV_RD;
            }
        }
        out.push_back(record);
    }
    return out;
}
