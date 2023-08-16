/*
    To Become Familiar With Hashing.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

int arr[SIZE];

void init()
{
    for (int i = 0; i < SIZE; i++)
        arr[i] = -1;
}

void insert(int value)
{
    int key = value % SIZE;

    if (arr[key] == -1)
    {
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value, key);
    }
    else
    {
        printf("Collision: Unable to insert %d at arr[%d] as it already contains %d.\n", value, key, arr[key]);
    }
}

void del(int value)
{
    int key = value % SIZE;
    if (arr[key] == value)
    {
        arr[key] = -1;
        printf("Deleted %d from arr[%d].\n", value, key);
    }
    else
    {
        printf("%d not found in the hash table.\n", value);
    }
}

void search(int value)
{
    int key = value % SIZE;
    if (arr[key] == value)
        printf("Search : %d found at arr[%d].\n", value, key);
    else
        printf("Search : %d not found in the hash table.\n", value);
}

void print()
{
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] != -1)
            printf("arr[%d] = %d\n", i, arr[i]);
        else
            printf("arr[%d] = Empty\n", i);
    }
}

int main()
{
    init();
    int choice, value;

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("\nEnter your choice : ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a valid option.\n");
            while (getchar() != '\n')
                ; // Clear the input buffer
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert : ");
            if (scanf("%d", &value) != 1)
            {
                printf("Invalid input. Please enter a valid value to insert.\n");
                while (getchar() != '\n')
                    ; // Clear the input buffer
                continue;
            }
            insert(value);
            break;
        case 2:
            printf("Enter the value to delete: ");
            if (scanf("%d", &value) != 1)
            {
                printf("Invalid input. Please enter a valid value to delete.\n");
                while (getchar() != '\n')
                    ; // Clear the input buffer
                continue;
            }
            del(value);
            break;
        case 3:
            printf("Enter the value to search: ");
            if (scanf("%d", &value) != 1)
            {
                printf("Invalid input. Please enter a valid value to search.\n");
                while (getchar() != '\n')
                    ; // Clear the input buffer
                continue;
            }
            search(value);
            break;
        case 4:
            print();
            break;
        case 5:
            printf("Exiting ...\n\n");
            exit(0);
        default:
            printf("Invalid choice. Please select a valid option.\n\n");
        }
    }

    return 0;
}