#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
    if(q->r==q->size-1 && q->f==0) return 1;
    else return 0;
}

int isEmpty(struct queue *q){
    if(q->r==q->f) return 1; // queue is empty
    else return 0; // queue is not empty
}

void enqueue(struct  queue *q, int val){
    if(isFull(q)) printf("This queue is full\n");
    else{
        q->r=q->r+1; // q->r++;
        q->arr[q->r]= val;
        printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)) printf("No element to dequeue\n");
    else{
        a = q->arr[q->f + 1];
        q->f++;
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr=(int *) malloc(q.size*sizeof(int));

    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1);
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));

    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue is not empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
    else{
        printf("Queue is not full\n");
    }

    // Free the allocated memory
    free(q.arr);
    return 0;
}
