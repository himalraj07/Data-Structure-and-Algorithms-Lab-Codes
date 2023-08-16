/*
	To Become familiar with circular linked list operations ( PUSH Operation, POP Operation and Traversal Operation ).
	Write a progtam to insert at beginning and insert at last,delete at beginning and delete at last and display the stack using circular linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
} *root;

void insertAtBeginning()
{
	int x;
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter data to insert at the beginning: ");
	scanf("%d", &x);
	temp->data = x;
	temp->next = root;
	root = temp;
	printf("Data inserted at the beginning successfully.\n");
}

void insertAtLast()
{
	int x;
	struct node *temp1, *temp2;
	temp1 = (struct node *)malloc(sizeof(struct node));
	printf("Enter data to insert at the last: ");
	scanf("%d", &x);
	temp1->data = x;
	temp1->next = NULL;
	if (root == NULL)
	{
		root = temp1;
	}
	else
	{
		temp2 = root;
		while (temp2->next != NULL)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp1;
	}
	printf("Data inserted at the last successfully.\n");
}

void display()
{
	struct node *temp;
	temp = root;
	if (root == NULL)
	{
		printf("Stack is empty.\n");
		return;
	}
	else
	{
		printf("Stack contents: ");
		while (temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
    printf("\n");
}

void deleteAtBeginning()
{
	struct node *temp;
	if (root == NULL)
	{
		printf("Stack is empty. Nothing to delete.\n");
		return;
	}
	else
	{
		temp = root;
		root = root->next;
		free(temp);
		printf("Data deleted from the beginning successfully.\n");
	}
}

void deleteAtLast()
{
	struct node *temp, *prev;
	if (root == NULL)
	{
		printf("Stack is empty. Nothing to delete.\n");
		return;
	}
	else
	{
		temp = root;
		prev = NULL;
		while (temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		if (prev != NULL)
			prev->next = NULL;
		else
			root = NULL;
		free(temp);
		printf("Data deleted from the last successfully.\n");
	}
}

int main()
{
	int ch;
	root = NULL;

	while (1)
	{
		printf("\nMenu:\n");
		printf("1. Insert at the Beginning\n");
		printf("2. Insert at the Last\n");
		printf("3. Display Stack\n");
		printf("4. Delete from the Beginning\n");
		printf("5. Delete from the Last\n");
		printf("6. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			insertAtBeginning();
			break;
		case 2:
			insertAtLast();
			break;
		case 3:
			display();
			break;
		case 4:
			deleteAtBeginning();
			break;
		case 5:
			deleteAtLast();
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("Invalid choice. Please try again.\n");
		}
	}
	return 0;
}