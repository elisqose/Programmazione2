#include <stdio.h>
#include <stdlib.h>

//Dato un array di interi a e la sua dimensione n, restituisca un nuovo array (allocato sullo heap)
//in cui ogni elemento è la media intera di tre elementi consecutivi dell'array originale.
//La dimensione del nuovo array sarà n - 2.

int* media_mobile_3(const int* a, int n, int* new_n) {

    if (a == NULL || n < 3) {
        *new_n = 0;
        return NULL;
    }

    *new_n = n-2;

    int* result = (int*) malloc(sizeof(int)*(*new_n));
    if (!result) {
        *new_n = 0;
        return NULL;
    }

    int j = 0;
    for(int i = 1; i < n-1; i++) {
        result[j] = (a[i-1] + a[i] + a[i+1])/3;
        j++;
    }
    return result;
}

int main() {
    int a[] = {2, 4, 6, 8, 10, 12};
    int n = 6;
    int new_n;

    int* res = media_mobile_3(a, n, &new_n);

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
