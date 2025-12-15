#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Data una stringa s, restituisci una nuova stringa in cui ogni vocale
// (sia maiuscola che minuscola) viene triplicata. Gli altri caratteri rimangono invariati.

int is_vowel (char c) {
    c = tolower(c);
    if (c == 'a' || c =='e' || c=='i' || c== 'o' || c== 'u') {
        return 1;
    }
    return 0;
}

char* triplica_vocali(const char* s) {

    if (s == NULL) {
        return NULL;
    }

    int len = strlen(s);
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (is_vowel(s[i])) {
            count++;
        }
    }

    int new_len = len + (count * 2);
    char* result = malloc(new_len + 1);

    if (!result) {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (is_vowel(s[i])) {
            result[j] = s[i];
            result[j+1] = s[i];
            result[j+2] = s[i];
            j += 3;
        }

        else {
            result[j] = s[i];
            j++;
        }
    }
    result[j] = '\0';
    return result;
}

int main() {
    char* s = "Esame";
    char* res = triplica_vocali(s);

    if (res != NULL) {
        printf("Stringa originale: %s\n", s);
        printf("Stringa finale: %s\n", res);
        free(res);
    } else {
        printf("Errore\n");
        return 1;
    }
    return 0;
}
