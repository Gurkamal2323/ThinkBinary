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

void swapNodes(listNode **headRef, int x, int y)
{
	//when x and y are equal, then do nothing
	if(x==y)
		return;
	//search for x
	listNode *prevX = NULL, *currX = (*headRef);
	while(currX!=NULL && currX->data!=x)
	{
		prevX = currX;
		currX = currX->next;
	}
	//search for y
	listNode *prevY = NULL, *currY = (*headRef);
	while(currY!=NULL && currY->data!=y)
	{
		prevY = currY;
		currY = currY->next;
	}
	//when x or y are not present in the list
	if(currX==NULL || currY==NULL)
		return;
	//when x is not the head
	if(prevX!=NULL)
		prevX->next = currY;
	else//update head
		(*headRef) = currY;
		
	//when y is not the head
	if(prevY!=NULL)
		prevY->next = currX;
	else//update head
		(*headRef) = currX;
		
	//swap next pointers
	listNode *temp;
	temp = currX->next;
	currX->next = currY->next;
	currY->next = temp;
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
	listNode *start = NULL;
	push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
    printf("Linked list\n");
	printList(start);
	
	swapNodes(&start,4,3);
	
	printf("\nList after swapping 4 and 3\n");
	printList(start);
	
	return 0;
}
