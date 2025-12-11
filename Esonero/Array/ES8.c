#include <stdio.h>
#include <stdlib.h>

//Dato un array a (es. {1, 1, 1, 2, 2, 3}), restituisci un nuovo array dove ogni sequenza di numeri
//uguali è sostituita da due numeri: il valore e la sua frequenza (es. {1, 3, 2, 2, 3, 1}).


int* comprimi_rle(const int* a, int n, int* new_n) {
    if (a == NULL || n <= 0) {
        *new_n = 0;
        return NULL;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i == n-1 || a[i] != a[i+1])
            count++;
    }

    *new_n = count * 2;

    int* result = (int*) malloc (sizeof(int)*(*new_n));
    if (result == NULL) {
        *new_n = 0;
        return NULL;
    }

    int cont = 1;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i < n-1 && a[i]==a[i+1]) {
            cont++;
        }
        else {
            result[j] = a[i];
            j++;
            result[j] = cont;
            j++;
            cont = 1;
        }
    }
    return result;
}

int main() {

    int a[] = {1,1,1,2,2,3,4,4,4,4};
    int n = 10;
    int new_n;

    int* res = comprimi_rle(a, n, &new_n);

    if (res != NULL) {
        printf("Array originale: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        printf("Array nuovo: ");
        for (int j = 0; j < new_n; j++) {
            printf("%d ", res[j]);
        }
    }

    else {
        printf("Errore o array vuoto");
        return 1;
    }
    free(res);
    return 0;
}