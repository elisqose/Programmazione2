#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Data una stringa e la sua lunghezza, rimuove i numeri 0…9 e li sostituisce con A e B alternati

char* sostituisciNumeri (const char* str, int lunghezza) {
    if (str == NULL || lunghezza <= 0) {
        return NULL;
    }

    char* result = (char*)malloc(lunghezza+1);
    if(!result) {
        return NULL;
    }

    int flag = 0;

    int j = 0;
    for (int i = 0; i < lunghezza; i++) {
        if(str[i] >= '0' && str[i] <= '9'){
            if(flag == 0) {
                result[j] = 'A';
                flag = 1;
                j++;
            }
            else {
                result[j] = 'B';
                flag = 0;
                j++;
            }
        }

        else {
            result[j] = str[i];
            j++;
        }
    }

    result[j] = '\0';
    return result;
}

int main() {
    char* string = "ciao1c2a4o2";
    int lunghezza = strlen(string);

    char *risultato = sostituisciNumeri(string, lunghezza);

    if(!risultato) {
        printf("Errore");
        return 1;
    }

    else {
        printf("Stringa originale: %s\n", string);
        printf("Stringa nuova: %s\n", risultato);
        free(risultato);
        return 0;
    }
}