#include <stdio.h>
#include <stdlib.h>

//Date le liste src, dispari, pari, sposta i nodi di src nelle altre liste in base alla posizione
//dove il primo nodo corrisponde alla posizione 1

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef Node* NodePtr;

typedef struct List {
    NodePtr head;
    NodePtr tail;
} List;

typedef List* ListPtr;

void split_reverse_positions(ListPtr src, ListPtr pari, ListPtr dispari) {
    pari->head = NULL;
    pari->tail = NULL;

    dispari->head = NULL;
    dispari->tail = NULL;

    NodePtr curr = src->head;
    int pos = 1;

    while(curr != NULL) {
        NodePtr temp = curr->next;
        curr->next = NULL;

        if(pos % 2 != 0) {
            curr->next = dispari->head;
            dispari->head = curr;
            if(dispari->tail == NULL) {
                dispari->tail = curr;
            }
        }

        else {
            curr->next = pari->head;
            pari->head = curr;
            if(pari->tail == NULL) {
                pari->tail = curr;
            }
        }

        curr = temp;
        pos++;
    }
    src->head = NULL;
    src->tail = NULL;
}

void printList(List l) {
    NodePtr curr = l.head;
    while(curr != NULL) {
        printf("%d", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Node n6 = {6, NULL};
    Node n5 = {5, &n6};
    Node n4 = {4, &n5};
    Node n3 = {3, &n4};
    Node n2 = {2, &n3};
    Node n1 = {1, &n2};

    List src = {&n1, &n6};
    List pari;
    List dispari;

    split_reverse_positions(&src, &pari, &dispari);

    printf("Dispari: ");
    printList(dispari);

    printf("Pari: ");
    printList(pari);

    return 0;
}

