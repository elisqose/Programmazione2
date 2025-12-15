#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Data una stringa e un intero k, restituire una nuova stringa dove ogni lettera è sostituita dalla
//lettera che si trova k posizioni dopo nell'alfabeto (gestendo il "giro" da Z ad A).

char* cifrario_cesare(const char* s, int k) {

    if (s == NULL) {
        return NULL;
    }

    int len = strlen(s);

    char* result = (char*) malloc(len + 1);
    if (!result) {
        return NULL;
    }

    int shift = k % 26;
    if (shift < 0) {
        shift += 26;
    }

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (islower(c)) {
            result[i] = 'a' + (c - 'a' + shift) % 26;
        }

        else if (isupper(c)) {
            result[i] = 'A' + (c - 'A' + shift) % 26;
        }

        else {
            result[i] = c;
        }
    }
    result[len] = '\0';
    return result;
}

int main() {
    char* s1 = "Ciao Mondo";
    int k1 = 3;
    char* res1 = cifrario_cesare(s1, k1);

    if (res1) {
        printf("1. Base:\n");
        printf("   Originale: %s\n", s1);
        printf("   Cifrato (k=%d): %s\n", k1, res1);
        printf("   ----------------\n");
        free(res1);
    }

    char* s2 = "xyz XYZ";
    int k2 = 1;
    char* res2 = cifrario_cesare(s2, k2);

    if (res2) {
        printf("2. Wrap-around (z->a):\n");
        printf("   Originale: %s\n", s2);
        printf("   Cifrato (k=%d): %s\n", k2, res2); // Atteso: "yza YZA"
        printf("   ----------------\n");
        free(res2);
    }

    char* s3 = "Abc";
    int k3 = 27;
    char* res3 = cifrario_cesare(s3, k3);

    if (res3) {
        printf("3. Shift Grande (k > 26):\n");
        printf("   Originale: %s\n", s3);
        printf("   Cifrato (k=%d): %s\n", k3, res3); // Atteso: "Bcd"
        printf("   ----------------\n");
        free(res3);
    }

    char* s4 = "Bcd";
    int k4 = -1;
    char* res4 = cifrario_cesare(s4, k4);

    if (res4) {
        printf("4. Shift Negativo:\n");
        printf("   Originale: %s\n", s4);
        printf("   Cifrato (k=%d): %s\n", k4, res4); // Atteso: "Abc"
        printf("   ----------------\n");
        free(res4);
    }

    return 0;
}