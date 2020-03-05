// pb_17_100.cpp
// Горбацевич Андрей
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node *sibling = nullptr;

    explicit Node(int d) : data(d) {};

    ~Node() {
        delete sibling;
        cout << "destructor for Node{" << data << "}\n";
    }
};

struct SinglyLinkedList {
    int len = 0;
    Node *first = nullptr;

    ~SinglyLinkedList() {
        delete first;
        cout << "destructor for List[" << len << "]\n";
    }
};

void push_to_list(Node* par, Node* node) {
    if (par->sibling == nullptr) {
        par->sibling = node;
    }
    else {
        push_to_list(par->sibling, node);
    }
}

void print_list(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->sibling;
    }
}

Node* insert_to_list_at(SinglyLinkedList* list, int at, Node* node) {
    if (list->len < at) {
        cerr << "Out of list bounds access exception: list size is ";
        cerr << list->len << " and position is " << at << endl;
        exit(-1);
    }
    //INFO: shitty workaround
    list->len++;
    if (at == 0) {
        node->sibling = list->first;
        list->first = node;
        return list->first;
    }
    Node *n = list->first;
    for (int i = 0; i < at-1; i++) {
        n = n->sibling;
    }
    if (n->sibling != nullptr) {
        node->sibling = n->sibling;
        n->sibling = node;
    }
    else {
        n->sibling = node;
    }
    return n->sibling;
}

int main() {
    srand(time(nullptr)+0);

    string path_in = "in.txt"; // путь до входного файла

    ifstream ifs(path_in);
    if (!ifs.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    auto list = new SinglyLinkedList();

    {
        Node *prev_ptr = nullptr;
        while (!ifs.eof() && !ifs.fail()) {
            int i;
            ifs >> i;
            auto node = new Node(i);
            if (list->first == nullptr) {
                list->first = node;
                prev_ptr = list->first;
            }
            else {
                push_to_list(prev_ptr, node);
                prev_ptr = prev_ptr->sibling;
            }
            list->len++;
        }
    }

    print_list(list->first);
    cout << endl;

    {
        Node *prev_ptr = list->first;
        int i = 0;
        while (prev_ptr != nullptr) {
            if (!(prev_ptr->data % to_string(prev_ptr->data).length())) {
                for (int _i = 0; _i < 5; _i++) {
                    int num = rand() % 100;
                    auto node = new Node(num);
                    insert_to_list_at(list, i++, node);
                }
            }
            else {
                i++;
            }

            prev_ptr = prev_ptr->sibling;
        }
    }

    print_list(list->first);
    cout << endl;

    delete list;
    return 0;
}
