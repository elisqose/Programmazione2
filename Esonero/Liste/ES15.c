#include <stdio.h>
#include <stdlib.h>

//Date due liste l e r, copia gli elelemti di l in una nuova lista solo se non compaiono in r nella
//stessa posizione

typedef struct node CharNode, *CharList;
struct node {
    char data;
    CharList next;
};

CharList newNode (char c, CharList next) {
    CharList n = malloc(sizeof(CharNode));
    n->data = c;
    n->next = next;
    return n;
}

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
        free (temp);
    }
}

CharList antiPrefix(CharList l, CharList r) {
    if (l == NULL) {
        return NULL;
    }

    CharList head = NULL;
    CharList tail = NULL;

    while (l != NULL) {
        if (r != NULL) {
            if (l->data == r->data) {
                break;
            }
            r = r->next;
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
    }
    return head;
}

int main() {
    CharList l = newNode('C', newNode('I', newNode('A', newNode('O', NULL))));
    CharList r = newNode('Q', newNode('U', newNode('A', NULL)));

    printf("Lista l: ");
    printList(l);
    printf("\n");

    printf("Lista r: ");
    printList(r);
    printf("\n");

    CharList risultato = antiPrefix(l, r);

    printf("Lista risultato: ");
    printList(risultato);

    freeList(l);
    freeList(r);
    freeList(risultato);

    return 0;
}