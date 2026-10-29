// Lab 2 — Debugging exercise (Fixed Version)
// Record of the 4 bugs found and fixed:
//   Bug 1: line 16, sum_array skipped a[0] (loop started at i=1). Fix: for (int i = 0; i < n; i++)
//   Bug 2: line 22, average did integer division (151 / 5 = 30). Fix: (double)sum_array(a, n) / n
//   Bug 3: line 26, max_array initialized max = 0, failing on all-negative arrays. Fix: int max = a[0]; loop i=1
//   Bug 4: line 34, reverse_string looped until i < len, swapping elements twice. Fix: loop until i < len / 2

#include <stdio.h>

#define N 5

int sum_array(int a[], int n) {
    int sum = 0;
    // FIX BUG 1: loop from i = 0
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

double average(int a[], int n) {
    // FIX BUG 2: cast sum to double to prevent integer truncation
    return (double)sum_array(a, n) / n;
}

int max_array(int a[], int n) {
    // FIX BUG 3: initialize max to a[0] to support negative values
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void reverse_string(char s[], int len) {
    // FIX BUG 4: only swap up to the middle of the string
    for (int i = 0; i < len / 2; i++) {
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}

int main(void) {
    int data[N] = {10, 20, 30, 40, 51};
    int temps[N] = {-5, -3, -8, -1, -9}; // winter temperatures

    printf("sum = %d\n", sum_array(data, N));          // Expected: 151
    printf("average = %.2f\n", average(data, N));      // Expected: 30.20
    printf("max = %d\n", max_array(data, N));          // Expected: 51
    printf("max temp = %d\n", max_array(temps, N));    // Expected: -1

    char word[] = "hello";
    reverse_string(word, 5);
    printf("reversed: %s\n", word);                    // Expected: olleh

    return 0;
}
