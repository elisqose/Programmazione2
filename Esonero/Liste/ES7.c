#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
    int data;
    IntList next;
};

// Data una lista di interi, restituisci una nuova lista che contiene prima tutti i numeri pari presenti
// nella lista originale (nello stesso ordine relativo), seguiti da tutti i numeri dispari.

void printList (IntList list) {
    IntList curr = list;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

void freeList (IntList list) {
    while (list != NULL) {
        IntList temp = list;
        list = list->next;
        free(temp);
    }
}

IntList newNode (int n, IntList next) {
    IntList node = malloc(sizeof(IntNode));
    if (!node) {
        return NULL;
    }
    node->data = n;
    node->next = next;
    return node;
}

IntList reorder_even_odd(IntList l) {
    IntList head = NULL;
    IntList tail = NULL;

    IntList curr = l;

    //pari
    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            IntList node = malloc(sizeof(IntNode));
            if (!node) {
                return NULL;
            }
            node->data = curr->data;
            node->next = NULL;

            if (head == NULL) {
                head = node;
                tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
        }
        curr = curr->next;
    }

    //dispari
    curr = l;
    while (curr != NULL) {
        if (curr->data % 2 != 0) {
            IntList node = malloc(sizeof(IntNode));
            if (!node) {
                return NULL;
            }
            node->data = curr->data;
            node->next = NULL;

            if (head == NULL) {
                head = node;
                tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
        }
        curr = curr->next;
    }
    return head;
}

int main() {
    IntList l = newNode(1, newNode(2, newNode(3, newNode(4, newNode(5, newNode(6, NULL))))));
    IntList res = reorder_even_odd(l);

    if (res != NULL) {
        printf("Lista originale: ");
        printList(l);
        printf("\n");

        printf("Lista finale: ");
        printList(res);
    }

    else {
        printf("Errore");
        return 1;
    }
    freeList(l);
    freeList(res);
    return 0;
}