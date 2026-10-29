// Homework 1.9 — Temperature table (Fahrenheit → Celsius)
// Compile: gcc -Wall -Wextra temperature.c -o temperature
// Test:    echo "0 300 20" | ./temperature

#include <stdio.h>

int main(void) {
    float lower, upper, step;

    printf("Enter lower upper step: ");
    if (scanf("%f %f %f", &lower, &upper, &step) != 3) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    if (step <= 0 || lower > upper) {
        fprintf(stderr, "Error: step must be > 0 and lower <= upper\n");
        return 1;
    }

    printf("\n  F      C\n");
    printf("-------------\n");

    for (float fahr = lower; fahr <= upper; fahr += step) {
        float celsius = (5.0f / 9.0f) * (fahr - 32.0f);
        printf("%3.0f %6.1f\n", fahr, celsius);
    }

    return 0;
}
