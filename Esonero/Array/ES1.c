#include <stdio.h>
#include <stdlib.h>

// Dati due array di interi a e b, entrambi di dimensione n. La funzione deve restituire un puntatore
// a un nuovo array di dimensione 2*n che contenga gli elementi di entrambi gli array combinati
// secondo la logica: Gli elementi di a devono essere inseriti nell'ordine originale (dal primo all'ultimo).
// Gli elementi di b devono essere inseriti in ordine inverso (dall'ultimo al primo).

int *combine (int* a, int* b, int n) {
    if(a == NULL || b == NULL || n <= 0) {
        return NULL;
    }

    int* result = (int*) malloc(sizeof(int)* (2*n));
    if(!result) {
        return NULL;
    }

    int k = 0; //scrollare result
    int j = n-1; //scrollare b dal fondo
    for(int i = 0; i < n; i++) {
        result[k] = a[i];
        k++;

        result[k] = b[j];
        k++;
        j--;
    }
    return result;
}

#define DIM 4

int main() {
    int a[DIM] = {1,2,3,4};
    int b[DIM] = {6,7,8,9};

    int* newArray = combine(a, b, DIM);

    if(!newArray) {
        printf("Errore");
        return 1;
    }

    else {
        printf("Array a: ");
        for(int i = 0; i < DIM; i++) {
            printf("%d", a[i]);
        }

        printf("\n");

        printf("Array b: ");
        for(int j = 0; j < DIM; j++) {
            printf("%d", b[j]);
        }

        printf("\n");

        printf("Array Nuovo: ");
        for(int k = 0; k < DIM*2; k++) {
            printf("%d", newArray[k]);
        }
        free(newArray);
    }
    return 0;
}