/*
    To Become familiar with Stack operations using Linked List.
*/

#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node
{
    int val;
    struct node *next;
};

struct node *head = NULL; // Initialize the head to NULL

int main()
{
    int choice = 0;
    printf("\n***\tStack operations using linked list\t***\n");
    printf("---------------------------------------------------\n");
    printf("\nChoose one from the below options...\n");
    while (choice != 4)
    {
        printf("\n1. Push\n2. Pop\n3. Show\n4. Exit\n");
        printf("\nEnter your choice : ");
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
            display();
            break;
        case 4:
            printf("Exiting ...\n\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n\n");
        };
    }

    // Free the memory used by the linked list before exiting
    struct node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

void push()
{
    int val;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Not able to push the element. Memory overflow.\n");
    }
    else
    {
        printf("Enter the value to push: ");
        scanf("%d", &val);
        ptr->val = val;
        ptr->next = head;
        head = ptr;
        printf("Item %d pushed successfully.\n", val);
    }
}

void pop()
{
    if (head == NULL)
    {
        printf("Stack is empty. Can not pop.\n");
    }
    else
    {
        struct node *ptr = head;
        int item = ptr->val;
        head = head->next;
        free(ptr);
        printf("Item %d popped successfully.\n", item);
    }
}

void display()
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("Stack is empty.");
    }
    else
    {
        printf("Stack elements are : ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->val);
            ptr = ptr->next;
        }
    }
    printf("\n");
}