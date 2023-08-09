#include <stdio.h>
#include <string.h>

#define d 256
#define q 101

void searchRabinKarp(char *pattern, char *text) {
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int i, j;
    int pHash = 0;
    int tHash = 0;
    int h = 1;

    for (i = 0; i < patternLength - 1; i++) {
        h = (h * d) % q;
    }

    for (i = 0; i < patternLength; i++) {
        pHash = (d * pHash + pattern[i]) % q;
        tHash = (d * tHash + text[i]) % q;
    }

    for (i = 0; i <= textLength - patternLength; i++) {
        if (pHash == tHash) {
            for (j = 0; j < patternLength; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == patternLength) {
                printf("Pattern found at index %d\n", i);
            }
        }

        if (i < textLength - patternLength) {
            tHash = (d * (tHash - text[i] * h) + text[i + patternLength]) % q;
            if (tHash < 0) {
                tHash = (tHash + q);
            }
        }
    }
}

int main() {
    char text[] = "ABCCDDAEFGCABCABABC";
    char pattern[] = "ABC";

    searchRabinKarp(pattern, text);

    return 0;
}
