#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Data una stringa s, restituisca una nuova stringa in cui ogni consonante minuscola (a-z esclusi a,e,i,o,u)
//viene raddoppiata. Le vocali, i numeri e le lettere maiuscole restano invariati.
//Esempio: "Cia0" -> "Cia0" (nessuna modifica). "baKo" -> "bbaKo".

int is_consonant_lower (char c) {
    if (c >= 'a' && c <= 'z') {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            return 1;
        }
    }
    return 0;
}

char* raddoppia_consonanti(const char* s) {

    if (s == NULL) {
        return NULL;
    }
    int len = strlen(s);

    int count = 0;
    for (int i = 0; i < len; i++) {
        if (is_consonant_lower(s[i])) {
            count++;
        }
    }

    int new_len = len + count;

    char* result = (char*) malloc(new_len + 1);
    if(!result) {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < len; i++) {
        result[j] = s[i];
        j++;

        if (is_consonant_lower((s[i]))) {
            result[j] = s[i];
            j++;
        }
    }

    result[j] = '\0';
    return result;
}

int main() {
    char* s = "progRAMMazioNE2";
    char* res = raddoppia_consonanti(s);

    if (res != NULL) {
        printf("Stringa iniziale: %s\n", s);
        printf("Stringa finale: %s\n", res);
    }

    else {
        printf("Errore");
        return 1;
    }
    free(res);
    return 0;
}