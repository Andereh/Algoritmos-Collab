#include <iostream>

using namespace std;

struct node_t {
    string data;
    node_t* next;

    node_t() : data(""), next(nullptr) {}
    node_t(string data) : data(data), next(nullptr) {}
    node_t(string data, node_t* next) : data(""), next(next) {}
};

node_t* search(node_t* head, string str) {
    while (head != NULL) {
        if (head->data == str) return head;
        head = head->next;
    }

    return NULL;
}

void append(node_t* head, string str) {
    if (head == NULL) return;

    while (head->next != NULL) {
        head = head->next;
    }

    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = str;

    head->next = newNode;
}

void pop(node_t* head) {
    if (head == NULL) return;

    pop(head->next);
}

void printListNode(node_t* head) {
    if (head == NULL) return;

    cout << head->data << " ";

    printListNode(head->next);
}

int main(int argc, char* argv[]) {
    node_t tail("ramon");

    append(&tail, "jose");
    append(&tail, "juan");

    printListNode(&tail);
    cout << "\n";
    pop(&tail);
    printListNode(&tail);

    // cout << search(&tail, "ramon")->data;
    return 0;
}
