#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
    int data;
    IntList next;
};

// Data una lista l, restituisce una nuova lista contenente solo gli ultimi k nodi.

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

IntList copy_last_k(IntList l, int k) {

    if (l == NULL || k <= 0) {
        return NULL;
    }

    int len = 0;
    IntList curr = l;
    while (curr != NULL) {
        len++;
        curr = curr->next;
    }

    int skip = 0;
    if (k < len) {
        skip = len - k;
    }

    curr = l;
    for (int i = 0; i < skip; i++) {
        curr = curr->next;
    }

    IntList head = NULL;
    IntList tail = NULL;

    while (curr != NULL) {
        IntList node = malloc(sizeof(IntNode));
        if (!node) {
            freeList(head);
            return NULL;
        }

        node->data = curr->data;
        node->next = NULL;

        if (head == NULL) {
            head = node;
            tail =node;
        }

        else {
            tail->next = node;
            tail = node;
        }
    curr = curr->next;
    }
    return head;
}

int main() {
    IntList l = newNode(10, newNode(20, newNode(30, newNode(40, newNode(50, NULL)))));
    int k = 2;

    IntList res = copy_last_k(l, k);

    if (res!= NULL) {
        printf("Lista originale: ");
        printList(l);
        printf("\n");

        printf("Ultimi %d elementi: ", k);
        printList(res);
        printf("\n");
    }

    else {
        printf("Errore");
        return 1;
    }
    freeList(l);
    freeList(res);
    return 0;
}
