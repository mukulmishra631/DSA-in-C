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

// case - 1 Function to insert at first
//  struct Node *insertAtFirst(struct Node *head, int data)
//  {
//      struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//      ptr->next = head;
//      ptr->data = data;
//      return ptr;
//  }

// Case 2 - Function to insert at an index
//  struct Node *insertInBetween(struct Node *head, int data, int index)
//  {
//      struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//      struct Node *p = head;

//     int i = 0;

//     while (i != index - 1)
//     {
//         p = p->next;
//         i++;
//     }
//     ptr->data = 999;
//     ptr->next = p->next;
//     p->next = ptr;
//     return head;
// }

// Case 3 - Function to insert at end
// struct Node *insertAtEnd(struct Node *head, int data)
// {
//     struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     ptr->data = data;
//     struct Node *p = head;

//     while (p->next != NULL)
//     {
//         p = p->next;
//     }
//     p->next = ptr;
//     ptr->next = NULL;
//     return head;
// }

// Case 4 - Function to insert after node
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main()
{
    struct Node *ptr;
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
    printf("\n");
    // head = insertAtFirst(head, 78);
    // head = insertInBetween(head, 78, 2);
    // head = insertAtEnd(head, 999);
    head = insertAfterNode(head, second, 456);
    linkedListTraversal(head);

    return 0;
}