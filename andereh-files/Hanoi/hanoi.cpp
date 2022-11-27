#include <cstdio>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* last = this;
    ListNode* prev = nullptr;
    string name;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode a;
ListNode b;
ListNode c;

void addNode(ListNode* node, int valToAppend) {
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));

    temp->val = valToAppend;
    temp->prev = node->last;

    if (node->last == nullptr) {
        node->next = temp;
        node->last = node->next;
        node->prev = node;
        return;
    }

    node->last->next = temp;
    node->last = node->last->next;
}

void changeNode(ListNode* from, ListNode* to) {
    addNode(to, from->last->val);
    from->last = from->last->prev;
    from->last->next = NULL;

    // from->last = from->last->prev;
    // from->last->next = nullptr;
}

void printListNode(ListNode* node) {
    if (node == NULL) return;

    if (node->val != 0) cout << node->val << " ";

    printListNode(node->next);
}

// logica
void moveDisc(ListNode* from, ListNode* to) {
    // printListNode(from);
    system("clear");
    cout << "\033[1;36m-----------------------------\033[0m\n";
    cout << " Mover disco desde " << from->name << " hasta " << to->name
         << '\n';
    changeNode(from, to);
    cout << " A: ";
    printListNode(&a);
    cout << "\n B: ";
    printListNode(&b);
    cout << "\n C: ";
    printListNode(&c);
    cout << '\n';
    getc(stdin);
}
void moveTower(int n, ListNode* origin, ListNode* destiny, ListNode* aux) {
    if (n > 0) {
        moveTower(n - 1, origin, aux, destiny);
        moveDisc(origin, destiny);
        moveTower(n - 1, aux, destiny, origin);
    }
}

int main(int argc, char* argv[]) {
    a.name = "A";
    b.name = "B";
    c.name = "C";

    int n;
    system("clear");
    cout << " Este programa te muestra como resolver las torres de Hanoi\n";
    cout << " Con cuantos discos te gustaria jugar?: ";
    cin >> n;
    for (int i = n; i > 0; --i) {
        addNode(&a, i);
    }

    moveTower(n, &a, &c, &b);
    return 0;
}

