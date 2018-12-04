#include <stdio.h>
#include <stdlib.h>

struct stk_node {
    int data;
    struct stk_node *next;
};


int isEmpty (struct stk_node *root) {

    return !root;

}


int peek (struct stk_node *root) {

    if (isEmpty(root)) {
        printf("Empty Stack\n");
        return -1;
    }

    printf("Peek of stack: %d\n", root->data);

    return root->data;

}


void pop (struct stk_node **root, int *data) {

    if (isEmpty(*root)) {
        printf("Empty Stack\n");
        return;
    }

    struct stk_node *temp = *root;
    *root = (*root)->next;
    *data = temp->data;

    printf("Poped Data[%d]\n", *data);

    free(temp);

    return;
}

void push (struct stk_node **root, int data) {

    struct stk_node *new = (struct stk_node *) malloc(sizeof(struct stk_node));
    new->data = data;
    new->next = *root;
    *root = new;

    printf("Pushed Data: [%d]\n", (*root)->data);

    return;

}


int main (void) {

    struct stk_node *root = NULL;
    int data;

    push(&root, 1);
    push(&root, 2);
    push(&root, 3);

    pop(&root, &data);
    printf("Poped data: %d\n", data);

    pop(&root, &data);
    printf("Poped data: %d\n", data);

    pop(&root, &data);
    printf("Poped data: %d\n", data);

    pop(&root, &data);
    printf("Poped data: %d\n", data);

    printf("Peek: %d\n", peek(root));

    return 0;

}
