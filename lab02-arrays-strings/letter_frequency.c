// Homework 2.12 — Count letter frequency a–z (case-insensitive)
// Compile: gcc -Wall -Wextra letter_frequency.c -o letter_frequency
// Usage:   echo "Hello World" | ./letter_frequency

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int count[26] = {0};
    int c;

    printf("Enter text (Ctrl+D to finish):\n");
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            c = tolower(c);
            count[c - 'a']++;
        }
    }

    printf("\nLetter frequency:\n");
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("  %c : %d\n", 'a' + i, count[i]);
        }
    }
    return 0;
}
