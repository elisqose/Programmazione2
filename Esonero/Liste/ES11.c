#include <stdio.h>
#include <stdlib.h>

//Data una lista di interi, restituire una nuova lista della stessa lunghezza in cui ogni nodo
//contiene la media intera tra il valore del nodo corrispondente nella lista originale e il valore
//del nodo successivo. Per l'ultimo nodo della lista, che non ha un successivo, il valore rimane invariato.

typedef struct node IntNode, *IntList;
struct node {
    int data;
    IntList next;
};

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

IntList media_mobile(IntList list) {

    if (list == NULL) {
        return NULL;
    }

    IntList head = NULL;
    IntList tail = NULL;

    IntList curr = list;
    while (curr != NULL) {

        IntList node = malloc(sizeof(IntNode));
        if (!node) {
            return NULL;
        }

        if (curr->next != NULL) {
            node->data = (curr->data + curr->next->data)/2;
            node->next = NULL;

        }

        else {
            node->data = curr->data;
            node->next = NULL;
        }

        if (head == NULL) {
            head = node;
            tail = node;
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
    IntList l = newNode(10, newNode(20, newNode(30, newNode(40, NULL))));
    IntList res = media_mobile(l);

    if (res != NULL) {
        printf("Lista originale: \n");
        printList(l);
        printf("\n");

        printf("Lista finale: \n");
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