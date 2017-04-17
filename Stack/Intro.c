#include<stdio.h>
#define MAX 100

int size = MAX;
int stack[MAX];
int top = -1;

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if(top==size)
		return 1;
	else
		return 0;
}

int peek()//return current top element in stack
{
	return stack[top];
}

int push(int data)
{
	if(!isFull())
	{
		top = top + 1;
		stack[top] = data;
	}
	else
	{
		printf("\nOverflow\n");
		return 0;
	}
}

int pop()
{
	int data;//element popped to be returned
	if(!isEmpty())
	{
		data = stack[top];
		top = top - 1;
		return data;
	}
	else
	{
		printf("\nUnderflow\n");
		return 0;
	}
}

int main()
{
	// push items on to the stack 
	push(3);
	push(5);
	push(9);
	push(1);
	push(12);
	push(15);

	printf("Element at top of the stack: %d\n" ,peek());
	printf("Elements: \n");

   // print stack data 
	while(!isEmpty()) {
		int data = pop();
		printf("%d\n",data);
	}

	printf("Stack full: %s\n" , isFull()?"true":"false");
	printf("Stack empty: %s\n" , isEmpty()?"true":"false");
	return 0;
}
