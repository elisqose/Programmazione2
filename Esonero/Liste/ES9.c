#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
    int data;
    IntList next;
};

//Date due liste di interi l1 e l2, che sono già ordinate in ordine crescente, restituisci
//una nuova lista che contenga tutti gli elementi di entrambe le liste, mantenendo l'ordine crescente.

void printList(IntList list) {
    IntList curr = list;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
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

IntList merge_sorted_lists(IntList l1, IntList l2) {

    IntList head = NULL;
    IntList tail = NULL;

    IntList curr1 = l1;
    IntList curr2 = l2;

    while (curr1 != NULL && curr2 != NULL) {
        IntList node = malloc(sizeof(IntNode));
        if (!node) {
            return NULL;
        }

        if (curr1->data < curr2->data) {
            node->data = curr1->data;
            node->next = NULL;
            curr1 = curr1->next;
        }

        else if (curr1->data > curr2->data) {
            node->data = curr2->data;
            node->next = NULL;
            curr2 = curr2->next;
        }

        else {
            node->data = curr1->data;
            node->next = NULL;
            curr1 = curr1->next;
        }

        if (head == NULL) {
            head = node;
            tail = node;
        }

        else {
            tail->next = node;
            tail = node;
        }
    }

    while (curr1 != NULL) {
        IntList node = malloc(sizeof(IntNode));

        if (!node) {
            return NULL;
        }

        node->data = curr1->data;
        node->next = NULL;

        if (head == NULL) {
            head = node;
            tail = node;
        }

        else {
            tail->next = node;
            tail = node;
        }
        curr1 = curr1->next;
    }

    while (curr2 != NULL) {
        IntList node = malloc(sizeof(IntNode));

        if (!node) {
            return NULL;
        }

        node->data = curr2->data;
        node->next = NULL;

        if (head == NULL) {
            head = node;
            tail = node;
        }

        else {
            tail->next = node;
            tail = node;
        }
        curr2 = curr2->next;
    }
    return head;
}

int main() {
    IntList l1 = newNode(1, newNode(3, newNode(5, NULL)));
    IntList l2 = newNode(2, newNode(4, newNode(6, newNode(8, NULL))));

    IntList res = merge_sorted_lists(l1, l2);

    if (res != NULL) {
        printf("Lista 1: ");
        printList(l1);
        printf("\n");

        printf("Lista 2: ");
        printList(l2);
        printf("\n");

        printf("Lista Finale: ");
        printList(res);
    }

    else {
        printf("Errore");
        return 1;
    }

    freeList(l1);
    freeList(l2);
    freeList(res);
    return 0;
}