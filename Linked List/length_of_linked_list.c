#include<stdio.h>
#include<stdlib.h>

//linked list structure
struct linked_list
{
	int data;
	struct linked_list *next;
};

//rename
typedef struct linked_list listNode;

//insert at the begining
void push(listNode **headRef, int data)
{
	listNode* newNode = (listNode *)malloc(sizeof(listNode));
	newNode->data = data;
	newNode->next = (*headRef);
	(*headRef) = newNode;
}

int getCount(listNode *head)
{
	listNode *temp = head;
	int count = 0;
	while(temp!=NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

int main()
{
	listNode *head = NULL;
	push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    printf("Length of list is %d\n",getCount(head));
	return 0;
}
