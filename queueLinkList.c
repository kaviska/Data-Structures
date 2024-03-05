#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void enque();
void deqe();
void display();

int main() {
    int choice;
    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enque();
                break;
            case 2:
                deqe();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}

void enque() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter Your data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        struct node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void deqe() {
    if (head == NULL) {
        printf("Empty Queue\n");
    } else {
        printf("Dequeued element: %d\n", head->data);
        struct node *ptr = head;
        head = head->next;
        free(ptr);
    }
}

void display() {
    if (head == NULL) {
        printf("Empty Queue\n");
    } else {
        printf("Queue elements: ");
        struct node *ptr = head;
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
