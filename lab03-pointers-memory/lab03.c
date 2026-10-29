// Lab 3 — Pointers and Dynamic Memory (Completed Solution)
// Compile and run:  gcc -Wall -Wextra -g lab03.c -o lab03 && ./lab03
// Check memory:     valgrind --leak-check=full ./lab03
#include <stdio.h>
#include <stdlib.h>
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

static int same_array(const int *a, const int *b, int n) {
    if (a == NULL || b == NULL) return 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

// 3.1 Swap the values of two variables
void swap(int *a, int *b) {
    if (!a || !b) return;
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3.2 Find the min and max of the array (n >= 1), returned through pointers
void min_max(const int *a, int n, int *min, int *max) {
    if (!a || n <= 0 || !min || !max) return;
    *min = a[0];
    *max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < *min) *min = a[i];
        if (a[i] > *max) *max = a[i];
    }
}

// 3.3 Sum of the array using pointer arithmetic (*p and p++)
int sum_pointer(const int *a, int n) {
    if (!a || n <= 0) return 0;
    int sum = 0;
    const int *p = a;
    for (int i = 0; i < n; i++) {
        sum += *p;
        p++;
    }
    return sum;
}

// 3.4 Return a copy of the array, allocated on the heap
int *copy_array(const int *a, int n) {
    if (!a || n <= 0) return NULL;
    int *c = (int *)malloc(n * sizeof(int));
    if (!c) return NULL;
    for (int i = 0; i < n; i++) {
        c[i] = a[i];
    }
    return c;
}

// 3.5 Return a new array containing only the even numbers of a
int *filter_even(const int *a, int n, int *returnSize) {
    if (!a || n <= 0 || !returnSize) {
        if (returnSize) *returnSize = 0;
        return NULL;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) count++;
    }
    *returnSize = count;
    if (count == 0) return NULL;

    int *evens = (int *)malloc(count * sizeof(int));
    if (!evens) {
        *returnSize = 0;
        return NULL;
    }
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            evens[idx++] = a[i];
        }
    }
    return evens;
}

// 3.6 Implement strdup: return a heap copy of the string s (+1 for '\0')
char *my_strdup(const char *s) {
    if (!s) return NULL;
    int len = 0;
    while (s[len] != '\0') len++;
    char *copy = (char *)malloc(len + 1);
    if (!copy) return NULL;
    for (int i = 0; i < len; i++) {
        copy[i] = s[i];
    }
    copy[len] = '\0';
    return copy;
}

// 3.7 Append value to the end of the dynamic array arr with doubling capacity
int *push_back(int *arr, int *size, int *capacity, int value) {
    if (!size || !capacity) return arr;
    if (*size == *capacity) {
        int new_cap = (*capacity == 0) ? 1 : (*capacity * 2);
        int *temp = (int *)realloc(arr, new_cap * sizeof(int));
        if (!temp) return arr;
        arr = temp;
        *capacity = new_cap;
    }
    arr[*size] = value;
    (*size)++;
    return arr;
}

// 3.8 Allocate a rows x cols matrix initialized to all 0
int **alloc_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return NULL;
    int **m = (int **)malloc(rows * sizeof(int *));
    if (!m) return NULL;
    for (int i = 0; i < rows; i++) {
        m[i] = (int *)calloc(cols, sizeof(int));
        if (!m[i]) {
            for (int k = 0; k < i; k++) free(m[k]);
            free(m);
            return NULL;
        }
    }
    return m;
}

// 3.8 Free matrix: each row first, then the array of pointers
void free_matrix(int **m, int rows) {
    if (!m) return;
    for (int i = 0; i < rows; i++) {
        if (m[i]) free(m[i]);
    }
    free(m);
}

// 3.9 Allocate an int on the heap and assign its address to *p
void allocate_int(int **p, int value) {
    if (!p) return;
    *p = (int *)malloc(sizeof(int));
    if (*p) {
        **p = value;
    }
}

int main(void) {
    printf("3.1 swap\n");
    int x = 1, y = 2;
    swap(&x, &y);
    CHECK(x == 2 && y == 1);

    printf("3.2 min_max\n");
    int a2[] = {4, -7, 9, 0, 3};
    int mn = 0, mx = 0;
    min_max(a2, 5, &mn, &mx);
    CHECK(mn == -7 && mx == 9);

    printf("3.3 sum_pointer\n");
    CHECK(sum_pointer(a2, 5) == 9);

    printf("3.4 copy_array\n");
    int *cp = copy_array(a2, 5);
    CHECK(cp != NULL && same_array(cp, a2, 5));
    free(cp);

    printf("3.5 filter_even\n");
    int retSize = 0;
    int *ev = filter_even(a2, 5, &retSize);
    CHECK(retSize == 2 && ev != NULL && ev[0] == 4 && ev[1] == 0);
    free(ev);

    printf("3.6 my_strdup\n");
    char *dup = my_strdup("hello");
    CHECK(dup != NULL && strcmp(dup, "hello") == 0);
    free(dup);

    printf("3.7 push_back\n");
    int *dyn = NULL;
    int sz = 0, cap = 0;
    dyn = push_back(dyn, &sz, &cap, 10);
    dyn = push_back(dyn, &sz, &cap, 20);
    dyn = push_back(dyn, &sz, &cap, 30);
    CHECK(sz == 3 && dyn[0] == 10 && dyn[1] == 20 && dyn[2] == 30);
    free(dyn);

    printf("3.8 alloc_matrix / free_matrix\n");
    int **mat = alloc_matrix(2, 3);
    CHECK(mat != NULL && mat[0][0] == 0 && mat[1][2] == 0);
    mat[0][1] = 42;
    CHECK(mat[0][1] == 42);
    free_matrix(mat, 2);

    printf("3.9 allocate_int\n");
    int *p = NULL;
    allocate_int(&p, 99);
    CHECK(p != NULL && *p == 99);
    free(p);

    printf("\nResult: %d/%d PASS\n", passed, total);
    return passed == total ? 0 : 1;
}
