#include <stdio.h>
#include <stdlib.h>

typedef struct node CharNode, *CharList;
struct node {
    char data;
    CharList next;
};

void printList(CharList list) {
    CharList curr = list;

    while (curr != NULL) {
        printf("%c", curr->data);
        curr = curr->next;
    }
}

void freeList(CharList list) {
    while (list != NULL) {
        CharList temp = list;
        list = list->next;
        free(temp);
    }
}

CharList newNode (char c, CharList next) {
    CharList nodo = malloc(sizeof(CharNode));
    nodo->data = c;
    nodo->next = next;
    return nodo;
}

//Date due liste l ed r, restituire una nuova lista che contenga il prefisso comune più lungo.
//Ovvero: copia i nodi finché i caratteri in l e r sono uguali. Appena sono diversi (o una delle
//due liste finisce), ti fermi.

CharList commonPrefix(CharList l, CharList r) {

    CharList head = NULL;
    CharList tail = NULL;

    while (l != NULL && r != NULL) {
        if (l->data != r -> data) {
            break;
        }

        CharList node = malloc(sizeof(CharNode));
        node->data = l->data;
        node->next = NULL;

        if (head == NULL) {
            head = node;
            tail = node;
        }

        else {
            tail->next = node;
            tail = node;
        }
        l = l->next;
        r = r->next;
    }
    return head;
}

int main() {
    CharList l = newNode('P', newNode('O', newNode('R', newNode('T', newNode('A', NULL)))));
    CharList r = newNode('P', newNode('O', newNode('R', newNode('T', newNode('O', NULL)))));

    CharList result = commonPrefix(l, r);

    printf("Lista l: ");
    printList(l);
    printf("\n");

    printf("Lista r: ");
    printList(r);
    printf("\n");

    printf("Lista finale: ");
    printList(result);

    freeList(l);
    freeList(r);
    freeList(result);

    return 0;
}