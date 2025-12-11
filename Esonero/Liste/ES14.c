#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Data una stringa s, restituisce una lista di caratteri che contiene tutti e soli i caratteri
//alfabetici maiuscoli (A - Z) trasformati in minuscoli della stringa s nell'ordine originale


typedef struct node CharNode, *CharList;

struct node {
    char data;
    CharList next;
};

void printList(CharList list) {
    CharList curr = list;
    while(curr != NULL) {
        printf("%c", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void freeList(CharList list) {
    while(list != NULL) {
        CharList temp = list;
        list = list->next;
        free(temp);
    }
}

CharList stringToList(char *s) {
    if(s == NULL) {
        return NULL;
    }

    CharList head = NULL;
    CharList tail = NULL;

    while(*s != '\0') {
        if(*s >= 'A' && *s <= 'Z') {
            CharList nodo = (CharList) malloc (sizeof(CharNode));
            if(nodo == NULL) {
                return NULL;
            }

            nodo->data = tolower(*s);
            nodo->next = NULL;

            if(head == NULL) {
                head = nodo;
                tail = nodo;
            }

            else {
                tail->next = nodo;
                tail = nodo;
            }
        }
        s++;
    }
    return head;
}

int main() {
    char *s = "Coordination@DisCoTec-2025";

    CharList result = stringToList(s);

    if(!result) {
        printf("Errore");
        return 1;
    }

    else {
        printf("La stringa originale: %s", s);
        printf("\n");
        printf("La lista finale: ");
        printList(result);
        freeList(result);
    }
    return 0;
}
