#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    unsigned capacity;
    int *arr;
};


int isStkFull (struct stack *stk) {

    return (stk->top == (stk->capacity - 1));

}


int isStkEmpty (struct stack *stk) {

    return (stk->top == -1);

}


void pop_stack (struct stack *stk, int *data) {

    if (isStkEmpty(stk)) {
        printf("Stack is Empty\n");
        return;
    }

    *data = stk->arr[stk->top--];
    printf("Poped data from stack: [%d]\n", stk->arr[stk->top+1]);

    return;

}


void push_stack (struct stack *stk, int data) {

    if (isStkFull(stk)) {
        printf("Stack is full\n");
        return;
    }

    stk->arr[++stk->top] = data;
    printf("Pushed data into stack: [%d]\n", stk->arr[stk->top]);

    return;

}


void create_stack (struct stack **stk, unsigned capacity) {

    printf("Creating stack of capacity: %d\n", capacity);

    *stk = (struct stack *) malloc(sizeof(struct stack));
    (*stk)->top = -1;
    (*stk)->capacity = capacity;
    (*stk)->arr = (int *) malloc(capacity * sizeof(int));

    return;

}


int main (void) {

    struct stack *stk = NULL;
    int data;

    create_stack(&stk, 3);

    push_stack(stk, 0);
    push_stack(stk, 1);
    push_stack(stk, 2);
    push_stack(stk, 2);

    pop_stack(stk, &data);
    printf("Poped data: %d\n", data);

    pop_stack(stk, &data);
    printf("Poped data: %d\n", data);

    pop_stack(stk, &data);
    printf("Poped data: %d\n", data);

    return 0;

}
