#include <stdio.h>
#include <stdlib.h>

//Dato un array di dimensione n e un intero k, restituire un nuovo array dove ogni elemento è
//spostato di k posizioni (es. [1,2,3,4,5] con k=2 diventa [4,5,1,2,3]).

int* rotate_right(const int* a, int n, int k, int* new_n) {
    if (a == NULL || n <= 0) {
        *new_n = 0;
        return NULL;
    }

    *new_n = n;

    int shift = k % n;
    if (shift < n) {
        shift += n;
    }

    int* result = (int*) malloc(sizeof(int)*n);
    if (!result) {
        *new_n = 0;
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        int pos = (i + shift) % n;
        result[pos] = a[i];
    }
    return result;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 2; // Vogliamo ottenere {4, 5, 1, 2, 3}
    int new_n;

    int* res = rotate_right(a, n, k, &new_n);

    if (res != NULL) {
        printf("Array originale: ");
        for (int i = 0; i < n; i++) printf("%d ", a[i]);
        printf("\n");

        printf("Array ruotato (k=%d): ", k);
        for (int i = 0; i < new_n; i++) printf("%d ", res[i]);
        printf("\n");


    }

    else {
        printf("Errore");
        return 1;
    }

    free(res);
    return 0;
}