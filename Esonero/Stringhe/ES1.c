#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Data una stringa, la sua lunghezza n e un numero m, restituisce una nuova
//stringa che contiene gli elementi invertiti fino alla posizione s[n-min(n,m)]

char* trasforma(char* str, int n, int m) {
    if (str == NULL || n < 0 || m < 0) {
        return NULL;
    }

    if(n == 0) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    int min = n;
    if (m < n) {
        min = m;
    }

    int posizione = n - min;

    char* result = (char*)malloc(min+1);
    if(!result) {
        return NULL;
    }

    int j = 0;
    for (int i = n-1; i >= posizione; i--) {
        result[j] = str[i];
        j++;
    }

    result[j] = '\0';
    return result;
}

int main() {
    char s[] = "eccocosafare";
    int n = strlen(s);
    int m = 5;

    char* newstring = trasforma(s, n, m);

    if(!newstring) {
        printf("Errore");
        return 1;
    }

    printf("Stringa originale: %s\n", s);
    printf("Stringa nuova: %s\n", newstring);
    free(newstring);
}