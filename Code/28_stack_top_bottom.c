#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1; // Stack is empty
    }
    else
        return 0; // Stack is not empty
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1; // Stack is full
    }
    else
        return 0; // Stack is not full
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow! Cannot pop %d from the stack\n");
        return -1; // Assuming that -1 will not be an element in the stack
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *sp, int i)
{
    int arrayInd = sp->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
    }
}

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp)
{
    return sp->arr[0];
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 8;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
    printf("Before pushing, Full : %d\n", isFull(sp));
    printf("Before pushing, Empty :  %d\n", isEmpty(sp));
    push(sp, 56);
    push(sp, 67);
    push(sp, 87);
    push(sp, 89);
    push(sp, 34);
    push(sp, 677);
    push(sp, 9);
    push(sp, 12); // ---> Pushed 8 elements (LIFO)
    push(sp, 15); // This is the 9th element so will cause stack overflow since the size of the stack is 8

    printf("After pushing, Full : %d\n", isFull(sp));
    printf("After pushing, Empty : %d\n", isEmpty(sp));

    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));

    // Printing values from the stack
    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }
    
    // Printing the top and bottom value of the stack 
    printf("The topmost value of this stack is %d\n", stackTop(sp));
    printf("The bottom most value of this stack is %d\n", stackBottom(sp));
    return 0;
}