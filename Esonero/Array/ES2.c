#include <stdio.h>
#include <stdlib.h>

//Dato un array di interi a di lunghezza n, restituire un puntatore ad un nuovo array (allocato sullo
//heap) che contiene tutti gli elementi di ache NON sono numeri pari, mantenendo l'ordine originale.

int* rimuovi_pari(const int* a, int n, int* new_n) {
    if(a == NULL || n < 0) {
        return NULL;
    }

    if(n == 0) {
        *new_n = 0;
        return NULL;
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 != 0) {
            count++;
        }
    }

    if(count == 0) {
        *new_n = 0;
        return NULL;
    }

    int* result = (int*)malloc(sizeof(int)*count);
    if(!result) {
        return NULL;
    }

    int j = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 != 0) {
            result[j]= a[i];
            j++;
        }
    }
    *new_n = count;
    return result;
}

int main(){
    int a[] = {1,2,3,4,5};
    int new_n = 0;

    int* result = rimuovi_pari(a, 5, &new_n);

    if(result == NULL && new_n != 0) {
        printf("Errore");
        return 1;
    }

    printf("Array iniziale: ");
    for(int i = 0; i < 5; i++) {
        printf("%d", a[i]);
    }
    printf("\n");

    printf("Array nuovo: ");
    for(int j = 0; j < new_n; j++) {
        printf("%d", result[j]);
    }
    free(result);
    return 0;
}