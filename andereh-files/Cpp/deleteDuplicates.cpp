#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printListNode(ListNode* head) {
    if (head == nullptr) return;

    cout << head->val << " ";
    printListNode(head->next);
}

// revursiva
// void deleteDuplicates(ListNode* head) {
// if (head == nullptr || head->next == nullptr) return;

// if (head->val == head->next->val) {
// if (head->next->next == nullptr)
// head->next = nullptr;
// else {
// head->next = head->next->next;
// deleteDuplicates(head);
//}
//}

// deleteDuplicates(head->next);
//}
ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return head;

    ListNode* dummyHead = head;

    while (dummyHead->next != nullptr) {
        if (dummyHead->val == dummyHead->next->val) {
            dummyHead->next = dummyHead->next->next;
        } else
            dummyHead = dummyHead->next;
    }
    return head;
}

int main(int argc, char* argv[]) {
    ListNode a(2);
    ListNode b(1, &a);
    ListNode c(1, &b);
    ListNode d(1, &c);
    ListNode e(1, &d);
    ListNode f(1, &e);
    ListNode g(1, &f);

    printListNode(&g);
    cout << '\n';

    deleteDuplicates(&g);
    printListNode(&g);
    return 0;
}

