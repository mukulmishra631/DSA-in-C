#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

// This *ptr is pointing to a struct Node which is written above like we made int *ptr that stores the address of int data type, similarly here we are pointing to a STRUCTURE and after that the ptr is being updated to the next element

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    // Function to traverse the linked list
    // printf("Element : %d \n", ptr->data);
    // ptr = ptr->next; //  We have to kickstart ptr once mannualy because ptr is already on head thus the ptr will not move forward so we have to mannualy print the first element and then run the while loop
    // while (ptr != head)
    // {
    //     printf("Element : %d \n", ptr->data);
    //     ptr = ptr->next;
    // } //This while loop will run until the ptr comes to head

    // We can use do while loop instead of the above method, because in do while loop the code runs at least one time then the condition is checked , so here the first element will be printed and the ptr will initiate from the second node and stop when again reaches the head node
    do
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p is pointing to the last node of the circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    // Link first and second node
    head->data = 4;
    head->next = second;
    // Link second and third node
    second->data = 3;
    second->next = third;
    // Link third and fourth node
    third->data = 6;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = head;
    printf("Circular Linked list before insertion\n");
    linkedListTraversal(head);
    printf("\n");

    insertAtFirst(head, 888);
    printf("Circular Linked list after insertion \n");
    linkedListTraversal(head);
    return 0;
}