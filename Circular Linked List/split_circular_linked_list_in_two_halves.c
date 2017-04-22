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

//split circular linked list
void splitList(listNode *head, listNode **headRef1, listNode **headRef2)
{
	//using tortoise and hare algo to get the middle and last nodes
	listNode *slow_ptr = head;
	listNode *fast_ptr = head;
	
	if(head==NULL)
		return;
	//for odd elements fast_ptr->next becomes head
	//for even elements fast_ptr->next->net becomes head	
	while(fast_ptr->next!=head && fast_ptr->next->next!=head)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}
	//if there are even elements in the list then move the fast pointer
	if(fast_ptr->next->next==head)
		fast_ptr = fast_ptr->next;
		
	//set the head pointer for the first half
	(*headRef1) = head;
	//set the head pointer for the seconf half
	if(head->next!=head)
		(*headRef2) = slow_ptr->next;
	//make second half circular
	fast_ptr->next = slow_ptr->next;
	//make first half circular
	slow_ptr->next = head;
}

//insert at the begining
void push(listNode **headRef, int data)
{
	listNode *ptr1 = (listNode *)malloc(sizeof(listNode));
	listNode *newNode = (*headRef);
	
	ptr1->data = data;
	ptr1->next = (*headRef);
	
	if((*headRef)!=NULL)
	{
		while(newNode->next!=(*headRef))
		{
			newNode = newNode->next;
		}
		newNode->next = ptr1;
	}
	else
		ptr1->next = ptr1; //for the first node
	
	(*headRef) = ptr1;
}

//print list
void printList(listNode *head)
{
	listNode *newNode = head;
	if(head!=NULL)
	{
		do//traverse the linked list
		{
			printf("%d ",newNode->data);
			newNode = newNode->next;
		}while(newNode!=head);
	}
}

int main()
{
	listNode *head = NULL;
	listNode *head1 = NULL;
	listNode *head2 = NULL;
	
	push(&head, 12); 
    push(&head, 56);   
    push(&head, 2);   
    push(&head, 11);
	
	 printf("original circular linked list\n");
	 printList(head);
	 
	 splitList(head,&head1,&head2);
	 
	 printf("\nfirst circular linked list\n");
	 printList(head1);
	 
	 printf("\nsecond circular linked list\n");
	 printList(head2);
	return 0;
}
