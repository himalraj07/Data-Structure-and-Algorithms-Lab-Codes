/*
    To Become familiar with Queue Implementation using Linked List.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void insert(int);
void deleteElement();
void display();

int main()
{
    int choice, value;
    printf("\nQueue Implementation using Linked List:\n\n");
    while (1)
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted : ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            deleteElement();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program ...\n\n");
            exit(0);
        default:
            printf("\nWrong selection ! Please try again .\n\n");
        }
    }
    return 0;
}

void insert(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (front == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Insertion is Successful !\n\n");
}

void deleteElement()
{
    if (front == NULL)
        printf("Queue is Empty !\n\n");
    else
    {
        struct Node *temp = front;
        front = front->next;
        printf("Deleted element is : %d\n\n", temp->data);
        free(temp);
    }
}

void display()
{
    if (front == NULL)
        printf("Queue is Empty !\n\n");
    else
    {
        struct Node *temp = front;
        printf("Queue elements are : ");
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
            if (temp != NULL)
                printf(" ---> ");
        }
        printf("\n\n");
    }
}