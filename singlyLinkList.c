#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void InsertAtBegin();
void InsertAtEnd();
void insertPosition();
void display();
void deleteAtBegining();
void deleteAtTheEnd();
void deleteAtThePosition();
void searchData();
void updateData();
void freeLinkedList();

int main()
{
    int choice;
    do
    {
        printf("\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete at a specific position\n");
        printf("7. Search data\n");
        printf("8. Update data\n");
        printf("9. Display\n");
        printf("10. Free Linked List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            InsertAtBegin();
            break;
        case 2:
            InsertAtEnd();
            break;
        case 3:
            insertPosition();
            break;
        case 4:
            deleteAtBegining();
            break;
        case 5:
            deleteAtTheEnd();
            break;
        case 6:
            deleteAtThePosition();
            break;
        case 7:
            searchData();
            break;
        case 8:
            updateData();
            break;
        case 9:
            display();
            break;
        case 10:
            freeLinkedList();
            break;
        case 11:
            printf("Exiting the program\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 11);

    return 0;
}

void InsertAtBegin()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    temp->data = data;
    temp->next = head;
    head = temp;

    printf("Successfully added node to the beginning\n");
}

void InsertAtEnd()
{
    struct node *ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    printf("Successfully added node to the end\n");
}

void insertPosition()
{
    int position;
    printf("Enter position: ");
    scanf("%d", &position);

    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    struct node *ptr = head;
    struct node *prevptr = NULL;

    for (int i = 1; i < position && ptr != NULL; i++)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL && position > 1)
    {
        printf("Invalid position\n");
        return;
    }

    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;

    if (position == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        temp->next = ptr;
        prevptr->next = temp;
    }

    printf("Successfully added node at position %d\n", position);
}

void display()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void deleteAtBegining()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *ptr = head;
    head = head->next;
    free(ptr);

    printf("Node deleted from the beginning\n");
}

void deleteAtTheEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if (head->next == NULL)
    {
        struct node *ptr = head;
        head = NULL;
        free(ptr);
        printf("Node deleted from the end\n");
    }
    else
    {
        struct node *ptr = head;
        struct node *prevptr = NULL;
        while (ptr->next != NULL)
        {
            prevptr = ptr;
            ptr = ptr->next;
        }
        prevptr->next = NULL;
        free(ptr);
        printf("Node deleted from the end\n");
    }
}

void deleteAtThePosition()
{
    int position;
    printf("Enter The Position: ");
    scanf("%d", &position);
    if (head == NULL)
    {
        printf("Link List is Empty\n");
        return;
    }
    else if (position == 0)
    {
        struct node *ptr = head;
        head->next = NULL;
        free(ptr);
        return;
    }
    struct node *ptr = head;
    struct node *prevptr = NULL;
    for (int i = 0; i < position; i++)
    {
        if (ptr == NULL)
        {
            printf("You added Wrong position\n");
        }
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr->next = ptr->next;
    free(ptr);
    printf("Sucessfully Deleted Node at given Position\n");
}

void searchData()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    int key;
    printf("Enter data to search: ");
    scanf("%d", &key);

    struct node *ptr = head;
    int found = 0;
    int position = 0;

    while (ptr != NULL)
    {
        position++;
        if (ptr->data == key)
        {
            printf("Data found at position: %d\n", position);
            found = 1;
        }
        ptr = ptr->next;
    }

    if (!found)
    {
        printf("Data not found\n");
    }
}

void updateData()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    int oldData, newData;
    printf("Enter data to update: ");
    scanf("%d", &oldData);

    printf("Enter new data: ");
    scanf("%d", &newData);

    struct node *ptr = head;
    int found = 0;

    while (ptr != NULL)
    {
        if (ptr->data == oldData)
        {
            ptr->data = newData;
            printf("Data updated successfully\n");
            found = 1;
        }
        ptr = ptr->next;
    }

    if (!found)
    {
        printf("Data not found\n");
    }
}

void freeLinkedList()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        struct node *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    head = NULL;
    printf("Linked list freed successfully\n");
}
