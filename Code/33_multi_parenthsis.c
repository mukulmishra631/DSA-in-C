#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}


void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
        printf("Stack overflow");
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow");
        return -1;
    }
        
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// char stackTop(struct stack* sp){
//     return sp->arr[sp->top];
// }
int match(char a, char b){
    if(a=='{' && b=='}') return 1;
    if(a=='(' && b==')') return 1;
    if(a=='[' && b==']') return 1;
    return 0;
}
int multiParenthesis(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack)) ;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(sp, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp)) return 0;// stack underflow
            popped_ch = pop(sp);
            if(!match(popped_ch, exp[i])) return 0; //this will stop further checking because the stack top element and the popped character did not matched
        }
    }
    if(isEmpty(sp)) return 1;
    else return 0;
}
int main()
{
    // char * exp = "((8)-{87-9})";
    // char * exp = "[4-6]((8){(9-8)})";
    char * exp = "((8){(9-8)})";
    // char *exp = "({[({[()]})]({[({[()]})]})})((({[()]})[{((({[()]})[{()}])})]))))((({[()]})[{()}])";

    
    if (multiParenthesis(exp))
        printf("Parenthesis matched successfully !The given expression is balanced.");
    else
        printf("Parenthesis not matched ! The expression is unbalanced.");
        return 0;
}