#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node DATA_NODE;
DATA_NODE *head_node = NULL; // Initialize head node as NULL

void insert();

int main() {
    int option = 0;
    printf("Singly Linked List Example - Insertion Only\n");

    while (option != 3) {
        printf("\nOptions\n");
        printf("1: Insert into Linked List\n");
        printf("Others: Exit()\n");
        printf("Enter your Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                insert();
                break;
            default:
                printf("Exiting...\n");
                break;
        }
    }

    return 0;
}

void insert() {
    int data;
    printf("\nEnter Element to Insert into Linked List: ");
    scanf("%d", &data);

    DATA_NODE *temp_node = (DATA_NODE *)malloc(sizeof(DATA_NODE));
    if (temp_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    temp_node->value = data;
    temp_node->next = NULL; // Initialize the next pointer to NULL

    // If the list is empty, make the new node the head
    if (head_node == NULL) {
        head_node = temp_node;
    } else {
        // Traverse to the end of the list and insert the new node
        DATA_NODE *current = head_node;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp_node; // Insert the new node at the end
    }

    printf("Inserted %d into the linked list.\n", data);
}