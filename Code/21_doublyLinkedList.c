#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// This function is initiating the *p from the last node and traversing backwards and printing the nodes data using the prev pointer until it reaches the NULL node (But there is a problem, how to initiate it from the first node becuase if the linked list will be very then it will be difficult to find the last node so try to write a function which first takes the *p to the last node and then prints the nodes data backwards in reverse manner)
// void display(struct Node *ptr)
// {
//     while(ptr!=NULL)
//     {
//         printf("%d ", ptr->data);
//         ptr = ptr->prev;
//     }
// }

struct Node *moveToLast(struct Node *p)
{
    while (p->next!= NULL)
    {
       p=p->next;
    }
    return p; // returns last node
}

void displayReverse(struct Node *p)
{
    p = moveToLast(p);
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}

int main()
{
    struct Node *N1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *N4 = (struct Node *)malloc(sizeof(struct Node));

    N1->data = 7;
    N1->prev = NULL;
    N1->next = N2;

    N2->data = 9;
    N2->prev = N1;
    N2->next = N3;

    N3->data = 11;
    N3->prev = N2;
    N3->next = N4;

    N4->data = 13;
    N4->prev = N3;
    N4->next = NULL;

    printf("Original List : ");
    display(N1);
    printf("\n");
    printf("Reversed List : ");
    displayReverse(N1);
    return 0;
}