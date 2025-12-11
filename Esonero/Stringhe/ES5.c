#include <string.h>
#include <ctype.h>
#include <stdio.h>

//Data una stringa s, restituire 1 se s è palindroma ignorando il case
// e i caratteri non alfabetici, 0 altrimenti.

int palindroma(const char* s) {
    if(s == NULL) {
        return 0;
    }

    int i = 0;
    int j = (int)strlen(s)-1;

    while (i < j) {
        if(!isalpha(s[i])) {
            i++;
            continue;
        }

        if(!isalpha(s[j])) {
            j--;
            continue;
        }

        if(tolower(s[i]) != tolower(s[j])) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    char *s = "I topi non avevano nipoti";

    int result = palindroma(s);

    if(result == 1) {
        printf("Palindroma");
        return 0;
    }

    else {
        printf("Non palindroma");
        return 0;
    }
    return 1;
}