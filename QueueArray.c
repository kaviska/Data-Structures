#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 200

int queue[MAX_SIZE];
int front = 0;
int rear = -1;
int size = 0;

void enque();
void deque();
void display();
bool isFull();
bool isEmpty();

int main()
{
    int choice;

    while (1)
    {
        printf("\nQueue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

void enque()
{
    if (!isFull())
    {
        printf("Enter data to enqueue: ");
        rear++;
        scanf("%d", &queue[rear]);
        size++;
        printf("Element enqueued successfully.\n");
    }
    else
    {
        printf("Queue is full! Cannot enqueue.\n");
    }
}

void deque()
{
    if (!isEmpty())
    {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
        size--;
    }
    else
    {
        printf("Queue is empty! Cannot dequeue.\n");
    }
}

void display()
{
    if (!isEmpty())
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Queue is empty!\n");
    }
}

bool isFull()
{
    return size == MAX_SIZE;
}

bool isEmpty()
{
    return size == 0;
}
