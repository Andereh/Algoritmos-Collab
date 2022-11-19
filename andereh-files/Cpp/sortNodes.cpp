#include <stdio.h>

// Programa para ordenar colas

struct ListNode {  // Definicion de la cola
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// El nombre del la funcion habla por si sola (recursion)
void printListNode(ListNode* head) {
    if (head == nullptr) return;

    printf("%d ", head->val);
    printListNode(head->next);
}

// Para validar que la cola este ordenada (iteracion)
int is_sort(ListNode* head) {
    if (head == nullptr) return 1;

    while (head->next != nullptr) {
        if (head->val > head->next->val) return 0;
        head = head->next;
    }

    return 1;
}

// Ordenamos la cola (iteracion)
void sortNodes(ListNode* head) {
    if (head == nullptr) return;

    ListNode* dummyHead;  // variable para no perder la raiz

    while (!is_sort(head)) {
        dummyHead = head;  // comenzamos desde la raiz

        while (dummyHead->next != nullptr) {
            // si el valor del nodo actual es mayor al valor del siguiente nodo
            if (dummyHead->val > dummyHead->next->val) {
                // cambiamos los valores
                int aux = dummyHead->val;
                dummyHead->val = dummyHead->next->val;
                dummyHead->next->val = aux;
            }

            // continuamos con el siguiente nodo
            dummyHead = dummyHead->next;
        }
    }
}

int main(int argc, char* argv[]) {
    ListNode a(5);
    ListNode b(1, &a);
    ListNode c(3, &b);
    ListNode d(7, &c);
    ListNode e(2, &d);

    printListNode(&e);
    printf("\n");

    sortNodes(&e);
    printListNode(&e);
    return 0;
}

