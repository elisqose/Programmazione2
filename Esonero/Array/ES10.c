#include <stdio.h>
#include <stdlib.h>

//Date due array di dimensione n, creare un nuovo array contenente solo gli elementi in comune
//e aggiornare new_n con la lunghezza dell array nuovo

int* intersezione(const int* a, const int* b, int n, int* new_n) {
    if(a == NULL || b == NULL || n < 0) {
        return NULL;
    }

    if(n == 0) {
        *new_n = 0;
        return NULL;
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i]==b[j]){
                count++;
                break;
            }
        }
    }

    *new_n = count;

    int* result = (int*) malloc (sizeof(int)*count);
    if(!result) {
        return NULL;
    }

    int x = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i] == b[j]) {
                int presente = 0;
                for(int k = 0; k < x; k++) {
                    if(result[k]==a[i]) {
                        presente = 1;
                        break;
                    }
                }

                if(presente == 0) {
                    result[x] = a[i];
                    x++;
                }
                break;
            }
        }
    }
    return result;
}

int main() {
    int a[] = {1,2,3,4};
    int b[] = {3,4,5,6};
    int n = 4;
    int new_n;

    int* res = intersezione(a, b, n, &new_n);

    if(res == NULL && new_n != 0) {
        printf("Errore");
        return 1;
    }

    else {
        printf("Intersezione: ");
        for(int i = 0; i < new_n; i++) {
            printf("%d", res[i]);
        }
        free(res);
    }
    return 0;
}