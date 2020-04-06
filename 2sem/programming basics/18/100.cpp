// pb_18_100.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <ctime>

#ifdef NDEVENV
#define dfunc(func) {func;}
#else
#define dfunc(func)
#endif

struct Node {
    int data;
    Node *next = nullptr;
    Node *prev = nullptr;

    explicit Node(int d) : data(d) {};

    ~Node() {
        delete next;
        next = nullptr;
        prev = nullptr;
    }
};

struct BiLinkedList {
    int len = 0;
    Node *first = nullptr;
    Node *last = nullptr;

    ~BiLinkedList() {
        delete first;
        first = nullptr;
        last = nullptr;
    }

    void push_node(Node *n) {
        if (this->last == this->first) {
            if (this->last == nullptr) {
                this->first = this->last = n;
            }
            else {
                this->first->next = n;
                n->prev = this->first;
                this->last = n;
            }
        }
        else {
            n->prev = this->last;
            this->last->next = n;
            this->last = n;
        }

        this->len += 1;
    }

    void prepend_node(Node *n, Node *before) {
        if (before == nullptr) {
            this->push_node(n);
        }
        else if (before == this->first) {
            n->next = this->first;
            this->first = n;
        }
        else {
            n->next = before;
            n->prev = before->prev;
            n->prev->next = n;
            n->next->prev = n;
        }

        this->len += 1;
    }

    void remove_at(int pos) {
        if (pos > this->len || pos < 0 || this->len <= 0) {
            return;
        }
        Node *cn = nullptr;
        if (this->len == 1) {
            this->first->next = nullptr;
            delete this->first;
        }
        else if (pos == 0) {
            cn = this->first;
            cn->next->prev = nullptr;
            this->first = cn->next;
        }
        else if (pos == this->len - 1) {
            cn = this->last;
            cn->prev->next = nullptr;
            this->last = cn->prev;
        }
        else if (pos > this->len/2) {
            int cpos = len - 1;
            cn = this->last;
            while (cpos != pos) {
                cn = cn->prev;
                cpos -= 1;
            }
            cn->prev->next = cn->next;
            cn->prev = cn->prev;
        }
        else {
            int cpos = 0;
            cn = this->first;
            while (cpos != pos) {
                cn = cn->next;
                cpos += 1;
            }
            cn->prev->next = cn->next;
            cn->prev = cn->prev;
        }

        if (cn != nullptr) {
            cn->next = cn->prev = nullptr;
            delete cn;
        }

        this->len -= 1;
        if (this->len == 0) {
            this->first = this->last = nullptr;
        }
    }

    void print_list(std::ostream &ost) {
        auto cn = this->first;
        while (cn != nullptr) {
            ost << cn->data << " ";
            cn = cn->next;
        }
    }

    void print_list_rev(std::ostream &ost) {
        auto cn = this->last;
        while (cn != nullptr) {
            ost << cn->data << " ";
            cn = cn->prev;
        }
    }
};

int main() {
    srand(time(nullptr)+0);
    std::string path_in = "in.txt"; // путь до входного файла

    BiLinkedList list;

    std::ifstream ifs(path_in);
    if (!ifs.is_open())
    {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    // possible input: 12 11 19 91 91 120 19 19 11 19 12 300
    { // водим данные в список
        while (!ifs.eof() && !ifs.fail()) {
            int i;
            ifs >> i;
            list.push_node(new Node(i));
        }
    }

    dfunc(printf("Size: %d; [", list.len));
    dfunc(list.print_list(std::cout));
    dfunc(printf("]\n"));

    // possible output: 12 6 6 11 12 1 11 19 91 91 120 7 53 5 95
    //                  122 19 19 11 19 12 1 9 5 4 12 300 219 139 269 165 87
    { // выполняем задание
        auto cn = list.first;
        while (cn != nullptr) {
            if (cn->data % std::to_string(cn->data).length() == 0) {
                list.prepend_node(new Node(rand() % (cn->data + 3)), cn->next);
                list.prepend_node(new Node(rand() % (cn->data + 3)), cn->next);
                list.prepend_node(new Node(rand() % (cn->data + 3)), cn->next);
                list.prepend_node(new Node(rand() % (cn->data + 3)), cn->next);
                list.prepend_node(new Node(rand() % (cn->data + 3)), cn->next);
                cn = cn->next->next->next->next->next;
            }
            cn = cn->next;
        }
    }

    for (;;) {
        printf("Size: %d; [", list.len);
        list.print_list(std::cout);
        printf("]\n");

        printf("Delete element at (`-1` - to exit) >>>");
        int pos;
        scanf("%d", &pos);
        if (pos == -1) {
            break;
        }
        list.remove_at(pos);
    }

    printf("Straight order: ");
    list.print_list(std::cout);
    printf("\nReversed order: ");
    list.print_list_rev(std::cout);
    printf("\n");

    return 0;
}