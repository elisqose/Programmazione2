#include <stdio.h>
#include <stdlib.h>

// Dati due array, estituisce un nuovo array con gli elementi presenti solo in 'a' o solo in 'b'
// Aggiorna new_n con la dimensione del nuovo array.

int presente (const int* arr, int n, int val) {
    for (int i = 0; i < n; i++) {
        if (arr[i]==val) {
            return 1;
        }
    }
    return 0;
}

int* differenza_simmetrica(const int* a, int na, const int* b, int nb, int* new_n) {

    if (a == NULL || b == NULL || na < 0 || nb < 0) {
        return NULL;
    }

    int count = 0;

    for (int i = 0; i < na; i++) {
        if (!presente(b, nb, a[i])) {
            count++;
        }
    }

    for (int j = 0; j < nb; j++) {
        if (!presente(a, na, b[j])) {
            count++;
        }
    }

    *new_n = count;

    if (count == 0) {
        return NULL;
    }

    int* result = (int*) malloc(sizeof(int)*count);
    if (!result) {
        return NULL;
    }

    int k = 0;

    for (int i = 0; i < na; i++) {
        if (!presente(b, nb, a[i])) {
            result[k] = a[i];
            k++;
        }
    }

    for (int j = 0; j < nb; j++) {
        if (!presente(a, na, b[j])) {
            result[k] = b[j];
            k++;
        }
    }
    return result;
}

int main() {
    int a[] = {1,2,3,4,5};
    int b[] = {4,5,6,7};
    int na = 5;
    int nb = 4;
    int new_n;

    int* result = differenza_simmetrica(a, na, b, nb, &new_n);

    if (result != NULL) {
        printf("Differenza simmetrica tra a e b: ");
        for (int i = 0; i < new_n; i++) {
            printf("%d ", result[i]);
        }
    }
    else {
        printf("Errore");
        return 1;
    }
    free(result);
    return 0;
}


