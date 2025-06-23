#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

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
        printf("Stack overflow ! cannot push '%c'\n", val);
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
        printf("Stack underflow , cannot pop !\n");
        return -1; // assuming that -1 will not be in the stack as an element
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top --;
        return val;
    }
}

int precedence(char ch){
    if(ch == '*' ||  ch=='/') return 3;
    else if(ch=='+' || ch=='-') return 2;
    else return 0;
}

 int isOperator(char ch){
 if(ch =='+' || ch=='-' || ch =='/' || ch=='*') return 1;
 else return 0;
}

char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // track infix traversal
    int j = 0; // track postfix append
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    // char *infix = "a-b+t/z";
    char *infix = "a/m*j-b-c";
    
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}

/*
Note : This program does not prove the validity of a expression, this just tells if the parentheses are mathched or not.
eg. 3*(5---$$%%)-(87/9)   this is balanced according to this program, because the parenthesis is matched, but we can clearly see that the expression is not valid
*/