#include <stdio.h>
#include <stdlib.h>

//Dato un array di interi a di lunghezza n, restituire un nuovo array in cui ogni numero negativo
//presente in a viene seguito immediatamente da uno zero. I numeri positivi rimangono invariati.

int* espandi_negativi(const int* a, int n, int* new_n) {
    *new_n = 0;

    if (a == NULL || n <= 0) {
        return NULL;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            count++;
        }
    }

    *new_n = n + count;

    int* result = (int*) malloc (sizeof(int) * (*new_n));
    if (!result) {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        result[j] = a[i];
        j++;

        if (a[i] < 0) {
            result[j] = '0';
            j++;
        }
    }
    return result;
}

int main() {
    int a[] = {10, -3, 5, -2, -1};
    int n = 5;
    int new_len;

    int* res = espandi_negativi(a, n, &new_len);
    if (res == NULL && new_len != 0) {
        printf("Errore");
        return 1;
    }

    printf("Originale: ");
    for(int i=0; i<5; i++) printf("%d ", a[i]);
    printf("\n");

    printf("Espanso:   ");
    for(int i=0; i<new_len; i++) printf("%d ", res[i]);
    printf("\n");

    free(res);
    return 0;
}
