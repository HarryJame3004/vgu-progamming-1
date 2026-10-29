// Lab 3 — Valgrind exercise: FIXED VERSION
// All 4 memory bugs resolved:
//   Bug 1: line 16, malloc without checking NULL
//   Bug 2: line 22, wrote past allocated size (off-by-one)
//   Bug 3: line 28, used freed memory (dangling pointer)
//   Bug 4: line 35, memory leak (forgot free)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *make_name(void) {
    char *name = (char *)malloc(20);
    if (!name) return NULL;   // FIX BUG 1: check malloc result
    strcpy(name, "Alice");
    return name;
}

int *make_squares(int n) {
    // FIX BUG 2: allocate exactly n ints
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) return NULL;
    for (int i = 0; i < n; i++)
        arr[i] = i * i;
    return arr;
}

int main(void) {
    char *name = make_name();
    if (!name) return 1;
    printf("name = %s\n", name);

    int *squares = make_squares(5);
    if (!squares) {
        free(name);
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += squares[i];

    if (sum > 0)
        printf("sum of squares = %d\n", sum);

    // FIX BUG 3: Read squares[1] BEFORE calling free
    printf("first square = %d\n", squares[1]);
    free(squares);

    // FIX BUG 4: Free dynamic string to avoid leak
    free(name);

    return 0;
}
