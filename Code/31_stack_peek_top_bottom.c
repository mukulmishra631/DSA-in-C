#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* top = NULL; //this is a global variable
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

struct  Node* push(struct Node* top, int x){
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


int peek(int pos){
    struct Node *ptr = top;
    for(int i = 0; (i< pos-1 && ptr!=NULL); i++){
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    } else return -1;
}

int stackTop(){
    return top->data;
}
int stackBottom(struct Node *top){
    struct Node *ptr = top;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    return ptr->data;
}
int main() {
    // struct Node *head;
    // struct Node *second;
    // struct Node *third;
    // struct Node *fourth;

    // head = (struct Node *)malloc(sizeof(struct Node));
    // second = (struct Node *)malloc(sizeof(struct Node));
    // third = (struct Node *)malloc(sizeof(struct Node));
    // fourth = (struct Node *)malloc(sizeof(struct Node));

    // head->data=4;
    // head->next=second;

    // second->data=7;
    // second->next=third;

    // third->data=9;
    // third->next =fourth;

    // fourth->data=11;
    // fourth->next=NULL;
    top = push(top, 78);
    top = push(top, 56);
    top = push(top, 66);
    top = push(top, 57);
    
    linkedListTraversal(top);
    for(int i = 1; i<=4; i++){
        printf("Value at position %d is : %d\n", i, peek(i));
    }
    int a = stackTop();
    int b = stackBottom(top);
    printf("Top value is : %d\n", a);
    printf("Bottom value is : %d\n", b);
    return 0;
}