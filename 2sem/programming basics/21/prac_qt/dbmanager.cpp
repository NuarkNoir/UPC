// pb_21_100.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <QtCore/QTextStream>

namespace nuark {
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

        static void print_table_head(QTextStream &ost) {
            auto ss = std::stringstream();
            ss.setf(std::ios::left);
            ss << std::string(102, '=') << std::endl;
            ss << std::setw(34) << "| surname";
            ss << std::setw(8) << " | age";
            ss << std::setw(35) << " | city";
            ss << std::setw(23) << " | scholarship" << " |\n";
            ss << std::string(102, '=') << std::endl;

            ost << ss.str().c_str();
        }

        void print_table_row(QTextStream &ost) const {
            auto ss = std::stringstream();
            ss.setf(std::ios::left);
            ss << "| " << std::setw(32) << this->surname;
            ss << " | " << std::setw(5) << this->age;
            ss << " | " << std::setw(32) << this->city;
            ss << " | " << std::setw(20);
            switch (this->scs) {
                case HI_ED:
                    ss << "higher";
                    break;
                case SC_ED:
                    ss << "secondary";
                    break;
                case SV_RD:
                    ss << "secondary vocational";
                    break;
            }
            ss << " |\n";
            auto t = ss.str();
            ost << ss.str().c_str();
        }

        bool validate() {
            return this->surname.length() > 0 && this->age > 0 && this->city.length() > 0;
        }
    };

    struct DBManager {
        typedef std::vector<DB_record> Database;

        std::size_t print_table(const Database &data, QTextStream &ost) {
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

        void first_mode(const QString &path_in, const QString &path_out, QTextStream &stream) {
            std::ifstream ist(path_in.toStdString());
            std::ofstream ost(path_out.toStdString(), std::ios::binary);
            if (!ist.is_open())
            {
                stream << "Unable to open `" << path_in << "`\n";
            }
            else {
                Database db;
                std::size_t trrc = load_txt(db, ist);
                stream << "Read " << trrc << " rows from txt\n";
                std::size_t prc = print_table(db, stream);
                stream << "Print " << prc << " rows from db\n";
                std::size_t brwc = save_bin(db, ost);
                stream << "Write " << brwc << " rows to bin\n";
            }
            ist.close();
            ost.close();
        }

        void second_mode(const QString &path_in, QTextStream &stream) {
            std::ifstream ist(path_in.toStdString(), std::ios::binary);
            if (!ist.is_open())
            {
                stream << "Unable to open `" << path_in << "`\n";
            }
            else {
                Database db;
                std::size_t brrc = load_bin(db, ist);
                stream << "Read " << brrc << " rows from bin\n";
                std::size_t prc = print_table(db, stream);
                stream << "Print " << prc << " rows from db\n";
            }
            ist.close();
        }
    };
}
