#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dnode {
    struct dnode *prev;
    char AadharNo[11];  
    struct dnode *next;
} *head = NULL;

// Function to insert a new node at the end of the list
void insert(char AadharNo[]) {
    struct dnode *q, *p = (struct dnode *)malloc(sizeof(struct dnode));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return; // Return without exiting the program
    }
    strcpy(p->AadharNo, AadharNo);
    p->next = NULL;
    if (head == NULL) {
        p->prev = NULL;
        head = p;
    } else {
        q = head;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
        p->prev = q;
    }
}

// Function to insert a new node at a specific position
void insertAtPos(char *AadharNo, int pos) {
    int i;
    struct dnode *q = head, *p = (struct dnode *)malloc(sizeof(struct dnode));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return; // Return without exiting the program
    }
    strcpy(p->AadharNo, AadharNo);
    if (pos <= 0) {
        p->prev = NULL;
        p->next = q;
        if (q != NULL) {
            q->prev = p;
        }
        head = p;
    } else {
        for (i = 1; i < pos && q != NULL; i++) {
            q = q->next;
        }
        if (q != NULL) {
            p->next = q->next;
            p->prev = q;
            if (q->next != NULL) {
                q->next->prev = p;
            }
            q->next = p;
        } else {
            // Insert at the end of the list if pos exceeds the list size
            q = head;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
            p->prev = q;
            p->next = NULL;
        }
    }
}

// Function to count the number of nodes in the list
int countList() {
    int count = 0;
    struct dnode *q = head;
    while (q != NULL) {
        count++;
        q = q->next;
    }
    return count;
}

// Function to display the list
void display() {
    struct dnode *q = head;
    while (q != NULL) {
        printf("\nAadhar Number: %s", q->AadharNo);
        q = q->next;
    }
}

// Function to clear memory and delete all nodes
void clearAll() {
    struct dnode *p, *q = head;
    while (q != NULL) {
        p = q;
        q = q->next;
        free(p);
    }
}

int main() {
    int n, pos;
    char AadharNo[11]; // Increased the size to accommodate the PAN and the null terminator
    printf("Enter the number of people: ");
    scanf("%d", &n);
    int i;
    for (i=0; i < n; i++) {
        printf("\nEnter Aadhar Number of person %d: ", i + 1);
        scanf("%12s", AadharNo); // Limit input to 12 characters
        insert(AadharNo);
    }
    printf("\nThe list is: ");
    display();
    printf("\nEnter the Aadhar Number of the new employee: ");
    scanf("%12s", AadharNo); // Limit input to 12 characters
    int count = countList();
    pos = (count+1)/2;
    if (pos < 0 || pos > count) {
        printf("Position value out of bounds");
    } else {
        insertAtPos(AadharNo, pos);
        printf("\n\nThe new list is: ");
        display();
    }

    clearAll();
    return 0;
}


