/*
    [ Doubly Linked List ]
    To Become familiar with doubly linked list operations ( PUSH Operation, POP Operation and Traversal Operation ).
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
} *front, *rear;

void dpush()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter a data: ");
    scanf("%d", &temp->data);
    temp->next = front;
    temp->prev = NULL;
    if (front != NULL)
    {
        front->prev = temp;
    }
    front = temp;
    if (rear == NULL)
    {
        rear = front;
    }
    printf("Item pushed successfully!\n");
}

void dpop()
{
    int x;
    struct node *temp;
    if (front == NULL)
    {
        printf("List is empty nothing to delete !!\n");
        return;
    }
    x = front->data;
    temp = front;
    front = front->next;
    free(temp);
    if (front != NULL)
    {
        front->prev = NULL;
    }
    else
    {
        rear = NULL;
    }
    printf("%d is the deleted item.\n", x);
}

void dinject()
{
    int x;
    struct node *temp;
    printf("Enter data: ");
    scanf("%d", &x);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL)
    {
        temp->prev = NULL;
        front = rear = temp;
    }
    else
    {
        temp->prev = rear;
        rear->next = temp;
        rear = temp;
    }
    printf("Item injected successfully!\n");
}

void deject()
{
    int x;
    struct node *temp;
    if (front == NULL)
    {
        printf("List is empty nothing to deject !!\n");
        return;
    }
    x = rear->data;
    temp = rear;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        rear->prev->next = NULL;
        rear = rear->prev;
    }
    free(temp);
    printf("%d is the dejected item.\n", x);
}

void display()
{
    struct node *temp;
    temp = front;
    if (front == NULL)
    {
        printf("List is empty..\n");
        return;
    }
    else
    {
        printf("Items in the list: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    int ch;
    front = rear = NULL; // Initialize front and rear pointers
    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Inject\n4. Deject\n5. Display\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            dpush(); // Loop to handle push operation
            break;
        case 2:
            dpop(); // Loop to handle pop operation
            break;
        case 3:
            dinject(); // Loop to handle inject operation
            break;
        case 4:
            deject(); // Loop to handle deject operation
            break;
        case 5:
            display(); // Loop to handle display operation
            break;
        case 6:
            printf("Exiting program.\n\n");
            exit(0); // Loop to handle exit operation
            break;
        default:
            printf("Invalid choice. Please try again.\n\n");
        }
    }
    return 0;
}