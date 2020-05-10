// pb_18_100.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstring>

class DB_record {
    std::string surname = "";
    unsigned short age = 0;
    std::string city = "";
    enum scholarship {
        HI_ED = 0, SC_ED = 1, SV_RD = 2
    } scs = SV_RD;

public:
    DB_record() = default;

    void load_txt(std::istream &ist) {
        ist >> this->surname;
        if (this->surname.length() > 32) {
            this->surname = this->surname.substr(0, 32);
        }
        ist >> this->age;
        ist >> this->city;
        if (this->city.length() > 32) {
            this->city = this->city.substr(0, 32);
        }
        {
            std::string comp_str;
            ist >> comp_str;
            if (comp_str[0] == '"') {
                std::string sub_comp_str;
                ist >> sub_comp_str;
                comp_str += " " + sub_comp_str;
            }
            if (comp_str == "higher") {
                this->scs = HI_ED;
            }
            else if (comp_str == "secondary") {
                this->scs = SC_ED;
            }
            else if (comp_str == "\"secondary vocational\"") {
                this->scs = SV_RD;
            }
        }
    }

    void load_bin(std::istream &ist) {
        struct wrapper {
            char _surname[32];
            unsigned short _age;
            char _city[32];
            scholarship _scs;
        } wr{};
        ist.read(reinterpret_cast<char*>(&wr), sizeof(wrapper));

        this->surname = std::string(wr._surname);
        this->age = wr._age;
        this->city = std::string(wr._city);
        this->scs = wr._scs;
    }

    void save_bin(std::ostream &ost) const {
        struct wrapper {
            char _surname[32];
            unsigned short _age;
            char _city[32];
            scholarship _scs;
        } wr{};
        std::strcpy(wr._surname, this->surname.c_str());
        wr._age = this->age;
        std::strcpy(wr._city, this->city.c_str());
        wr._scs = this->scs;

        ost.write(reinterpret_cast<char*>(&wr), sizeof(wrapper));
    }

    static void print_table_head(std::ostream &ost) {
        ost.setf(std::ios::left);
        ost << std::string(102, '=') << std::endl;
        ost << std::setw(34) << "| surname";
        ost << std::setw(8) << " | age";
        ost << std::setw(35) << " | city";
        ost << std::setw(23) << " | scholarship" << " |\n";
        ost << std::string(102, '=') << std::endl;
    }

    void print_table_row(std::ostream &ost) const {
        ost.setf(std::ios::left);
        ost << "| " << std::setw(32) << this->surname;
        ost << " | " << std::setw(5) << this->age;
        ost << " | " << std::setw(32) << this->city;
        ost << " | " << std::setw(20);
        switch (this->scs) {
            case HI_ED:
                ost << "higher";
                break;
            case SC_ED:
                ost << "secondary";
                break;
            case SV_RD:
                ost << "secondary vocational";
                break;
        }
        ost << " |\n";
    }

    bool validate() {
        return this->surname.length() > 0 && this->age > 0 && this->city.length() > 0;
    }
};

typedef std::vector<DB_record> Database;

std::size_t print_table(const Database &data, std::ostream &ost) {
    std::size_t c = 0;
    DB_record::print_table_head(ost);
    for (const auto& rec : data) {
        rec.print_table_row(ost);
        c++;
    }
    return c;
}

std::size_t load_txt(Database &data, std::istream &ist) {
    std::size_t c = 0;
    while (!ist.fail() && !ist.eof()) {
        DB_record record{};
        record.load_txt(ist);
        if (record.validate()) {
            data.push_back(record);
            c++;
        }
    }
    return c;
}

std::size_t load_bin(Database &data, std::istream &ist) {
    std::size_t c = 0;
    while (!ist.fail() && !ist.eof()) {
        DB_record record{};
        record.load_bin(ist);
        if (record.validate()) {
            data.push_back(record);
            c++;
        }
    }
    return c;
}

std::size_t save_bin(const Database &data, std::ostream &ost) {
    std::size_t c = 0;
    for (const auto& rec : data) {
        rec.save_bin(ost);
        c++;
    }
    return c;
}

void first_mode(std::string &path_in, std::string &path_out) {
    std::ifstream ist(path_in);
    std::ofstream ost(path_out, std::ios::binary);
    if (!ist.is_open())
    {
        std::cerr << "Unable to open file" << std::endl;
    }
    else {
        Database db;
        std::size_t trrc = load_txt(db, ist);
        std::cout << "Read " << trrc << " rows from txt\n";
        std::size_t prc = print_table(db, std::cout);
        std::cout << "Print " << prc << " rows from db\n";
        std::size_t brwc = save_bin(db, ost);
        std::cout << "Write " << brwc << " rows to bin\n";
    }
    ist.close();
    ost.close();
}

void second_mode(std::string &path_in) {
    std::ifstream ist(path_in, std::ios::binary);
    if (!ist.is_open())
    {
        std::cerr << "Unable to open file" << std::endl;
    }
    else {
        Database db;
        std::size_t brrc = load_bin(db, ist);
        std::cout << "Read " << brrc << " rows from bin\n";
        std::size_t prc = print_table(db, std::cout);
        std::cout << "Print " << prc << " rows from db\n";
    }
    ist.close();
}

int main() {
    std::string path_in = "in.txt"; // путь до входного файла
    std::string path_out = "out.bin"; // путь до выходного файла

    std::cout << "Select working mode:\n\t1. First mode\n\t2. Second mode\n>>> ";
    int mode;
    std::cin >> mode;
    switch (mode) {
        case 1:
            first_mode(path_in, path_out);
            break;
        case 2:
            second_mode(path_out);
            break;
        default:
            std::cerr << "WRONG MODE SELECTED. SHOULD BE 1 OR 2\n";
            break;
    }

    return 0;
}

