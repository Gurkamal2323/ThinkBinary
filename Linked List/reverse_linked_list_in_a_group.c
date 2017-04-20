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

//reverse list in a group
listNode *reverseList(listNode *head, int k)
{
	listNode *prev = NULL;
	listNode *curr = head;
	listNode *next = NULL;
	int count = 0;
	while(curr!=NULL & count<k)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	//now next point to the (k+1)th node
	if(next!=NULL)
	{
		head->next = reverseList(next,k);
	}
	//prev becomes head of the list
	return prev;
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
	 push(&head, 9);
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);
     printf("Linked list\n");
     printList(head);
     head = reverseList(head,3);
     printf("\nReverse list upto 3\n");
     printList(head);
	return 0;
}
