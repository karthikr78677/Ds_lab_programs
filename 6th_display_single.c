#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node {
    int value;
    struct node *next;
};

void insert();  // Function to insert a node into the linked list
void display(); // Function to display the linked list

typedef struct node DATA_NODE;
DATA_NODE *head_node, *first_node = NULL, *temp_node = NULL;
int data;

int main() {
    int option = 0;
    printf("Singly Linked List Example - Insertion and Display Operations\n");

    while (option < 3) {
        printf("\nOptions\n");
        printf("1: Insert into Linked List\n");
        printf("2: Display Linked List\n");
        printf("Others: Exit\n");
        printf("Enter your Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: insert(); break;
            case 2: display(); break;
            default: break;
        }
    }

    return 0;
}

void insert() {
    printf("\nEnter Element to Insert into Linked List: ");
    scanf("%d", &data);

    temp_node = (DATA_NODE *) malloc(sizeof(DATA_NODE));
    temp_node->value = data;
    temp_node->next = NULL;

    if (first_node == NULL) {  // If the list is empty, the new node becomes the first node
        first_node = temp_node;
    } else {  // If the list is not empty, insert at the end
        head_node->next = temp_node;
    }
    head_node = temp_node;  // Update the head node
}

void display() {
    int count = 0;
    temp_node = first_node;

    if (temp_node == NULL) {
        printf("\nThe Linked List is Empty\n");
        return;
    }

    printf("\nDisplaying Linked List:\n");
    while (temp_node != NULL) {
        printf(" #%d# ", temp_node->value);
        count++;
        temp_node = temp_node->next;
    }
    printf("\nNumber of items in the Linked List: %d\n", count);
}