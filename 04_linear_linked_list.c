/*
    To Become familiar with linear linked list operations ( PUSH Operation, POP Operation and Traversal Operation ).
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
int count = 0;

void insert_at_begin(int);
void insert_at_end(int);
void traverse();
void delete_from_begin();
void delete_from_end();

int main()
{
    int input, data;

    while (1)
    {
        printf("\n1. Insert an element at the beginning of the linked list.\n");
        printf("2. Insert an element at the end of the linked list.\n");
        printf("3. Traverse the linked list.\n");
        printf("4. Delete an element from the beginning.\n");
        printf("5. Delete an element from the end.\n");
        printf("6. Exit\n");
        printf("\nSelect an option: ");

        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("Enter the value of the element: ");
            scanf("%d", &data);
            insert_at_begin(data);
            break;
        case 2:
            printf("Enter the value of the element: ");
            scanf("%d", &data);
            insert_at_end(data);
            break;
        case 3:
            traverse();
            break;
        case 4:
            delete_from_begin();
            break;
        case 5:
            delete_from_end();
            break;
        case 6:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Please enter a valid input.\n");
            break;
        }
    }

    return 0;
}

void insert_at_begin(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    count++;

    if (t == NULL)
    {
        printf("Memory allocation failed. Unable to insert element.\n");
        return;
    }

    t->data = x;
    t->next = start;
    start = t;
    printf("%d inserted at the beginning successfully.\n", x);
}

void insert_at_end(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    count++;

    if (t == NULL)
    {
        printf("Memory allocation failed. Unable to insert element.\n");
        return;
    }

    t->data = x;
    t->next = NULL;

    if (start == NULL)
    {
        start = t;
    }
    else
    {
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = t;
    }

    printf("%d inserted at the end successfully.\n", x);
}

void traverse()
{
    struct node *t = start;

    if (t == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked list elements: ");
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\nTotal elements in linked list: %d\n", count);
}

void delete_from_begin()
{
    if (start == NULL)
    {
        printf("Linked list is already empty. Cannot delete from the beginning.\n");
        return;
    }

    int n = start->data;
    struct node *t = start->next;
    free(start);
    start = t;
    count--;

    printf("%d deleted from the beginning successfully.\n", n);
}

void delete_from_end()
{
    if (start == NULL)
    {
        printf("Linked list is already empty. Cannot delete from the end.\n");
        return;
    }

    count--;
    int n;
    if (start->next == NULL)
    {
        n = start->data;
        free(start);
        start = NULL;
    }
    else
    {
        struct node *t = start;
        struct node *u = NULL;
        while (t->next != NULL)
        {
            u = t;
            t = t->next;
        }
        n = t->data;
        u->next = NULL;
        free(t);
    }

    printf("%d deleted from the end successfully.\n", n);
}