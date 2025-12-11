#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Data una stringa contenente lettere e singole cifre (es. "a3b2"), restituisci una nuova stringa
//dove ogni lettera è ripetuta tante volte quanto indicato dalla cifra successiva.
//Se una lettera non è seguita da un numero, va presa una sola volta. (Es. "a3b2" -> "aaabb").

char* espandi_stringa(const char* str) {

    if (str == NULL) {
        return NULL;
    }
    int len = strlen(str);

    if (len == 0) {
        return NULL;
    }

    int count = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            int ripetizioni = 1;

            if (isdigit(str[i+1])) {
                ripetizioni = str[i+1] - '0';
            }
            count += ripetizioni;
        }
    }

    char* result = (char*) malloc(count+1);
    if (!result) {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            char c = str[i];
            int ripetizioni = 1;

            if (isdigit(str[i+1])) {
                ripetizioni = str[i+1] - '0';
            }

            for (int k = 0; k < ripetizioni; k++) {
                result[j]=c;
                j++;
            }
        }
    }

    result[j] = '\0';
    return result;
}

int main() {
    char* str = "a3b2c4";

    char* res = espandi_stringa(str);

    if (res != NULL) {
        printf("Stringa iniziale: %s\n", str);
        printf("Stringa finale: %s", res);
    }

    else {
        printf("Errore");
        return 1;
    }

    free(res);
    return 0;
}