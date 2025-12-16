#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Date due stringhe s1 e s2, restituisci una nuova stringa contenente
// solo i caratteri di s1 che NON compaiono in s2, mantenendo l'ordine originale

int char_presente(char* str, char c) {
    while (*str != '\0') {
        if (*str == c) {
            return 1;
        }
        str++;
    }
    return 0;
}


char* sottrai_stringhe(const char* s1, const char* s2) {

    if (s1 == NULL) {
        return NULL;
    }

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (s2 == NULL) {
        char* copy = malloc(sizeof(len1 + 1));
        if (!copy) {
            return NULL;
        }

        for (int i = 0; i < len1; i++) {
            copy[i] = s1[i];
        }
        return copy;
    }

    int count = 0;
    for (int i = 0; i < len1; i++) {
        if (!char_presente(s2, s1[i])) {
            count++;
        }
    }

    char* result = malloc(count + 1);
    if (!result) {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < len1; i++) {
        if (!char_presente(s2, s1[i])) {
            result[j] = s1[i];
            j++;
        }
    }
    result[j] = '\0';
    return result;
}

int main() {
    char* s1 = "banane e lamponi";
    char* s2 = "aeiou ";

    char* res = sottrai_stringhe(s1, s2);

    if (res != NULL) {
        printf("Stringa 1: '%s'\n", s1);
        printf("Stringa da rimuovere: '%s'\n", s2);
        printf("Risultato: '%s'\n", res);
        free(res);
    }

    else {
        printf("Errore\n");
        return 1;
    }
    return 0;
}