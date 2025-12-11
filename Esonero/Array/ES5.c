#include <stdio.h>
#include <stdlib.h>

//Scrivere una funzione che riceva due array di interi a e b (con le relative dimensioni na e nb).
//La funzione deve restituire un nuovo array allocato nello heap che contiene tutti gli elementi
//di a che NON sono presenti in b. L'ordine degli elementi deve essere preservato.

int* differenza_array(const int* a, int na, const int* b, int nb, int* new_n) {

    if (a == NULL || b == NULL || na < 0 || nb < 0) {
        return NULL;
    }

    if (na == 0) {
        *new_n = 0;
        return NULL;
    }

    int count = 0;
    for (int i = 0; i < na; i++) {
        int trovato = 0;
        for (int j = 0; j < nb; j++) {
            if (a[i]==b[j]) {
                trovato = 1;
                break;
            }
        }
        if (trovato == 0) {
            count++;
        }
    }

    if (count == 0) {
        *new_n = 0;
        return NULL;
    }

    int* result = (int*) malloc (sizeof(int) * count);
    if (result == NULL) {
        return NULL;
    }

    int k = 0;
    for (int i = 0; i < na; i++) {
        int found = 0;
        for (int j = 0; j < nb; j++) {
            if (a[i] == b[j]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            result[k] = a[i];
            k++;
        }
    }
    *new_n = count;
    return result;
}

int main () {
    int a[] = {1,2,3,4,5};
    int b[] = {2,4};
    int na = 5;
    int nb = 2;
    int new_n;

    int *res = differenza_array(a, na, b, nb, &new_n);

    if (res == NULL && new_n != 0) {
        printf("Errore");
        return 1;
    }

    else {
        printf("Differenza A - B: ");
        for (int i = 0; i < new_n; i++) {
            printf("%d", res[i]);
        }
    }
    free(res);
    return 0;
}