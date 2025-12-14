#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
    int data;
    IntList next;
};

//Data una lista di interi l, restituisca una nuova lista della stessa lunghezza. Ogni nodo i della
//nuova lista deve contenere la somma di tutti i nodi della lista originale dalla testa fino alla
//posizione i inclusa.

void printList(IntList l) {
    IntList curr = l;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

void freeList(IntList l) {
    while (l != NULL) {
        IntList temp = l;
        l = l->next;
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

IntList somma_cumulativa(IntList l) {

    if (l == NULL) {
        return NULL;
    }

    IntList head = NULL;
    IntList tail = NULL;

    int current_sum = 0;

    IntList curr = l;
    while (curr != NULL) {
        current_sum += curr->data;

        IntList node = malloc(sizeof(IntNode));
        if (!node) {
            freeList(head);
            return NULL;
        }
        node->data = current_sum;
        node->next = NULL;

        if (head == NULL) {
            head = node;
            tail = node;
        }
        else {
            tail ->next = node;
            tail = node;
        }
        curr = curr->next;
    }
    return head;
}

int main() {
    IntList l = newNode(1, newNode(2, newNode(3, newNode(4, NULL))));
    IntList res = somma_cumulativa(l);

    if (res != NULL) {
        printf("Lista iniziale: ");
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