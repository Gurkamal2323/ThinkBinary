#include<stdio.h>
#include<stdlib.h>

//linked list structure
struct linked_list
{
	int data;//data
	struct linkd_list *next;//next pointer
};

typedef struct linked_list listNode;

//insert node at the begining
void push(listNode **headRef, int new_data)
{
	//1.create new node
	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	//2. insert data in newNode
	newNode->data =new_data;
	//3. point newNode->next to head
	newNode->next = (*headRef);
	//4. update head to point to newNode
	(*headRef) = newNode;
}

void insertAfter(listNode *prev_node, int new_data)
{
	//1. check whether prev_node is NULL
	if(prev_node==NULL)
	{
		printf("Previous node is NULL\n");
		return;
	}
	//2. create new node
	listNode* newNode = (listNode *)malloc(sizeof(listNode));
	//3. insert data in newNode
	newNode->data = new_data;
	//4.point newNode->next to prev_node->next
	newNode->next = prev_node->next;
	//5. point prev_node->next to newNode
	prev_node->next = newNode;
}

void append(listNode **headRef,int new_data)
{
	//1. create new node
	listNode* newNode = (listNode *)malloc(sizeof(listNode));
	
	listNode* lastNode = (*headRef); //head is stored so that original head does not change
	
	//2. insert data in newNode
	newNode->data = new_data;
	//3. point newNode->next to NULL
	newNode->next = NULL;
	//4. check if list is empty, if so make the newNode as the head
	if((*headRef)==NULL)
	{
		(*headRef) = newNode;
		return;
	}
	//5. traverse to the last node
	while(lastNode->next!=NULL)
	{
		lastNode = lastNode->next;
	}
	//6. point lastNode->next to newNode
	lastNode->next = newNode;
	
	return;
}

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
	append(&head,6);
	push(&head,7);
	push(&head,1);
	append(&head,4);
	insertAfter(head->next,8);
	printf("Linked list is \n");
	printList(head);
	return 0;
}
