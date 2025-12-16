#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
    int data;
    IntList next;
};

// Date due liste l1 e l2, crea una nuova lista prendendo un nodo da l1, poi uno da l2, poi uno da l1,
// e così via. I nodi residui della lista più lunga vengono aggiunti in coda.

IntList newNode(int n, IntList next) {
    IntList node = malloc(sizeof(IntNode));
    if (!node) {
        return NULL;
    }

    node->data = n;
    node->next = next;
    return node;
}

void printList(IntList list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
}

void freeList(IntList list) {
    while (list != NULL) {
        IntList temp = list;
        list = list->next;
        free(temp);
    }
}

IntList zip_lists(IntList l1, IntList l2) {

    IntList head = NULL;
    IntList tail = NULL;

    while (l1 != NULL || l2 != NULL) {

        if (l1 != NULL) {
            IntList node = malloc(sizeof(IntNode));
            if (!node) {
                freeList(head);
                return NULL;
            }
            node->data = l1->data;
            node->next = NULL;

            if (head == NULL) {
                head = node;
                tail = node;
            }

            else {
                tail->next = node;
                tail = node;
            }
            l1 = l1->next;
        }

        if (l2 != NULL) {
            IntList node = malloc(sizeof(IntNode));
            if (!node) {
                freeList(head);
                return NULL;
            }
            node->data = l2->data;
            node->next = NULL;

            if (head == NULL) {
                head = node;
                tail = node;
            }

            else {
                tail->next = node;
                tail = node;
            }
            l2 = l2->next;
        }
    }
    return head;
}

int main() {
    IntList l1 = newNode(1, newNode(3, newNode(5, NULL)));
    IntList l2 = newNode(2, newNode(4, newNode(6, newNode(8, newNode(10, NULL)))));

    IntList res = zip_lists(l1, l2);

    if (res != NULL) {
        printf("Lista 1: ");
        printList(l1);
        printf("\n");

        printf("Lista 2: ");
        printList(l2);
        printf("\n");

        printf("Lista Zip: ");
        printList(res);
    }

    else {
        printf("Errore");
        return 1;
    }
    freeList(l1);
    freeList(l2);
    freeList(res);
    return 0;
}