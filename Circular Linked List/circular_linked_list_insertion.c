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

//insert in an empty list
listNode *addToEmpty(listNode *last, int data)
{
	//if list is not empty
	if(last!=NULL)
		return last;
	//create new node
	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	//insert the data
	newNode->data = data;
	//set pointers
	last = newNode;
	last->next = last;
	return newNode;
}

//insert at the begining of the list
listNode *addBegin(listNode *last, int data)
{
	if(last==NULL)
		addToEmpty(last,data);
	
	//create new node
	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	//insert data
	newNode->data = data;
	//set pointers
	newNode->next = last->next;
	last->next = newNode;
	
	return last;
}

//insert at the end of the list
listNode *addEnd(listNode *last, int data)
{
	if(last==NULL)
		addToEmpty(last,data);
	//create new node
	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	//insert data
	newNode->data = data;
	//set pointers
	newNode->next = last->next;
	last->next = newNode;
	last = newNode;
	
	return last;
}

//insert in between the list
listNode *addAfter(listNode *last, int data, int item)
{
	if(last==NULL)
		return NULL;
	listNode *newNode;
	listNode *prev_node = last->next;
	do
	{
		if(prev_node->data==item)
		{
			//create new node
			newNode = (listNode *)malloc(sizeof(listNode));
			//insert data
			newNode->data = data;
			//set pointers
			newNode->next = prev_node->next;
			prev_node->next = newNode;
			if(prev_node==last)
				last = newNode;
				
			return last;
		}
		prev_node = prev_node->next;
	}while(prev_node!=last->next);
	
	printf("%d not present",item);
	return last;
}

//traverse using last pointer
void traverse(listNode *last)
{
	listNode *newNode;
	//if list is empty
	if(last==NULL)
	{
		printf("List is empty");
		return;
	}
	//point to first node
	newNode = last->next;
	//traverse the list
	do
	{
		printf("%d ",newNode->data);
		newNode = newNode->next;
	}while(newNode!=last->next);
}

int main()
{
	listNode *last = NULL;
	last = addToEmpty(last,6);
	last = addBegin(last,4);
	last = addBegin(last,2);
	last = addEnd(last,8);
	last = addEnd(last,12);
	last = addAfter(last,10,8);
	
	traverse(last);
	return 0;
}
