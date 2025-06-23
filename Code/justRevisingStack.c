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
        return 1; // true - this denotes the condition is true and the stack is empty thus elements can not be poped from the structure.
    }
    else
    {
        return 0; // false this denotes the condition is false and the stack is not empty thus elements can be poped now from the stack
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1; // true
    }
    else
    {
        return 0; // false
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack overflow ! Cannot push %d to the stack\n", val);
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
        printf("Stack is empty ! Cannot pop any element from the stack\n");
        return -1; // We are assuming that -1 will not be an element of the stack
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
        printf("Cannot peek, please provide a valid position !\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
    }
}

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}
int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 5;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully !\n");
    printf("Before pushing, Full : %d\n", isFull(sp));
    printf("Before pushing, Empty : %d\n", isEmpty(sp));
    push(sp, 56);
    push(sp, 57);
    push(sp, 58);
    push(sp, 59);
    push(sp, 60); // -->pushed 5 elements
    push(sp, 61); // --->this will cause stack overflow
    printf("After pushing, Full : %d\n", isFull(sp));
    printf("After pushing, Empty : %d\n", isEmpty(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));

    for (int j = 1; j <= sp->top+1; j++)
    {
        printf("The value at position %d is %d : \n", j, peek(sp, j));
    }

    printf("The topmost value of the stack is %d \n", stackTop(sp));
    printf("The bottom most value of the stack is %d \n", stackBottom(sp));
    return 0;
}