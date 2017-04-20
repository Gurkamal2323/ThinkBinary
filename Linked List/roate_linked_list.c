#include<Stdio.h>
#include<Stdlib.h>

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

//rotate linked list
void rotateList(listNode **headRef, int k)
{
	if(k==0)
		return;
	listNode *curr = (*headRef);
	int count = 1;
	while(curr!=NULL && count<k)
	{
		curr = curr->next;
		count++;
	}
	
	if(curr==NULL)
		return;
	
	//curr points to kth node, store it
	listNode *kthNode = curr;
	//traverse to the last of the linked list
	while(curr->next!=NULL)
	{
		curr = curr->next;
	}
	//curr points to the last node
	//update pointers
	//1. lastNode will point to head
	//2. head will be kthNode->next
	//3. kthNode->next will be NULL
	curr->next = (*headRef);
	(*headRef) = kthNode->next;
	kthNode->next = NULL;
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
	push(&head,60);
	push(&head,50);
	push(&head,40);
	push(&head,30);
	push(&head,20);
	push(&head,10);
	printf("Linked list\n");
	printList(head);
	rotateList(&head,4);
	printf("\nLinked list after rotation\n");
	printList(head);
	return 0;
}
