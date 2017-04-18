#include<stdio.h>
#include<stdlib.h>

//linked list structure
struct linked_list
{
	int data;
	struct linked_list* next;
};

//insert at the begining
typedef struct linked_list listNode;

void push(listNode **headRef, int data)
{
	listNode* newNode = (listNode *)malloc(sizeof(listNode));
	newNode->data = data;
	newNode->next = (*headRef);
	(*headRef) = newNode;
}

//delete node
void deleteNode(listNode **headRef, int data)
{
	//we need two nodes prev_node to keep track of previous node and temp node to be the node to be deleted
	listNode *prev_node;
	listNode* temp = (*headRef);
	//when head contains the key to be deleted
	if(temp!=NULL && (*headRef)->data==data)
	{
		(*headRef) = temp;
		free(temp);
		return;
	}
	//traverse the list to find the node to be deleted and also keep track of prev_node
	while(temp!=NULL && temp->data!=data)
	{
		prev_node = temp;
		temp = temp->next;
	}
	//update pointer of prev_node
	prev_node->next = temp->next;
	//free memory
	free(temp);
}

//print list
printList(listNode* head)
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
	push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    printf("Linked List\n");
    printList(head);
    deleteNode(&head,1);
    printf("\nLinked List after deletion of 1\n");
    printList(head);
	return 0;
}
