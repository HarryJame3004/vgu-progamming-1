// Homework 4.5 — Student management CLI (top-down, uses only student.h API)
// Compile: make app && ./app

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

static void flush_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static void print_menu(void) {
    printf("\n========== Student Manager ==========\n");
    printf("1. Add student\n");
    printf("2. Remove student by id\n");
    printf("3. Find by id\n");
    printf("4. Update GPA\n");
    printf("5. Print list (sorted by: 1=id  2=name  3=GPA desc)\n");
    printf("6. Count excellent students (GPA >= 3.6)\n");
    printf("0. Exit\n");
    printf("Choice: ");
}

static Node *do_add(Node *list) {
    int id;
    char name[MAX_NAME];
    float gpa;

    printf("ID: ");
    if (scanf("%d", &id) != 1) { flush_stdin(); return list; }
    flush_stdin();

    printf("Name: ");
    if (!fgets(name, sizeof(name), stdin)) return list;
    name[strcspn(name, "\n")] = '\0';

    printf("GPA: ");
    if (scanf("%f", &gpa) != 1) { flush_stdin(); return list; }
    flush_stdin();

    list = list_push_back(list, make_student(id, name, gpa));
    printf("Added.\n");
    return list;
}

static Node *do_remove(Node *list) {
    int id;
    printf("ID to remove: ");
    if (scanf("%d", &id) != 1) { flush_stdin(); return list; }
    flush_stdin();
    list = list_remove(list, id);
    printf("Done.\n");
    return list;
}

static void do_find(Node *list) {
    int id;
    printf("ID to find: ");
    if (scanf("%d", &id) != 1) { flush_stdin(); return; }
    flush_stdin();
    Student *s = list_find(list, id);
    if (s) print_student(s);
    else printf("Not found.\n");
}

static void do_update_gpa(Node *list) {
    int id;
    float gpa;
    printf("ID: ");
    if (scanf("%d", &id) != 1) { flush_stdin(); return; }
    printf("New GPA: ");
    if (scanf("%f", &gpa) != 1) { flush_stdin(); return; }
    flush_stdin();
    Student *s = list_find(list, id);
    if (s) {
        s->gpa = gpa;
        printf("Updated.\n");
    } else {
        printf("Not found.\n");
    }
}

static void do_print_sorted(Node *list) {
    int mode;
    printf("Sort by (1=id, 2=name, 3=GPA desc): ");
    if (scanf("%d", &mode) != 1) { flush_stdin(); return; }
    flush_stdin();

    StudentCompare sorters[] = {
        compare_by_id,
        compare_by_name,
        compare_by_gpa_desc
    };
    if (mode < 1 || mode > 3) mode = 1;

    Student arr[200];
    int n = list_to_array(list, arr, 200);
    if (n == 0) {
        printf("(empty list)\n");
        return;
    }
    sort_students(arr, n, sorters[mode - 1]);
    printf("ID      Name                           GPA\n");
    printf("------  ------------------------------ -----\n");
    for (int i = 0; i < n; i++) print_student(&arr[i]);
}

static void do_count_excellent(Node *list) {
    int cnt = count_if(list, is_excellent);
    printf("Excellent students: %d\n", cnt);
}

int main(void) {
    Node *list = NULL;
    int choice;

    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            flush_stdin();
            continue;
        }
        flush_stdin();

        switch (choice) {
            case 0:
                list_free(list);
                printf("Bye!\n");
                return 0;
            case 1: list = do_add(list); break;
            case 2: list = do_remove(list); break;
            case 3: do_find(list); break;
            case 4: do_update_gpa(list); break;
            case 5: do_print_sorted(list); break;
            case 6: do_count_excellent(list); break;
            default: printf("Invalid choice\n"); break;
        }
    }
}
