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
        return 1; // true
    }
    else
    {
        return 0; // false
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
        printf("Stack is empty ! Cannot pop any element from the stack");
        return -1;
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
        printf("Cannot peek, please provide a valid position !");
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
    }
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
    // push(sp, 56);
    // push(sp, 57);
    // push(sp, 58);
    // push(sp, 59);
    // push(sp, 60); // -->pushed 5 elements
    // push(sp, 60); // --->this will cause stack overflow

    // code to get input from the user to fill elements in the stack
    printf("Enter the elements : ");
    for(int k = 0; k<=sp->size; k++){
        scanf("%d ", &val);
    }
    printf("After pushing, Full : %d\n", isFull(sp));
    printf("After pushing, Empty : %d\n", isEmpty(sp));
    return 0;
}