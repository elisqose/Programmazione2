#include <stdio.h>
#include <stdlib.h>

typedef struct node CharNode, *CharList;
struct node {
    char data;
    CharList next;
};

// Data una lista l, restituisci una nuova lista che contiene tutti gli elementi di l, ma se un
// valore appare più volte, devi mantenere solo la sua prima apparizione assoluta

void printList (CharList l) {
    CharList curr = l;
    while (curr != NULL) {
        printf("%c ", curr->data);
        curr = curr->next;
    }
}

void freeList (CharList l) {
    while (l != NULL) {
        CharList temp = l;
        l = l->next;
        free(temp);
    }
}

CharList newNode (char c, CharList next) {
    CharList node = malloc(sizeof(CharNode));
    if (!node) {
        return NULL;
    }
    node->data = c;
    node->next = next;
    return node;
}

int exists (CharList list, char c) {
    CharList curr = list;
    while (curr != NULL) {
        if (curr->data == c) {
        return 1;
    }
        curr = curr->next;
    }
    return 0;
}

CharList unique_elements(CharList l) {

    CharList head = NULL;
    CharList tail = NULL;

    CharList curr = l;
    while (curr != NULL) {
        if (!exists(head, curr->data)) {
            CharList node = malloc(sizeof(CharNode));
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
    CharList l = newNode('A', newNode('B', newNode('A', newNode('C', newNode('B', newNode('A', NULL))))));
    CharList result = unique_elements(l);

    if (result != NULL) {
        printf("Lista originale: ");
        printList(l);
        printf("\n");

        printf("Lista finale: ");
        printList(result);
    }

    else {
        printf("Errore");
        return 1;
    }
    freeList(l);
    freeList(result);
    return 0;
}