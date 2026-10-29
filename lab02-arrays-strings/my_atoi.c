// Homework 2.11 — my_atoi (supports optional leading + / -)
// Compile: gcc -Wall -Wextra my_atoi.c -o my_atoi && ./my_atoi

#include <stdio.h>

int my_atoi(const char s[]) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // skip leading spaces
    while (s[i] == ' ' || s[i] == '\t') i++;

    // optional sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');
        i++;
    }
    return sign * result;
}

int main(void) {
    printf("my_atoi(\"42\")     = %d\n", my_atoi("42"));
    printf("my_atoi(\"-17\")    = %d\n", my_atoi("-17"));
    printf("my_atoi(\"+100\")   = %d\n", my_atoi("+100"));
    printf("my_atoi(\"  007\")  = %d\n", my_atoi("  007"));
    printf("my_atoi(\"abc\")    = %d\n", my_atoi("abc"));
    return 0;
}
