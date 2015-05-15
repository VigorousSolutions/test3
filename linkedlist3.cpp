// linkedlist3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

/* Link list node */
struct node
{
	int data;
	struct node* next;
};

/* Function to get the middle of the linked list*/

void push(struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node =
		(struct node*) malloc(sizeof(struct node));

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}
// A utility function to print a given linked list
void printList(struct node *ptr)
{
	while (ptr != NULL)
	{
		printf("%d->", ptr->data);

		ptr = ptr->next;
	}
	printf("NULL\n");
}
void printMiddleOfList(struct node *head)
{
	struct node *slow_ptr = head;

	struct node *fast_ptr = head;

	if (head != NULL)
	{
		int l = 0;
		while (fast_ptr != NULL && fast_ptr->next != NULL)
		{
			l++;
			printf("L is  [%d]\n\n", l);
			fast_ptr = fast_ptr->next->next;
			slow_ptr = slow_ptr->next;
		}
		printf("The middle element is [%d]\n\n", slow_ptr->data);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	struct node* head = NULL;
	int i;
	int string1;

	for (i = 250; i>0; i--)
	{
		push(&head, i);
		printList(head);
		printMiddleOfList(head);
	}
	cin >> string1;

	return 0;
}

