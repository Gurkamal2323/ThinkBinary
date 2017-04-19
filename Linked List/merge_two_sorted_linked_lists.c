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

listNode *sortedMerge(listNode *a, listNode *b)
{
	listNode *result = NULL;
	//base cases
	if(a==NULL)
		return(b);
	else if(b==NULL)
		return(a);
	
	//pick either a or b and recur
	if(a->data <= b->data)
	{
		result = a;
		result->next = sortedMerge(a->next,b);
	}
	else
	{
		result = b;
		result->next = sortedMerge(a,b->next);
	}
	
	return result;
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
	listNode *a = NULL;
	listNode *b = NULL;
	//list 1
	push(&a,1);
	push(&a,2);
	push(&a,3);
	push(&a,4);
	//list 2
	push(&b,5);
	push(&b,6);
	push(&b,7);
	
	printf("list 1\n");
	printList(a);
	printf("\nlist 2\n");
	printList(b);
	
	listNode *result = sortedMerge(a,b);
	printf("\nMerged list\n");
	printList(result);
	return 0;
}
