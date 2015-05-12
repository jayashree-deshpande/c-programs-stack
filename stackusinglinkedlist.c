#include<stdio.h>
#include<stdlib.h>

struct StackNode{
	int data;
	struct StackNode* next;
}*top,*top1,*temp;

struct StackNode* newNode(int data)
{
	struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

int topelement();
void push(int data);
void pop();
void empty();
void display();
void freeTheStack();
void stack_count();
void create();

int count = 0;

void main()
{
    int no, ch, e;
 
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Top");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Display");
    printf("\n 7 - Stack Count");
    printf("\n 8 - Free stack");
 
    create();
 
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (top == NULL)
                printf("No elements in stack");
            else
            {
                e = topelement();
                printf("\n Top element : %d", e);
            }
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            stack_count();
            break;
        case 8:
            freeTheStack();
            break;
        default :
            printf(" Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}


/* Create empty stack */
void create()
{
    top = NULL;
}
 
/* Count stack elements */
void stack_count()
{
    printf("\n No. of elements in stack : %d", count);
}

/* Push data into stack */
void push(int data)
{
	if(top == NULL)
	{
		top = (struct StackNode*)malloc(sizeof(struct StackNode));
		top->data = data;
		top->next = NULL;
	}
	else
	{
		temp = (struct StackNode*)malloc(sizeof(struct StackNode));
		temp->next = top;
		temp->data = data;
		top = temp;
	}
	 count++;
}

/* Display stack elements */
void display()
{
	top1 = top;
	if(top1 == NULL)
	{
		printf("Stack is empty");
        return;
	}
	else
	{
		while(top != NULL)
		{
			printf("%d", top->data);
			top = top->next;
		}
	}
}

/* Pop Operation on stack */
void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else
	{
		top1 = top1->next;
		printf("\n Popped value : %d", top->data);
		free(top);
		top = top1;
		count--;
	}
}

/* Return top element */
int topelement()
{
    return(top->data);
}

/* Check if stack is empty or not */
void empty()
{
    if (top == NULL)
        printf("\n Stack is empty");
    else
        printf("\n Stack is not empty with %d elements", count);
}

/* free entire stack */
void freeTheStack()
{
    top1 = top;
 
    while (top1 != NULL)
    {
        top1 = top->next;
        free(top);
        top = top1;
        top1 = top1->next;
    }
    free(top1);
    top = NULL;
 
    printf("\n All stack elements destroyed");
    count = 0;
}
