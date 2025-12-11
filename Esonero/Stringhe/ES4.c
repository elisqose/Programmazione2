#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Data una stringa e due indici i e j, coppia in ordine inverso in una nuova
// stringa gli elementi nelle posizioni da j a i.

char* cambio (const char* str, int i, int j) {
    if(str == NULL || i < 0 || j < 0) {
        return NULL;
    }

    int lunghezza = strlen(str);

    if(i >= lunghezza || j >= lunghezza) {
        return NULL;
    }

    if(i > j) {
        char* empty = (char*) malloc(1);
        empty[0] = '\0';
        return empty;
    }

    int len = j - i + 1;

    char* result = (char*) malloc(len+1);
    if(!result) {
        return NULL;
    }

    int k = 0;
    for(int v = j; v >= i; v--) {
        result[k] = str[v];
        k++;
    }

    result[k] = '\0';
    return result;
 }

 int main() {
    char* str = "eccocosafare";
    int i = 4;
    int j = 7;

    char* result = cambio(str, i, j);

    if(!result) {
        printf("Errore");
        return 1;
    }

    else {
        printf("Stringa iniziale: %s\n", str);
        printf("Stringa finale: %s\n", result);
        free(result);
    }
    return 0;
}
