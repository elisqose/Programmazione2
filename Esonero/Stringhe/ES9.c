#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data una stringa s composta da parole separate da spazi, restituisci una nuova stringa
// dove ogni singola parola è invertita, mantenendo l'ordine originale delle parole.

char* inverti_parole(const char* s) {
    if (s == NULL) {
        return NULL;
    }

    int len = strlen(s);

    char* result = (char*) malloc(len+1);
    if (!result) {
        return NULL;
    }

    strcpy(result, s);

    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (result[i] == ' ' || result[i] == '\0') {
            int end = i - 1;

            while(start < end) {
                char temp = result[start];
                result[start] = result[end];
                result[end] = temp;
                start++;
                end--;
            }
            start = i + 1;
        }
    }
    return result;
}

int main() {
    char* str = "programmazione in linguaggio c";
    char* res = inverti_parole(str);

    if (res != NULL) {
        printf("Stringa originale: %s\n", str);
        printf("Stringa invertita: %s\n", res);
        free(res);
    }

    else {
        printf("Errore");
        return 1;
    }
    return 0;
}