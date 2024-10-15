#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head = NULL;

void insertion_beginning();
void insertion_last();
void deletion_beginning();
void deletion_last();

int main() {
    int choice = 0;
    
    while (choice != 5) {
        printf("\n****Main Menu****\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at last\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from Last\n");
        printf("5. Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insertion_beginning();
                break;
            case 2:
                insertion_last();
                break;
            case 3:
                deletion_beginning();
                break;
            case 4:
                deletion_last();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Please enter a valid choice..\n");
        }
    }
    return 0;
}

void insertion_beginning() {
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("\nEnter Item value: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->prev = NULL;
        ptr->next = head;

        if (head != NULL) {
            head->prev = ptr;
        }
        
        head = ptr;
        printf("\nNode inserted at the beginning\n");
    }
}

void insertion_last() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = NULL;

        if (head == NULL) {
            ptr->prev = NULL;
            head = ptr;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
        }
        printf("\nNode inserted at the end\n");
    }
}

void deletion_beginning() {
    struct node *ptr;

    if (head == NULL) {
        printf("\nUNDERFLOW\n");
    } else {
        ptr = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }
        
        free(ptr);
        printf("\nNode deleted from the beginning\n");
    }
}

void deletion_last() {
    struct node *ptr;

    if (head == NULL) {
        printf("\nUNDERFLOW\n");
    } else {
        ptr = head;

        if (ptr->next == NULL) { // Only one node in the list
            head = NULL;
        } else {
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->prev->next = NULL;
        }
        free(ptr);
        printf("\nNode deleted from the end\n");
    }
}