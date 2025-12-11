#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Data una stringa s e la sua lunghezza n, rimuove tutti i numeri, sostituisce
//gli spazi con # e cambia h e k in maiuscolo e restituisce la nuova stringa

char* trasforma_stringa(const char* str, int n) {
    if(str == NULL || n <= 0) {
        return NULL;
    }

    char *result = (char*)malloc(n+1);
    if(!result) {
        return NULL;
    }

    int j = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            continue;
        }

        else if(str[i] == 'h') {
            result[j] = 'H';
            j++;
        }

        else if(str[i] == 'k') {
            result[j] = 'K';
            j++;
        }

        else if(str[i] == ' ') {
            result[j] = '#';
            j++;
        }

        else {
            result[j] = str[i];
            j++;
        }
    }

    while(j < n) {
        result[j] = '#';
        j++;
    }

    result[n] = '\0';
    return result;
}

int main() {
    char* s = "ciao h3k io";
    int n = strlen(s);

    char* result = trasforma_stringa(s, n);

    if(!result) {
        printf("Errore");
        return 1;
    }

    else {
        printf("Stringa iniziale: %s\n", s);
        printf("Stringa finale: %s\n", result);
        free(result);
    }
    return 0;
}