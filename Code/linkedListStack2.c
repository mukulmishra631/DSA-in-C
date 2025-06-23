#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Function to print the elements in a linked list
void linkedListTraversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr=ptr->next;
    }
    
}

// function to check if the stack is empty or not
int isEmpty(struct Node* top){
    if(top==NULL){
        return 1;
    } else return 0; //else is not needed but we've written for beginners
}

// function to check if the stack is full or not
int isFull(struct Node* top){
 struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        return 1; // Dynamically memory not allocated i.e. stack is full
    } else return 0; // Memory allocated i.e. stack is not full
}

struct  Node* push(struct Node* tp, int x){
    if(isFull(top)){
        printf("Stack overflow\n");
    } else{
        struct Node *n = (struct Node*)malloc(sizeof(struct Node));
        n->data=x;
        n->next = top;
        top=n;
        return top;
    }
    
}


int pop(struct Node* tp){
    if(isEmpty(tp)){
        printf("Stack underflow\n");
    } else{
        struct Node *n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main() {
    top = push(top, 78);
    top = push(top, 56);
    top = push(top, 66);
    int element = pop(top);
    printf("Popped element is %d\n", element);
    linkedListTraversal(top);
    return 0;
}