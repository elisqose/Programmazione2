#include <stdio.h>
#include <stdlib.h>

//Dato un array di interi a di lunghezza n, restituire un puntatore a un nuovo array
//(allocato sullo heap) in cui ogni elemento multiplo di 3 è duplicato consecutivamente.

 int* duplica_multipli3(const int* a, int n, int* new_n) {
    if (a == NULL || n < 0) {
        return NULL;
    }

    if (n == 0) {
        *new_n = 0;
        return NULL;
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 3 == 0) {
            count++;
        }
    }
    *new_n = n + count;

    int* result = (int*) malloc(sizeof(int)*(*new_n));
    if(!result) {
        return NULL;
    }

    int j = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 3 == 0) {
            result[j] = a[i];
            j++;
            result[j] = a[i];
            j++;
        }

        else {
            result[j] = a[i];
            j++;
        }
    }
    return result;
}

int main() {
    int a[] = {3,5,6};
    int new_len;

    int* res = duplica_multipli3(a, 3, &new_len);

    if(!res && new_len != 0) {
        printf("Errore");
        return 1;
    }

    else {
        printf("Array originale: \n");
        for(int i = 0; i < 3; i++) {
            printf(" %d ", a[i]);
        }
        printf("\n");

        printf("Array finale: ");
        for(int j = 0; j < new_len; j++) {
            printf(" %d ", res[j]);
        }
    }
    free(res);
    return 0;
}