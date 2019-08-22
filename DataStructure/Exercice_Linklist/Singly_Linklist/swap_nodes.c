#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int print_list (node *head) {

    printf("Printing LinkList\n");

    node *temp = head;
    int len = 0;

    while (NULL != temp) {
        printf("%d -> ", temp->data);
        len++;
        temp = temp->next;
    }

    printf("NULL\n");

    return len;
}

void push_on_front (node **head, int data) {

    printf("Pushing node at Front with Data:[%d]\n", data);

    node *new  = (node *) malloc(sizeof(node));

    new->data = data;
    new->next = *head;
    *head = new;

    return;

}

int swap_nodes (node **head, int key1, int key2) {

    if (key1 == key2)
        return 0;

    node *prevX = NULL;
    node *currX = *head;
    node *prevY = NULL;
    node *currY = *head;
    node *temp = NULL;

    while (currX && currX->data != key1) {
        prevX = currX;
        currX = currX->next;
    }

    while (currY && currY->data != key2) {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL)
        return 0;

    if (prevX != NULL)
        prevX->next = currY;
    else
        *head = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else
        *head = currX;

    temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;

    return 0;

}

int main (void) {
    node *head = NULL;

    push_on_front(&head, 10);
    push_on_front(&head, 22);
    push_on_front(&head, 90);
    push_on_front(&head, 8);
    push_on_front(&head, 2);
    push_on_front(&head, 44);
    push_on_front(&head, 21);
    push_on_front(&head, 15);

    print_list(head);

    swap_nodes (&head, 15, 90);

    print_list(head);

    return 0;

}
