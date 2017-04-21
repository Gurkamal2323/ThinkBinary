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

//create new node
void push(listNode **headRef, int data)
{
	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	newNode->data = data;
	newNode->next = (*headRef);
	(*headRef) = newNode;
}

//detect loop
int detectLoop(listNode *head)
{
	listNode *slow_ptr = head;
	listNode *fast_ptr = head;
	while(slow_ptr && fast_ptr && fast_ptr->next)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if(slow_ptr==fast_ptr)
		{
			printf("Loop Detected");
			return 1;
		}
	}
	return 0;
}

//print list
printList(listNode *head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head = head->next;
	}
}

int main()
{
	listNode *head = NULL;
	push(&head,20);
	push(&head,4);
	push(&head,15);
	push(&head,10);
	printf("Linked list\n");
	printList(head);
	//create loop for testing
	head->next->next->next->next = head;
	detectLoop(head);
	return 0;
}
