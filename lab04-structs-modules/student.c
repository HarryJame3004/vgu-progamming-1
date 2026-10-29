// Lab 4 — Student management module: IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

// ===================== 4.1 Struct =====================
Student make_student(int id, const char *name, float gpa) {
    Student s = {0};
    s.id = id;
    s.gpa = gpa;
    if (name) {
        snprintf(s.name, MAX_NAME, "%s", name);
    }
    return s;
}

void print_student(const Student *s) {
    if (!s) return;
    printf("%6d  %-30s %.2f\n", s->id, s->name, s->gpa);
}

// ===================== 4.2 Linked list =====================
Node *list_push_front(Node *head, Student s) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) return head;
    node->data = s;
    node->next = head;
    return node;
}

Node *list_push_back(Node *head, Student s) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) return head;
    node->data = s;
    node->next = NULL;

    if (!head) {
        DEBUG_PRINT("push_back id=%d (new head)", s.id);
        return node;
    }

    Node *curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = node;
    DEBUG_PRINT("push_back id=%d", s.id);
    return head;
}

int list_length(const Node *head) {
    int n = 0;
    while (head) {
        n++;
        head = head->next;
    }
    return n;
}

Student *list_find(Node *head, int id) {
    while (head) {
        if (head->data.id == id) return &head->data;
        head = head->next;
    }
    return NULL;
}

Node *list_remove(Node *head, int id) {
    if (!head) return NULL;

    // remove head
    if (head->data.id == id) {
        Node *next = head->next;
        DEBUG_PRINT("remove id=%d (was head)", id);
        free(head);
        return next;
    }

    Node *prev = head;
    Node *curr = head->next;
    while (curr) {
        if (curr->data.id == id) {
            prev->next = curr->next;
            DEBUG_PRINT("remove id=%d", id);
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    return head; // not found
}

void list_print(const Node *head) {
    printf("ID      Name                           GPA\n");
    printf("------  ------------------------------ -----\n");
    while (head) {
        print_student(&head->data);
        head = head->next;
    }
}

void list_free(Node *head) {
    while (head) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

// ===================== 4.3 Function pointers =====================
int compare_by_id(const void *a, const void *b) {
    const Student *sa = (const Student *)a;
    const Student *sb = (const Student *)b;
    return sa->id - sb->id;
}

int compare_by_name(const void *a, const void *b) {
    const Student *sa = (const Student *)a;
    const Student *sb = (const Student *)b;
    return strcmp(sa->name, sb->name);
}

int compare_by_gpa_desc(const void *a, const void *b) {
    const Student *sa = (const Student *)a;
    const Student *sb = (const Student *)b;
    // Cannot subtract floats for qsort; use comparison
    if (sa->gpa > sb->gpa) return -1;
    if (sa->gpa < sb->gpa) return 1;
    return 0;
}

int list_to_array(const Node *head, Student out[], int max) {
    int i = 0;
    while (head && i < max) {
        out[i++] = head->data;
        head = head->next;
    }
    return i;
}

void sort_students(Student arr[], int n, StudentCompare cmp) {
    if (!arr || n <= 0 || !cmp) return;
    qsort(arr, n, sizeof(Student), cmp);
}

int is_excellent(const Student *s) {
    return s && s->gpa >= 3.6f;
}

int count_if(const Node *head, StudentPredicate pred) {
    if (!pred) return 0;
    int cnt = 0;
    while (head) {
        if (pred(&head->data)) cnt++;
        head = head->next;
    }
    return cnt;
}
