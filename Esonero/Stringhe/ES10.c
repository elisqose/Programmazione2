#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Date due stringhe s1 e s2, restituisci una nuova stringa formata alternando
// i caratteri di s1 e s2. I caratteri residui della stringa più lunga vengono accodati.

char* merge_alternato(const char* s1, const char* s2) {
    if (s1 == NULL || s2 == NULL) {
        return NULL;
    }

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len = len1 + len2;

    char* result = (char*) malloc(len + 1);
    if (!result) {
        return NULL;
    }

    int i = 0;  //s1
    int j = 0;  //s2
    int k = 0;  //result

    while (i < len1 || j < len2) {
        if (i < len1) {
            result[k] = s1[i];
            k++;
            i++;
        }

        if (j < len2) {
            result[k] = s2[j];
            k++;
            j++;
        }
    }
    result[k] = '\0';
    return result;
}

int main() {
    char* s1 = "ace";
    char* s2 = "bdfglih";
    char* result = merge_alternato(s1, s2);

    if (result != NULL) {
        printf("Prima stringa: %s\n", s1);
        printf("Seconda stringa: %s\n", s2);
        printf("Stringa finale: %s\n", result);
        free(result);
    }

    else {
        printf("Errore");
        return 1;
    }
return 0;
}