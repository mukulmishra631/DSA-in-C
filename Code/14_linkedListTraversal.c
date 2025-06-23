#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

// This *ptr is pointing to a struct Node which is written above like we made int *ptr that stores the address of int data type, similarly here we are pointing to a STRUCTURE and after that the ptr is being updated to the next element 

void linkedListTraversal(struct Node *ptr) 
{
    // Function to traverse the linked list
    while (ptr != NULL)
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
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
    head->data = 7;
    head->next = second;
    // Link second and third node
    second->data = 11;
    second->next = third;
    // Link third and fourth node
    third->data = 56; 
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 66;
    fourth->next = NULL;

    linkedListTraversal(head);
    return 0;
}