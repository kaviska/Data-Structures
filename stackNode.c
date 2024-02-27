#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void push();
void pop();
void print();
int peek();

int main()
{
    int choice;
    do
    {
        printf("\n\033[1m----- Menu -----\033[0m\n");
        printf("\033[32m1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("5. Exit\033[0m\n");
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
            print();
            break;
        case 5:
            break;
        default:
            printf("\033[31mInvalid choice! Please enter a number between 1 and 5.\033[0m\n");
        }
    } while (choice != 5);

    return 0;
}

void push()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("\033[34mEnter data: \033[0m");
    scanf("%d", &(temp->data)); 
    if (head == NULL)
    {
        head = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    printf("\033[32mData inserted successfully.\033[0m\n");
}

void pop()
{
    int item;
    struct node *ptr;
    if (head == NULL)
    {
        printf("\033[31mEmpty Stack\033[0m\n");
    }
    else
    {
        ptr = head;
        item = head->data;
        head = head->next;
        printf("\033[33mPopped out stack item is %d\033[0m\n", item);
        free(ptr);
    }
}

void print()
{
    if (head == NULL)
    {
        printf("\033[31mEmpty Stack\033[0m\n");
    }
    else
    {
        struct node *temp;
        temp = head;
        printf("\033[34mStack: \033[0m");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int peek()
{
    if (head == NULL)
    {
        printf("\033[31mStack is empty\033[0m\n");
        return -1; // Assuming -1 indicates an empty stack
    }
    else
    {
        printf("\033[34mTop element of stack: %d\033[0m\n", head->data);
        return head->data;
    }
}
