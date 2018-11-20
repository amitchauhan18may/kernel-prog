#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print_list (struct node *head) {

    struct node *temp = head;

    while (NULL != temp) {
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

void push_on_end (struct node **head, int data) {

    struct node *temp = *head;
    struct node *new  = (struct node *) malloc(sizeof(struct node));

    new->data = data;
    new->next = NULL;

    if (NULL == *head) {
        *head = new;
        return;
    }

    while (NULL != temp->next) {
        temp = temp->next;
    }

    temp->next = new;

    return;

}

void push_on_nth (struct node **head, int data, int pos) {

    if (NULL == *head) {
        printf("Empty LinkLIst");
        return;
    }

    struct node *temp_head, *temp;
    temp_head = *head;
    int i = 1;
    struct node *new  = (struct node *) malloc(sizeof(struct node));

    new->data = data;

    while (i < pos-1) {
        if (NULL == temp_head->next){
            printf("No specified location found!\n");
            return;
        }
        temp_head = temp_head->next;
        i++;
    }

    temp = temp_head->next;
    temp_head->next = new;
    new->next = temp;

    return;

}

void pop_on_position (struct node **head, int pos) {

    struct node *temp = *head;
    struct node *prev;

    if (NULL == *head) {
        printf("Empty LinkList !\nNothing to remove\n");
        return;
    }


    if (0 == pos) {
        prev = temp;
        temp = temp->next;
        *head = temp;
        free(prev);
        return;
    }

    while (NULL != temp && pos--) {
        prev = temp;
        temp = temp->next;
    }

    if (NULL == temp) {
        printf("No pop-node for this position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

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

    push_on_front(&head, 4);
    print_list(head);

    push_on_end(&head, 25);
    print_list(head);

    push_on_nth (&head, 112, 3);
    print_list(head);

    pop_on_position(&head, 8);
    print_list(head);

    return 0;

}
