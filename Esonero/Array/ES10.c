#include <stdio.h>
#include <stdlib.h>

// Dato un array a, restituisci un nuovo array dove ogni elemento è la somma
// di se stesso e dei suoi adiacenti (precedente e successivo, se esistono).

int* somma_adiacenti(const int* a, int n, int* new_n) {

    if (a == NULL || n <= 0) {
        *new_n = 0;
        return NULL;
    }

    int* result = (int*) malloc(sizeof(int)*n);
    if (!result) {
        *new_n = 0;
        return NULL;
    }

    if (n == 1) {
        result[0] = a[0];
        *new_n = 1;
        return result;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if(i == 0) {
            result[j] = a[i]+ a[i+1];
            j++;
        }

        else if(i == n-1) {
            result[j] = a[i] + a[i-1];
            j++;
        }

        else {
            result[j] = a[i-1] + a[i] + a[i+1];
            j++;
        }
    }
    *new_n = n;
    return result;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;
    int new_n;

    int* res = somma_adiacenti(a, n, &new_n);

    if (res != NULL) {
        printf("Array iniziale: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }

        printf("\n");

        printf("Array finale: ");
        for (int j = 0; j < new_n; j++) {
            printf("%d ", res[j]);
        }
    }

    else {
        printf("Errore");
        return 1;
    }

    free(res);
    return 0;
}