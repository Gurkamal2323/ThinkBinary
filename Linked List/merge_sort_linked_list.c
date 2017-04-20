#include<stdio.h>
#include<Stdlib.h>

struct linked_list
{
	int data;
	struct linked_list *next;
};

typedef struct linked_list listNode;

void push(listNode **headRef, int data)
{
	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	newNode->data = data;
	newNode->next = (*headRef);
	(*headRef) = newNode;
}

listNode *mergeSorted(listNode *a, listNode *b)
{
	listNode *result = NULL;
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	
	if(a->data <= b->data)
	{
		result = a;
		result->next = mergeSorted(a->next,b);
	}
	else
	{
		result = b;
		result->next = mergeSorted(a,b->next);
	}
	
	return result;
}

int getLength(listNode *head)
{
	int count = 0;
	listNode *temp = head;
	while(temp!=NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

listNode *mergeSort(listNode *head)
{
	listNode *oldHead = head;
	int mid = getLength(head)/2;
	
	//if list has only one element
	if(head->next==NULL)
		return head;
	
	//move oldHead to mid
	while(mid-1>0)
	{
		oldHead = oldHead->next;
		mid--;
	}
	
	listNode *newHead = oldHead->next;
	oldHead->next = NULL;//breadk the list
	oldHead = head;
	
	//sort two parts
	listNode *n1 = mergeSort(oldHead);
	listNode *n2 = mergeSort(newHead);
	
	return mergeSorted(n1,n2);
}

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
	push(&head,9);
	push(&head,3);
	push(&head,4);
	push(&head,2);
	push(&head,5);
	push(&head,1);
	printf("Linked list \n");
	printList(head);
	listNode *result = mergeSort(head);
	printf("\nSorted list\n");
	printList(result);
	return 0;
}
