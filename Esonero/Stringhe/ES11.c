#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data una stringa s contenente solo lettere minuscole (es. "aaabbc"), restituire una nuova stringa
// compressa dove ogni sequenza di caratteri uguali è seguita dal numero di ripetizioni (es. "a3b2c1").

char* comprimi_stringa(const char* s) {

    if (s == NULL) {
        return NULL;
    }

    int len = strlen(s);
    if (len == 0) {
        char* empty = (char*) malloc(sizeof(1));
        if (!empty) {
            return NULL;
        }
        empty[0] = '\0';
        return empty;
    }

    int gruppi = 0;
    for (int i = 0; i < len; i++) {
        if (i == len-1 || s[i] != s[i+1]) {
            gruppi++;
        }
    }

    char* result = (char*) malloc(gruppi*2+1);
    if (!result) {
        return NULL;
    }

    int j = 0;
    int count = 1;

    for (int i = 0; i < len; i++) {
        if (i < len-1 && s[i] == s[i+1]) {
            count++;
        }

        else {
            result[j] = s[i];
            j++;
            result[j] = count + '0';
            j++;

            count = 1;
        }

    }
    result[j] = '\0';
    return result;
}

int main() {
    char* s = "aaabbc";
    char* res = comprimi_stringa(s);

    if (res != NULL) {
        printf("Stringa iniziale: %s\n", s);
        printf("Stringa finale: %s", res);
    }

    else {
        printf("Errore");
        return 1;
    }
    free(res);
    return 0;
}