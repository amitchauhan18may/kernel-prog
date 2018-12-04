#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front;
    int rear;
    int size;
    unsigned capacity;
    int *array;
};


int isQueueEmpty (struct queue *q) {

    return (q->size == 0);

}


int dequeue (struct queue **q) {

    int data = -1;

    if (isQueueEmpty(*q)) {
        printf("Queue is Empty\n");
        return -1;
    }

    data = (*q)->array[(*q)->front];
    (*q)->front = ((*q)->front + 1) % (*q)->capacity;
    (*q)->size = (*q)->size - 1;

    printf("Dequed Data [%d]\n", data);

    return data;

}


int isQueueFull (struct queue *q) {

    return (q->size == q->capacity);

}


void enqueue (struct queue **q, int data) {

    if (isQueueFull(*q)) {
        printf("Queue is full\n");
        return;
    }

    (*q)->rear = ((*q)->rear + 1) % (*q)->capacity;
    (*q)->array[(*q)->rear] = data;
    (*q)->size = (*q)->size + 1;

    printf("Enqued Data [%d]\n", (*q)->array[(*q)->rear]);

    return;

}


void crete_queue (struct queue **q, unsigned capacity) {

    printf("Creting Queue of capacity: %d\n", capacity);

    *q = (struct queue *) malloc(sizeof(struct queue));

    (*q)->front = (*q)->size = 0;
    (*q)->rear = capacity - 1;
    (*q)->capacity = capacity;

    (*q)->array = (int *) malloc(capacity * sizeof(int));

    return;

}


int main (void) {

    struct queue *q = NULL;

    crete_queue(&q, 3);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    return 0;

}
