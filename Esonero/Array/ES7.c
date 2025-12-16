#include <stdio.h>
#include <stdlib.h>

//Dato un array di interi a, restituisci un nuovo array contenente solo gli elementi
//che sono strettamente maggiori sia del loro precedente che del loro successivo.
//Per il primo elemento confronta solo col successivo, per l'ultimo solo col precedente).

int* trova_picchi(const int* a, int n, int* new_n) {
    if (a == NULL || n <= 0) {
        return NULL;
    }

    int count = 0;

    for (int i = 0; i < n; i++) {

        if (n == 1) {
            count++;
        }

        else if (i == 0 ) {
            if (a[i] > a[i+1]) {
                count++;
            }
        }

        else if (i == n-1 ) {
            if (a[i] > a[i-1]) {
                count++;
            }
        }

        else if (a[i+1] < a[i] && a[i-1] < a[i]) {
                count++;
        }
    }

    *new_n = count;

    if (count == 0) {
        return NULL;
    }

    int* result = (int*) malloc (sizeof(int)*count);
    if (!result) {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {

        int isPeak = 0;

        if (n == 1) {
                isPeak = 1;
        }

        else if (i == 0 ) {
            if (a[i] > a[i+1]) {
                isPeak = 1;
            }
        }

        else if (i == n-1 ) {
            if (a[i] > a[i-1]) {
                isPeak = 1;
            }
        }

        else if (a[i+1] < a[i] && a[i-1] < a[i]) {
                isPeak = 1;
        }

        if (isPeak == 1) {
            result[j]=a[i];
            j++;
        }
    }
    return result;
}

int main() {
    int a[] = {10, 2, 5, 3, 8};
    int n = 5;
    int new_n;

    int* res = trova_picchi(a, n, &new_n);

    if (res == NULL && new_n != 0) {
        printf("Errore");
        return 1;
    }

    else {
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
    free(res);
    return 0;
}