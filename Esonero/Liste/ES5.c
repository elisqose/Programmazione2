#include <stdio.h>
#include <stdlib.h>

//Data una singola lista l, restituire una nuova lista in cui tutti i caratteri
//consecutivi uguali sono ridotti a uno solo.

typedef struct node CharNode, *CharList;
struct node {
    char data;
    CharList next;
};

void printList (CharList list) {
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
    CharList node = malloc(sizeof(CharNode));
    node->data = c;
    node->next = next;
    return node;
}

CharList compressList(CharList l) {
    if (l == NULL) {
        return NULL;
    }

    CharList head = NULL;
    CharList tail = NULL;

    while (l != NULL) {
        int daInserire = 0;

        if (head == NULL) {
            daInserire = 1;
        }
        else if (l->data != tail->data) {
            daInserire = 1;
        }

        if (daInserire == 1) {
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
        }
        l = l->next;
    }
    return head;
}

int main() {
    CharList list = newNode('c', newNode('a', newNode('f', newNode('f', newNode('e', newNode('l', newNode('l', newNode('a', newNode('t', newNode('t', newNode('e', NULL)))))))))));

    CharList result = compressList(list);

    printf("Lista iniziale: ");
    printList(list);
    printf("\n");

    printf("Lista finale: ");
    printList(result);

    freeList(list);
    freeList(result);
    return 0;
}