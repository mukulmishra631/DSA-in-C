#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list : \n");
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
        printf("The queue is full");
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
            f = r = n; // Queue is empty
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if (f == NULL)
        printf("The queueu is empty\n");
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val; 
}
int main()
{
    linkedListTraversal(f);
    printf("Dequeuing element : %d\n",dequeue());
    enqueue(34);
    enqueue(45);
    enqueue(22);
    enqueue(33);
    linkedListTraversal(f);
    printf("Dequeuing element : %d\n", dequeue());
    printf("Dequeuing element : %d\n", dequeue());
    printf("Dequeuing element : %d\n", dequeue());
    linkedListTraversal(f);
    return 0;
}