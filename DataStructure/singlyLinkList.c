#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print_list (struct node *head) {

    struct node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return;
}

void push_on_front (struct node **head, int data) {

    struct node *new  = (struct node *) malloc(sizeof(struct node));

    new->data = data;
    new->next = *head;

    *head = new;

    return;
}

int main (void) {
    struct node *head   = NULL;
    struct node *second = NULL;
    struct node *third  = NULL;

    head   = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));
    third  = (struct node *) malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    print_list(head);

    push_on_front(&head, 15);

    print_list(head);

    return 0;
}
