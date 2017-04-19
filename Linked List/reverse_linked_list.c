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

//reverse list
void reverse(listNode **headRef)
{
	if(!headRef)
		return;
	reverseUtil(NULL,*headRef,headRef);
}

void reverseUtil(listNode* prev, listNode* curr, listNode **headRef)
{
	//if last node, the update head
	if(!curr->next)
	{
		//update head
		(*headRef) = curr;
		//update curr->next to prev;
		curr->next = prev;
		return;
	}
	//store curr->next for recursive calls
	listNode *next = curr->next;
	
	//update curr->next to prev;
	curr->next = prev;
	
	reverseUtil(curr,next,headRef);
}

//print list
void printList(listNode *head)
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
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,7);
	push(&head,8);
	printf("Linked lis\n");
	printList(head);
	reverse(&head);
	printf("\nRversed linked list\n");
	printList(head);
	return 0;
}
