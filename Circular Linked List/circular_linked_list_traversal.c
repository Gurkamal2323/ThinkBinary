#include<stdio.h>
#include<Stdlib.h>

//linked list structure
struct linked_list
{
	int data;
	struct linked_list *next;
};

//rename
typedef struct linked_list listNode;

void push(listNode **headRef, int data)
{
	listNode *ptr1 = (listNode *)malloc(sizeof(listNode));
	listNode *newNode = (*headRef);
	ptr1->data = data;
	ptr1->next = (*headRef);
	//if head is not NULL
	if((*headRef)!=NULL)
	{
		while(newNode->next!=(*headRef))
		{
			newNode = newNode->next;
		}
		newNode->next = ptr1;
	}
	else
		ptr1->next = ptr1;//for the first node
		
	(*headRef) = ptr1;
}

//print list
void printList(listNode *head)
{
	listNode *newNode = head;
	if(head!=NULL)
	{
		//traverse the list
		do
		{
			printf("%d ",newNode->data);
			newNode = newNode->next;
		}while(newNode!=head);
	}
}

int main()
{
	listNode *head = NULL;
	push(&head,12);
	push(&head,56);
	push(&head,2);
	push(&head,11);
	printf("Circular linked list\n");
	printList(head);
	return 0;
}
