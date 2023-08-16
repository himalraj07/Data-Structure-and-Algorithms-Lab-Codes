/*
    To Become familiar with circular queue operations ( PUSH Operation, POP Operation and Traversal Operation ).
*/

#include <stdio.h>

#define MAX 5
int cqueue_arr[MAX];
int front = -1;
int rear = -1;

int isQueueEmpty()
{
    return (front == -1);
}

int isQueueFull()
{
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

void insert(int item)
{
    if (isQueueFull())
    {
        printf("Queue Overflow.\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == MAX - 1)
            rear = 0;
        else
            rear = rear + 1;
    }

    cqueue_arr[rear] = item;
    printf("Element %d inserted successfully.\n", item);
}

void deletion()
{
    if (isQueueEmpty())
    {
        printf("Queue Underflow.\n");
        return;
    }

    printf("Element deleted from the queue is: %d.\n", cqueue_arr[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;
    }
}

void display()
{
    if (isQueueEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    do
    {
        printf("%d ", cqueue_arr[i]);
        if (i == rear)
            break;
        if (i == MAX - 1)
            i = 0;
        else
            i++;
    } while (i != front);
    printf("\n");
}

int main()
{
    printf("\nCircular Queue Operations:\n");
    int choice, item;
    do
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element for insertion in the queue: ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Quitting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}