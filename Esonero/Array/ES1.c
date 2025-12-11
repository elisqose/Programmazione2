#include <stdio.h>
#include <stdlib.h>

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