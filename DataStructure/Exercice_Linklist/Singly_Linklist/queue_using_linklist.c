#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

void dequeue (struct queue **q) {

    int dequeue_data;

    if (NULL == (*q)->front) {
        printf("Empty Queue\n");
        return;
    }

    dequeue_data = (*q)->front->data;
    struct node *temp = (*q)->front;
    (*q)->front = (*q)->front->next;

    printf("Removed node from Queue\nData[%d]\n", dequeue_data);

    free(temp);

    return;

}


void enqueue (struct queue **q, int data) {

    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    if (NULL == (*q)->rear) {
        (*q)->rear = (*q)->front = new;
        printf("Adding node to Empty Queue\nData[%d]\n", (*q)->rear->data);
        return;
    }

    (*q)->rear->next = new;
    (*q)->rear = new;

    printf("Adding node to Queue\nData[%d]\n", (*q)->rear->data);

    return;

}


int main (void) {

    struct queue *q = (struct queue *) malloc(sizeof(struct queue));
    q->front = q->rear = NULL;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    return 0;

}
