// Homework 1.10 — Pocket calculator (top-down design)
// Compile: gcc -Wall -Wextra calculator.c -o calculator && ./calculator

#include <stdio.h>
#include <math.h>

double add(double a, double b)      { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b == 0.0) {
        fprintf(stderr, "Error: division by zero\n");
        return 0.0;
    }
    return a / b;
}
double power(double a, double b)    { return pow(a, b); }

void print_menu(void) {
    printf("\n===== Pocket Calculator =====\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("0. Exit\n");
    printf("Choice: ");
}

int main(void) {
    int choice;
    double a, b, result;

    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) break;
        if (choice == 0) {
            printf("Goodbye!\n");
            break;
        }
        if (choice < 1 || choice > 5) {
            printf("Invalid choice\n");
            continue;
        }

        printf("Enter two numbers: ");
        if (scanf("%lf %lf", &a, &b) != 2) {
            printf("Invalid numbers\n");
            continue;
        }

        switch (choice) {
            case 1: result = add(a, b);      break;
            case 2: result = subtract(a, b); break;
            case 3: result = multiply(a, b); break;
            case 4: result = divide(a, b);   break;
            case 5: result = power(a, b);    break;
            default: continue;
        }
        printf("Result = %.6g\n", result);
    }
    return 0;
}
