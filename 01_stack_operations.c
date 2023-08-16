/*
    To Become familiar with stack operations ( PUSH Operation, POP Operation and Traversal Operation ).
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = 0;

void push(int value);
int pop();
void traverse();
int is_empty();
int top_element();

int main()
{
    int element, choice;

    printf("\nStack Operations :\n");
    while (1)
    {
        printf("1. Insert into stack (Push operation)\n");
        printf("2. Delete from stack (Pop operation)\n");
        printf("3. Print top element of stack\n");
        printf("4. Check if stack is empty\n");
        printf("5. Traverse stack\n");
        printf("6. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (top == MAX_SIZE)
            {
                printf("Error: Stack Overflow.\n\n");
            }
            else
            {
                printf("Enter the value to insert : ");
                scanf("%d", &element);
                push(element);
                printf("%d is pushed successfully !", element);
                printf("\n\n");
            }
            break;
        case 2:
            if (top == 0)
            {
                printf("Error: Stack Underflow.\n\n");
            }
            else
            {
                element = pop();
                printf("Element removed from stack is %d.\n\n", element);
            }
            break;
        case 3:
            if (!is_empty())
            {
                element = top_element();
                printf("Element at the top of stack is %d.\n\n", element);
            }
            else
            {
                printf("Stack is empty.\n\n");
            }
            break;
        case 4:
            if (is_empty())
            {
                printf("Stack is empty.\n\n");
            }
            else
            {
                printf("Stack is not empty.\n\n");
            }
            break;
        case 5:
            traverse();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n\n");
        }
    }
}

void push(int value)
{
    stack[top] = value;
    top++;
}

int pop()
{
    top--;
    return stack[top];
}

void traverse()
{
    if (top == 0)
    {
        printf("Stack is empty.\n\n");
        return;
    }

    printf("Stack elements : ");
    for (int d = top - 1; d >= 0; d--)
    {
        printf("%d ", stack[d]);
    }
    printf("\n\n");
}

int is_empty()
{
    return top == 0;
}

int top_element()
{
    return stack[top - 1];
}
