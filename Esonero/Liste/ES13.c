#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
    int data;
    IntList next;
};

//Data una lista, restituire una nuova lista che contiene gli stessi elementi ma in ordine inverso.

void printList(IntList l) {
    IntList curr = l;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

void freeList (IntList l) {
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

IntList reverse_copy(IntList l) {

    if (l == NULL) {
        return NULL;
    }

    IntList head = NULL;

    IntList curr = l;

    while (curr != NULL) {
        IntList node = malloc(sizeof(IntNode));
        if (!node) {
            free(head);
            return NULL;
        }

        node->data = curr->data;
        node->next = head;
        head = node;

        curr = curr->next;
    }
    return head;
}

int main() {
    IntList l = newNode(1, newNode(2, newNode(3, newNode(4, NULL))));
    IntList res = reverse_copy(l);

    if (res != NULL) {
        printf("Lista iniziale: ");
        printList(l);
        printf("\n");

        printf("Lista invertita: ");
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