#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
struct Node {
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

// Function declarations
void enqueue();
int dequeue();
void display();
int isEmpty();

int main() {
    int choice;

    while (1) {
        printf("\nMENU\n");
        printf("1. Insert an element into Queue\n");
        printf("2. Delete an element from Queue\n");
        printf("3. Display the Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                if (!isEmpty())
                    printf("\nThe deleted element is = %d\n", dequeue());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nYou entered an incorrect choice.\n");
                break;
        }
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    if (front == NULL) {
        printf("\nQueue is empty.\n");
        return 1;
    }
    return 0;
}

// Function to add an element to the queue
void enqueue() {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("\nMemory allocation failed.\n");
        return;
    }
    
    printf("Enter the element to insert: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\nElement inserted.\n");
}

// Function to remove and return the front element from the queue
int dequeue() {
    if (isEmpty()) {
        return -1;
    }

    struct Node *temp = front;
    int value = front->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return value;
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        return;
    }

    struct Node *temp = front;
    printf("\nQueue elements:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}