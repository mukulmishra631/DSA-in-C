#include<stdio.h>
#include<malloc.h>

struct node{
    int data; 
    struct node *left;
    struct node *right;
};



int main() {
    // Constructing the root node
    struct node *p;
    p = (struct node*) malloc(sizeof(struct node));
    p->left = NULL;
    p->right = NULL;

    // Constructing the second node
    struct node *p1;
    p1 = (struct node*) malloc(sizeof(struct node));
    p1->left = NULL;
    p1->right = NULL;

    // Constructing the third node
    struct node *p2;
    p2 = (struct node*) malloc(sizeof(struct node));
    p2->left = NULL;
    p2->right = NULL;

    // LInking the root node with left and right children
    p->left = p1;
    p->right = p2;
    return 0;
}