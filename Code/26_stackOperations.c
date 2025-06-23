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
        return -1; // Assuming that -1 will not be an element in the stack (this element will not be inserted in the stack because it will cause the rules to break because -1 is an integer and we cannot return -1 while it is in the stack so -1 is assumed to be not present in the stack by default otherwise it will cause error)
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
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
    push(sp, 12); // ---> Pushed 8 elements
    push(sp, 15); // This is the 9th element so will cause stack overflow since the size of the stack is 8

    printf("After pushing, Full : %d\n", isFull(sp));
    printf("After pushing, Empty : %d\n", isEmpty(sp));

    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    
    return 0;
}