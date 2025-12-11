#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Data una stringa s, restituisci una nuova stringa che contiene solo le consonanti di s, ma in
//ordine inverso. Le vocali e i numeri vengono scartati.

char* filtra_inverti_consonanti(const char* str) {

    if (str == NULL) {
        return NULL;
    }

    int len = strlen(str);
    int count = 0;

    for (int i = 0; i < len; i++) {

        char c = tolower(str[i]);

        if (!isdigit(c) && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            count++;
        }
    }

    char* result = (char*) malloc (count + 1);
    if (!result) {
        return NULL;
    }

    int j = count - 1;
    for (int i = 0; i < len; i++) {

        char c = tolower(str[i]);

        if (!isdigit(c) && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            result[j] = str[i];
            j--;
        }
    }
    result[count] = '\0';
    return result;
}

int main() {
    char* str = "Ciao user 123!";

    char* res = filtra_inverti_consonanti(str);

    if (res != NULL) {
        printf("Stringa originale: %s\n", str);
        printf("Stringa finale: %s", res);
    }

    else {
        printf("Errore");
        return 1;
    }
    free(res);
    return 0;
}