#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 100

// stack structure
struct Stack
{
	int top;
	int items[STACKSIZE];
};

void push(struct Stack *s, int x)
{
	int top;
	if(s->top == (STACKSIZE-1)){
		printf("Error: stack overflow\n");
		return;
	}
	else{
		s->top = s->top +1;
		s->items[s->top] = x;
	}
}

int isEmpty(struct Stack *s)
{
	if(s == NULL)
		return;
	
	if(s->top == -1)
		return 1;
	else
		return 0;
}

int pop(struct Stack *s)
{
	int temp;
	if(s == NULL)
		return;
	
	if(s->top == -1)
	{
		return;
	}
	else
	{
		temp = s->items[s->top];
		s->top-- ;
		return temp;
	}
}

/* prints element and NGE pair for all elements of
a[] of size n */
void printNGE(int a[], int n)
{
	int i = 0;
	struct Stack s;
	s.top = -1;
    	int element, next;
	printf("%d", a[0]);
	/* push first element to stack */
	push(&s, a[0]);
    
	/* iterate for rest of the elements */
	for(i=1; i<n; i++)
	{
		next = a[i];
	}
	
    for (i=1; i<n; i++)
    {
        next = a[i];
 
        if (!isEmpty(&s))
        {
            // if stack is not empty, then pop an element from stack
        	element = pop(&s);
		printf("%d", element);
            /* If the popped element is smaller than next, then
                a) print the pair
                b) keep popping while elements are smaller and
                stack is not empty */
            while (element < next)
            {
                printf("\n %d --> %d \n", element, next);
                if(isEmpty(&s))
                   break;
                element = pop(&s);
            }
 
            /* If element is greater than next, then push
               the element back */
            if (element > next)
                push(&s, element);
        }
 
        /* push next to stack so that we can find
           next greater for it */
        push(&s, next);
    }
 
    /* After iterating over the loop, the remaining
       elements in stack do not have the next greater
       element, so print -1 for them */
    while (!isEmpty(&s))
    {
        element = pop(&s);
        next = -1;
        printf("\n %d -- %d", element, next);
    }
}
 
/* Driver program to test above functions */
int main()
{
    int a[]= {7, 2, 11, 23,15};
    int n = sizeof(a)/sizeof(a[0]);
    printNGE(a, n);
    getchar();
    return 0;
}
