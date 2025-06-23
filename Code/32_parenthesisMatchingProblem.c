#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1; // stack is empty
    else
        return 0; // stack is not empty
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1; // stack is full
    else
        return 0; // stack is not full
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
        printf("Stack overflow ! cannot push %d", val);
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        // printf("Pushed %d into the stack\n", val);
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow , cannot pop !");
        return -1; // assuming that -1 will not be in the stack as an element
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top --;
        return val;
    }
}

//Function for checking parenthesis match problem
int parenthesisMatch(char *exp)
{
    struct stack *sp;
    sp->top = -1;
    sp->size = 100;
    sp->arr=(char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0; // stack underflow
            }
            pop(sp);
        }
    }
    // if (isEmpty(sp))
    //     return 1; // balanced
    // else
    //     return 0; // unbalanced
}

int main()
{
    char *exp = "3*8(8-9))";
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    } else printf("The parenthesis is not matching");
    return 0;
}


/*
Note : This program does not prove the validity of a expression, this just tells if the parentheses are mathched or not. 
eg. 3*(5---$$%%)-(87/9)   this is balanced according to this program, because the parenthesis is matched, but we can clearly see that the expression is not valid 
*/