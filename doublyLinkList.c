#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void insertAtBeginning();
void insertAtTheEnd();
void insertAtThePosition();
void printForward();
void printBackward();
void comparing();
void freeList();
void CircularLinkList();

int main() {
    int choice;

    do {
        printf("\nDoubly Linked List Operations\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Print the list forward\n");
        printf("5. Print the list backward\n");
        printf("6. Find maximum and minimum\n");
        printf("7. Print the list as circular\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtTheEnd();
                break;
            case 3:
                insertAtThePosition();
                break;
            case 4:
                printForward();
                break;
            case 5:
                printBackward();
                break;
            case 6:
                comparing();
                break;
            case 7:
                CircularLinkList();
                break;
            case 8:
                freeList(); // Free allocated memory before exiting
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 8.\n");
        }
    } while (choice != 8);

    return 0;
}

void insertAtBeginning() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data to insert at the beginning: ");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTheEnd() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data to insert at the end: ");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtThePosition() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    int position;
    printf("Enter the position to insert: ");
    scanf("%d", &position);

    printf("Enter data to insert at position %d: ", position);
    scanf("%d", &temp->data);

    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }

    if (head == NULL) { // If list is empty
        if (position != 1) {
            printf("Position out of range\n");
            return;
        }
        head = temp;
        tail = temp;
        temp->prev = NULL;
        temp->next = NULL;
        return;
    }

    struct node *ptr = head;
    for (int i = 1; i < position - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Position out of range\n");
        return;
    }

    temp->prev = ptr;
    temp->next = ptr->next;

    if (ptr->next != NULL) {
        ptr->next->prev = temp;
    } else {
        tail = temp;
    }

    ptr->next = temp;
}

void printForward() {
    struct node *ptr = head;
    if (head == NULL) {
        printf("No Doubly Linked List\n");
        return;
    }

    printf("List (forward): ");
    while (ptr != NULL) {
        printf("%d ", ptr->data); // Adding space for readability
        ptr = ptr->next;
    }
    printf("\n"); // Newline for clarity
}

void printBackward() {
    struct node *ptr = tail;
    if (head == NULL) {
        printf("No Doubly Linked List\n");
        return;
    }

    printf("List (backward): ");
    while (ptr != NULL) {
        printf("%d ", ptr->data); // Adding space for readability
        ptr = ptr->prev;
    }
    printf("\n"); // Newline for clarity
}

void comparing() {
    struct node *ptr = head;
    if (head == NULL) {
        printf("No Doubly Linked List\n");
        return;
    }

    int max = ptr->data;
    int min = ptr->data;

    while (ptr != NULL) {
        if (max < ptr->data) {
            max = ptr->data;
        }
        if (min > ptr->data) {
            min = ptr->data;
        }
        ptr = ptr->next;
    }
    printf("Maximum is %d and minimum is %d\n", max, min); // Newline for clarity
}

void CircularLinkList() {
    if (head == NULL) {
        printf("No Doubly Linked List\n");
        return;
    }

    tail->next = head; // Making the list circular

    struct node *ptr = head;

    printf("List (forward, considering as circular): ");
    while (ptr->next != head) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d ", ptr->data); // Printing the last node
    printf("\n");
}

void freeList() {
    struct node *current = head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    tail = NULL;
}
