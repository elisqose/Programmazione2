#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
    int data;
    IntList next;
};

//Data una lista di interi l e due interi min e max, restituisci una nuova lista che contenga solo
//gli elementi di l il cui valore è compreso tra min e max (inclusi), mantenendo l'ordine originale.

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

IntList newNode(int n, IntList next) {
    IntList node = malloc(sizeof(IntNode));
    if (!node) return NULL;
    node->data = n;
    node->next = next;
    return node;
}

IntList filter_range(IntList l, int min, int max) {
    if (l == NULL) {
        return NULL;
    }

    IntList head = NULL;
    IntList tail = NULL;

    IntList curr = l;
    while (curr != NULL) {
        if (curr->data >= min && curr->data <= max) {
            IntList node = malloc(sizeof(IntNode));
            if (!node) {
                return NULL;
            }
            node->data = curr->data;
            node->next= NULL;

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
    IntList l = newNode(10, newNode(2, newNode(15, newNode(8, newNode(20, newNode(5, NULL))))));
    int min = 8;
    int max = 15;

    IntList res = filter_range(l, min, max);
    if (res != NULL) {
        printf("Lista originale: ");
        printList(l);
        printf("\n");

        printf("Lista filtrata: ");
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