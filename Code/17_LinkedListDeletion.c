#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to traverse the elements of the linked list
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1 - Deleting the first node
// struct Node *deleteFirstNode(struct Node *head)
// {
//     struct Node *ptr = head;
//     head = head->next;
//     free(ptr);
//     return head;
// }

// Case 2 - Deleting node at any index
// struct Node *deleteAtIndex(struct Node *head, int index)
// {
//     struct Node *p = head;
//     struct Node *q = head->next;
//     for (int i = 0; i < index - 1; i++)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     p->next = q->next;
//     free(q);
//     return head;
// }

// Case 3 - Delete the last node
// struct Node *deleteLastNode(struct Node *head)
// {
//     struct Node *p = head;
//     struct Node *q = p->next;
//     while (q->next != NULL)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     p->next = NULL;
//     free(q);
//     return head;
// }

// Case 4 - Deleting the node with a given value
struct Node *deleteValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("The given value cannot be found , there fore it cannot be deleted ! Try with a different value.");
    }
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
    head->data = 4;
    head->next = second;
    // Link second and third node
    second->data = 3;
    second->next = third;
    // Link third and fourth node
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    linkedListTraversal(head);
    printf("\n");

    // head = deleteFirstNode(head); // For deleting the first element of the linked list
    //  head = deleteAtIndex(head, 2); // For deleting the element at any given index
    // head = deleteLastNode(head); // For deleting the last node in a linked list
    head = deleteValue(head, 3); //For deleting a specific value in a linked list, but it cannot delete the first node (use the deleteFirstNode function to delete the head node)
    printf("Linked list after deletion\n");
    linkedListTraversal(head);
    return 0;
}
