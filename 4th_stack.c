#include<stdio.h>
#define max 5

int st[max], top = -1;

void push() {
    int x;
    if (top == max - 1) {
        printf("Stack is full\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);
    top++;
    st[top] = x;
    printf("Element pushed: %d\n", x);
}

void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Element popped: %d\n", st[top]);
    top--;
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", st[i]);
    }
}

int main() {
    int ch;
    while (1) {
        printf("Enter\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Please enter a valid choice\n");
        }
    }
    return 0;
}