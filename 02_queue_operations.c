/*
    To Become familiar with queue operations ( PUSH Operation, POP Operation and Traversal Operation ).
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
} *front, *rear, *temp, *front1;

int frontelement();
void enq(int data);
void deq();
void empty();
void display();
void create();
void queuesize();

int count = 0;

int main()
{
    int no, ch, e;

    printf("\n1 - Enqueue");
    printf("\n2 - Dequeue");
    printf("\n3 - Front element");
    printf("\n4 - Find queue is empty or not");
    printf("\n5 - Exit");
    printf("\n6 - Display queue elements");
    printf("\n7 - Queue size\n");
    create();
    while (1)
    {
        printf("\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            enq(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("Front element : %d\n", e);
            else
                printf("No front element in Queue as queue is empty.\n");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            queuesize();
            break;
        default:
            printf("Wrong choice, Please enter correct choice.\n");
            break;
        }
    }

    return 0;
}

/* Create an empty queue */
void create()
{
    front = rear = NULL;
}

/* Returns queue size */
void queuesize()
{
    printf("Queue size : %d\n", count);
}

/* Enqueueing the queue */
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;

        rear = temp;
    }
    count++;
}

/* Displaying the queue elements */
void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (front1 != NULL)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    printf("\n");
}

/* Dequeueing the queue */
void deq()
{
    front1 = front;

    if (front1 == NULL)
    {
        printf("Error: Trying to dequeue elements from an empty queue.\n");
        return;
    }
    else if (front1->ptr != NULL)
    {
        front1 = front1->ptr;
        printf("Dequeued value : %d\n", front->info);
        free(front);
        front = front1;
    }
    else
    {
        printf("\nDequeued value : %d\n", front->info);
        free(front);
        front = NULL;
        rear = NULL;
    }
    count--;
}

/* Returns the front element of the queue */
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return front->info;
    else
        return 0;
}

/* Display if the queue is empty or not */
void empty()
{
    if ((front == NULL) && (rear == NULL))
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");
}