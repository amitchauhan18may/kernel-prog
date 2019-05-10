#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print_list (struct node *head) {

    printf("Printing LinkList\n");

    struct node *temp = head;

    while (NULL != temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return;

}

void push_on_front (struct node **head, int data) {

    printf("Pushing node at Front with Data:[%d]\n", data);

    struct node *new  = (struct node *) malloc(sizeof(struct node));

    new->data = data;
    new->next = *head;
    *head = new;

    return;

}

void push_on_end (struct node **head, int data) {

    printf("Pushing node at End   with Data:[%d]\n", data);

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

void remove_duplicates (struct node **head) {

    struct node *temp = *head;
    struct node *next = temp->next;

    while (NULL != temp) {
        if (temp->data == next->data) {
            temp->next = next->next;
            free(next);
            next = temp->next;
        }
        temp = temp->next;
    }

    return;
}


int main (void) {

    struct node *head = NULL;

    push_on_front(&head, 1);
    push_on_front(&head, 1);
    push_on_front(&head, 1);
    push_on_end(&head, 5);
    push_on_end(&head, 6);
    push_on_end(&head, 9);

    print_list(head);
    remove_duplicates(&head);
    print_list(head);
    return 0;
}
