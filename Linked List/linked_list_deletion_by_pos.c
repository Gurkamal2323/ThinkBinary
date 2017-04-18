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

//insert at the begining
void push(listNode **headRef, int data)
{
	listNode* newNode = (listNode *)malloc(sizeof(listNode));
	newNode->data = data;
	newNode->next = (*headRef);
	(*headRef) = newNode;
}

//delete node by position
void deleteNode(listNode **headRef, int pos)
{
	int i;
	//if list is empty
	if((*headRef)==NULL)
		return;
	//store head
	listNode* temp = (*headRef);
	//if node to be deleted is head, i.e node at pos 0
	if(pos==0)
	{
		(*headRef) = temp->next;
		free(temp);
		return;
	}
	//find the prev node of th node to be deleted
	for(i=0;temp!=NULL && i<=pos-1;i++)
		temp = temp->next;
	//if pos is mode than the number of nodes in the list
	if(temp==NULL || temp->next==NULL)
		return;
	//temp->next is the node to be deleted
	//store the next pointer of the node to be deleted
	listNode *next = temp->next->next;
	
	//delete node
	free(temp->next);
	
	//update pointer
	temp->next = next;
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
	push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);
    printf("Linked list\n");
    printList(head);
    deleteNode(&head,3);
    printf("\nLinked list after deletion of node at position 4\n");
    printList(head);
	return 0;
}
