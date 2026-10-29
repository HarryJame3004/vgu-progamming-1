// Lab 2 — Arrays and Strings (Completed Solution)
// Compile and run:  gcc -Wall -Wextra -g lab02.c -o lab02 && ./lab02
#include <stdio.h>
#include <string.h>

static int passed = 0, total = 0;
#define CHECK(expr)                                 \
    do {                                            \
        total++;                                    \
        if (expr) {                                 \
            passed++;                               \
            printf("  PASS  %s\n", #expr);          \
        } else {                                    \
            printf("  FAIL  %s\n", #expr);          \
        }                                           \
    } while (0)

static int same_array(const int a[], const int b[], int n) {
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

#define ROWS 3
#define COLS 4

// 2.1 Maximum value of the array (n >= 1)
int array_max(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

// 2.2 Arithmetic mean (n >= 1)
double array_mean(int a[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / (double)n;
}

// 2.3 Reverse the array in place: {1, 2, 3} -> {3, 2, 1}
void reverse_array(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int tmp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = tmp;
    }
}

// 2.4 Number of occurrences of value in the array
int count_value(int a[], int n, int value) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == value) cnt++;
    }
    return cnt;
}

// 2.5 Max along an axis:
//   axis = 0: max of each COLUMN -> out has COLS elements
//   axis = 1: max of each ROW -> out has rows elements
void max_2d(int a[][COLS], int rows, int axis, int out[]) {
    if (axis == 0) {
        for (int c = 0; c < COLS; c++) {
            int mx = a[0][c];
            for (int r = 1; r < rows; r++) {
                if (a[r][c] > mx) mx = a[r][c];
            }
            out[c] = mx;
        }
    } else if (axis == 1) {
        for (int r = 0; r < rows; r++) {
            int mx = a[r][0];
            for (int c = 1; c < COLS; c++) {
                if (a[r][c] > mx) mx = a[r][c];
            }
            out[r] = mx;
        }
    }
}

// 2.6 Matrix multiplication: C = A x B, where A is 2x3, B is 3x2, C is 2x2
void matmul(int A[2][3], int B[3][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 2.7 Implement strlen yourself (do NOT use <string.h>)
int my_strlen(const char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

// 2.8 Convert lowercase letters to uppercase in place
void to_upper(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
    }
}

// 2.9 Return 1 if s is a palindrome, otherwise 0
int is_palindrome(const char s[]) {
    int len = 0;
    while (s[len] != '\0') len++;
    int left = 0, right = len - 1;
    while (left < right) {
        if (s[left] != s[right]) return 0;
        left++;
        right--;
    }
    return 1;
}

// 2.10 Count words; words are separated by one or more spaces ' '
int count_words(const char s[]) {
    int count = 0;
    int in_word = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }
    return count;
}

int main(void) {
    printf("2.1 array_max\n");
    int a1[] = {3, 9, -2, 7};
    int neg[] = {-5, -3, -8};
    CHECK(array_max(a1, 4) == 9);
    CHECK(array_max(neg, 3) == -3);

    printf("2.2 array_mean\n");
    int a2[] = {1, 2, 3, 4};
    CHECK(array_mean(a2, 4) == 2.5);
    CHECK(array_mean(neg, 3) > -5.34 && array_mean(neg, 3) < -5.33);

    printf("2.3 reverse_array\n");
    int r1[] = {1, 2, 3, 4, 5}, e1[] = {5, 4, 3, 2, 1};
    int r2[] = {1, 2, 3, 4}, e2[] = {4, 3, 2, 1};
    reverse_array(r1, 5);
    reverse_array(r2, 4);
    CHECK(same_array(r1, e1, 5));
    CHECK(same_array(r2, e2, 4));

    printf("2.4 count_value\n");
    int a4[] = {1, 2, 1, 3, 1};
    CHECK(count_value(a4, 5, 1) == 3);
    CHECK(count_value(a4, 5, 9) == 0);

    printf("2.5 max_2d\n");
    int m[ROWS][COLS] = {{1, 8, 3, 4}, {5, 2, 7, 0}, {9, 6, 1, 2}};
    int cols[COLS] = {0}, rows[ROWS] = {0};
    int ecols[] = {9, 8, 7, 4}, erows[] = {8, 7, 9};
    max_2d(m, ROWS, 0, cols);
    max_2d(m, ROWS, 1, rows);
    CHECK(same_array(cols, ecols, COLS));
    CHECK(same_array(rows, erows, ROWS));

    printf("2.6 matmul\n");
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int C[2][2] = {{0}};
    matmul(A, B, C);
    CHECK(C[0][0] == 58 && C[0][1] == 64);
    CHECK(C[1][0] == 139 && C[1][1] == 154);

    printf("2.7 my_strlen\n");
    CHECK(my_strlen("") == 0);
    CHECK(my_strlen("hello") == 5);

    printf("2.8 to_upper\n");
    char s8[] = "Hello, World 2024!";
    to_upper(s8);
    CHECK(strcmp(s8, "HELLO, WORLD 2024!") == 0);

    printf("2.9 is_palindrome\n");
    CHECK(is_palindrome("racecar") == 1);
    CHECK(is_palindrome("abba") == 1);
    CHECK(is_palindrome("") == 1);
    CHECK(is_palindrome("abca") == 0);

    printf("2.10 count_words\n");
    CHECK(count_words("hello world") == 2);
    CHECK(count_words("  hello   world ") == 2);
    CHECK(count_words("") == 0);
    CHECK(count_words("   ") == 0);
    CHECK(count_words("C") == 1);

    printf("\nResult: %d/%d PASS\n", passed, total);
    return passed == total ? 0 : 1;
}
