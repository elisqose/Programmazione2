#include <stdio.h>
#include <stdlib.h>

//Riceve un array di interi a, la sua dimensione n e una soglia k. La funzione deve restituire un
//nuovo array (allocato nello heap) che contiene tutti gli elementi di a, ma con una regola: se un
//elemento è strettamente maggiore di k, nel nuovo array deve essere seguito immediatamente dal valore -1

int* esplodi_valori(const int* a, int n, int k, int* new_n) {

    if (a == NULL || n <= 0) {
        *new_n = 0;
        return NULL;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > k) {
            count++;
        }
    }

    *new_n = n + count;

    int* result = malloc(sizeof(int) * (*new_n));
    if (!result) {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        result[j] = a[i];
        j++;
        if (a[i] > k) {
            result[j] = -1;
            j++;
        }
    }
    return result;
}

int main() {
    int a[] = {2, 10, 3, 8};
    int n = 4;
    int k = 5;
    int new_n;

    int* res = esplodi_valori(a, n, k, &new_n);

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