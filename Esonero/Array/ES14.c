#include <stdio.h>
#include <stdlib.h>

//Dato un array e due indici start e end, restituire un nuovo array contenente solo gli elementi
//in quell'intervallo.

int* slice_array(const int* a, int n, int start, int end, int* new_n) {

    if (a == NULL || n <= 0 || start < 0 || end >= n || start > end) {
        *new_n = 0;
        return NULL;
    }

    int len = end - start + 1;
    *new_n = len;

    int* result = (int*) malloc(sizeof(int)*len);
    if (!result) {
        *new_n = 0;
        return NULL;
    }

    int j = 0;
    for (int i = start; i <= end; i++) {
        result[j] = a[i];
        j++;
    }
    return result;
}

int main() {
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;

    // Vogliamo estrarre {30, 40, 50, 60} -> indici da 2 a 5
    int start = 2;
    int end = 5;
    int new_n;

    int* res = slice_array(a, n, start, end, &new_n);

    if (res != NULL) {
        printf("Array originale: ");
        for(int i=0; i<n; i++) printf("%d ", a[i]);
        printf("\n");

        printf("Slice (%d-%d):    ", start, end);
        for(int i=0; i<new_n; i++) printf("%d ", res[i]);
        printf("\n");
    }
    else {
        printf("Errore");
        return 1;
    }

    free(res);
    return 0;
}