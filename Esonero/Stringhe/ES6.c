#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Dato una stringa, creare una nuova coppiando tutti gli elementi, duplicando i numeri

char* duplicaNumeri (const char* str, int lunghezza) {
    if(str == NULL || lunghezza < 0) {
        return NULL;
    }

    if(lunghezza == 0) {
        char *empty = (char*)malloc(1);
        if(!empty) {
            return NULL;
        }
        empty[0] = '\0';
        return empty;
    }

    int count = 0;
    for(int i = 0; i < lunghezza; i++) {
        if(isdigit(str[i])) {
            count++;
        }
    }

    int newLength = lunghezza + count;

    char* result = (char*)malloc(newLength+1);
    if(!result) {
        return NULL;
    }

    int j = 0;
    for(int i = 0; i < lunghezza; i++) {
        if(isdigit(str[i])) {
            result[j] = str[i];
            j++;
            result[j] = str[i];
            j++;
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
    char *str = "abc1c";
    int lunghezza = strlen(str);

    char *new = duplicaNumeri(str, lunghezza);

    if(!new) {
        printf("Errore");
        return 1;
    }

    else {
        printf("Stringa originale: %s\n", str);
        printf("Stringa nuova: %s\n", new);
        free(new);
    }
    return 0;
}