#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print_List (struct node *head) {

    struct node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return;
}

int main () {
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

    print_List(head);

    return 0;
}
