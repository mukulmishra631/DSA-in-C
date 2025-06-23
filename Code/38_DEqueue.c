// DEqueue = Double Ended Queue
// dequeue = operation in queue , so don't confuse both the terms
#include <stdio.h>
#include <stdlib.h>
struct DEqueue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct DEqueue *q)
{
    if (q->r == q->size - 1 && q->f == 0 || q->r + 1 == q->f)
    {
        printf("The queue is full\n");
        return 1;
    }
    else
        return 0;
}

int isEmpty(struct DEqueue *q)
{
    if (q->f == -1 && q->r == -1)
    {
        printf("The queue is empty\n");
        return 1;
    }
    else
        return 0;
}

void push_rear(struct DEqueue *q, int val)
{
    if (isFull(q))
        printf("The queue is full, cannot enqueue elements\n");
    else
    {
        if (isEmpty(q))
        {
            q->f = q->r = 0;
        }
        else
            q->r++;
        q->arr[q->r] = val;
        printf("Enqueued element from rear end : %d\n", val);
    }
}

int pop_front(struct DEqueue *q)
{
    int a = -1; // This will be returned if dequeue from front end would not be possible
    if (isEmpty(q))
        printf("The queue is empty, cannot dequeue elements from the queue\n");
    else
    {
        a = q->arr[q->f];
        if (q->f == q->r)
        {
            q->f = q->r = -1;
        }
        else
        {
            q->f++;
        }
        printf("Dequeued element from front end : %d\n", a);
    }
    return a;
}

void push_front(struct DEqueue *q, int val)
{
    if (isFull(q))
        printf("The queue is full, cannot enqueue elements from the front end.\n");
    else
    {
        if (isEmpty(q))
        {
            q->f = q->r = 0;
        }
        else if (q->f == 0)
        {
            q->f = q->size - 1;
        }
        else
            q->f--;
    }
    q->arr[q->f] = val;
    printf("Enqueued element from front : %d\n", val);
}

int pop_rear(struct DEqueue *q)
{
    int a = -1; // This will be returned if dequeue from REAR END would not be possible
    if (isEmpty(q))
        printf("The queue is empty, cannot dequeue any element from the REAR END !");
    else
    {
        a = q->arr[q->r];
        if (q->f == q->r)
        {
            q->f = q->r = -1;
        }
        else if (q->r == 0)
        {
            q->r = q->size - 1;
        }
        else
            q->r--;
        printf("Dequeued element from REAR END : %d\n", a);
    }
    return a;
}

int main()
{
    struct DEqueue q;
    q.size = 6;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    push_front(&q, 5);
    push_front(&q, 6);
    push_front(&q, 7);
    push_front(&q, 8);
    push_front(&q, 9);
    pop_front(&q);
    pop_front(&q);
    return 0;
}
