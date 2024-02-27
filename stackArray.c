#include <stdio.h>
#include <stdlib.h>
#define N 200

int top = -1;
int stack[N];

void push();
void pop();
void peek();
void printStack();

int main()
{
    int choice;
    do
    {
        printf("\n----- Menu -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            printStack();
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

void push()
{
    if (top == N - 1)
    {
        printf("Stack is full. You cannot add more data.\n");
        return;
    }
    
    printf("Enter Your Data: ");
    int value;
    scanf("%d", &value);

    top++;
    stack[top] = value;
    printf("Data inserted successfully.\n");
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty. Nothing to pop.\n");
        return;
    }
    
    printf("Value popped out: %d\n", stack[top]);
    top--;
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty. No element to peek.\n");
        return;
    }
    
    printf("Top element of stack: %d\n", stack[top]);
}

void printStack()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
