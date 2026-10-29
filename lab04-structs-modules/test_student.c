// Lab 4 — Tests for the student module
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

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

int main(void) {
    printf("=== Lab 04 Student Module Tests ===\n\n");

    // 4.1 make_student
    printf("4.1 make_student\n");
    Student s1 = make_student(1001, "Nguyen Van An", 3.45f);
    CHECK(s1.id == 1001);
    CHECK(strcmp(s1.name, "Nguyen Van An") == 0);
    CHECK(s1.gpa > 3.44f && s1.gpa < 3.46f);

    // long name truncation
    char longname[100];
    memset(longname, 'A', 80);
    longname[80] = '\0';
    Student s2 = make_student(1002, longname, 2.0f);
    CHECK(strlen(s2.name) < MAX_NAME);

    // 4.2 Linked list
    printf("4.2 linked list\n");
    Node *list = NULL;
    list = list_push_front(list, make_student(1, "Alice", 3.8f));
    list = list_push_front(list, make_student(2, "Bob", 3.2f));
    list = list_push_back(list, make_student(3, "Carol", 3.9f));
    CHECK(list_length(list) == 3);

    Student *found = list_find(list, 2);
    CHECK(found != NULL && strcmp(found->name, "Bob") == 0);
    found->gpa = 3.5f; // modify in place
    CHECK(list_find(list, 2)->gpa > 3.49f);

    list = list_remove(list, 2);
    CHECK(list_length(list) == 2);
    CHECK(list_find(list, 2) == NULL);

    list = list_remove(list, 1); // remove new head
    CHECK(list_length(list) == 1);
    CHECK(list->data.id == 3);

    list_free(list);
    list = NULL;

    // rebuild for function pointer tests
    list = list_push_back(list, make_student(10, "Zoe", 2.5f));
    list = list_push_back(list, make_student(20, "Anna", 3.7f));
    list = list_push_back(list, make_student(15, "Mike", 3.9f));

    printf("4.3 function pointers\n");
    Student arr[10];
    int n = list_to_array(list, arr, 10);
    CHECK(n == 3);

    sort_students(arr, n, compare_by_name);
    CHECK(strcmp(arr[0].name, "Anna") == 0);

    sort_students(arr, n, compare_by_gpa_desc);
    CHECK(arr[0].gpa > arr[1].gpa);

    CHECK(is_excellent(&arr[0]) == 1);
    CHECK(count_if(list, is_excellent) == 2);

    list_free(list);

    printf("\nResult: %d/%d PASS\n", passed, total);
    return passed == total ? 0 : 1;
}
