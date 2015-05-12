#include<stdlib.h>
#include<stdio.h>

// A structure to represent a stack
struct Stack{
	int top;
	unsigned capacity;
	int* array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity){
	struct Stack* myStack = (struct Stack*)malloc(sizeof(struct Stack));
	myStack->capacity = capacity;
	myStack->top = -1;
	myStack->array = (int*)malloc(myStack->capacity * sizeof(int));
	return myStack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* myStack){
	if((myStack->capacity - 1) == myStack->top)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* myStack){
	if(myStack->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

// Function to add an item to stack.  It increases top by 1
void push(struct Stack* myStack, int item)
{
	if(isFull(myStack))
	{
		return;
	}
	myStack->array[++myStack->top] = item;
	printf("%d pushed to stack\n", item);
}

int pop(struct Stack* myStack)
{
	if(isEmpty(myStack)){
		return;
	}
	return myStack->array[myStack->top--];
}

// Function to get top item from stack
int peek(struct Stack* myStack)
{
    if (isEmpty(myStack))
        return -1;
    return myStack->array[myStack->top];
}

// Driver program to test above functions
int main()
{
    struct Stack* stack = createStack(100);
 
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
 
    printf("%d popped from stack\n", pop(stack));
 
    printf("Top item is %d\n", peek(stack));
 
    return 0;
}

