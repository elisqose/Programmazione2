#include <stdio.h>
#include <stdlib.h>

//Dati due array a e b di uguale dimensione n. Restituire un nuovo array di dimensione n dove l'elemento
//i è il massimo tra a[i] e b[i].

int* max_merge(const int* a, const int* b, int n) {
    if (n <= 0 || a == NULL || b == NULL) {
        return NULL;
    }


    int* result = (int*) malloc(sizeof(int)*n);
    if (!result) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
            if (a[i] >= b[i]) {
                result[i] = a[i];
            }
            else {
                result[i] = b[i];
            }
        }
    return result;
}

int main() {
    int a[] = {10, 2, 50, 3, 8};
    int b[] = {5, 20, 5, 30, 1};
    int n = 5;

    int* res = max_merge(a, b, n);

    if (res != NULL) {
        printf("Risulrato: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", res[i]);
        }
    }

    else {
        printf("Errore");
        return 1;
    }

    free(res);
    return 0;
}