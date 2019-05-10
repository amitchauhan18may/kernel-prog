#include <stdio.h>
#include <stdlib.h>

/*Linklist Node*/
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

    while (NULL != next->next) {

        if (temp->data == next->data) {
            printf("\ncurrent <%d> | Next <%d>\n", temp->data, next->data);
            temp->next = next->next;
            printf("Freeing data: <%d>\n", next->data);
            free(next);
            next = temp->next;
            printf("After Freeing data:\n");
            printf("current <%d> | Next <%d>\n", temp->data, next->data);
        } else {
            printf("\ncurrent != Next\n");
            temp = temp->next;
            next = temp->next;
            printf("current <%d> | Next <%d>\n", temp->data, next->data);
        }

    }/*Loop End*/

    if (temp->data == next->data) {
            printf("\ncurrent <%d> | Next <%d>\n", temp->data, next->data);
            temp->next = next->next;
            printf("Freeing data: <%d>\n", next->data);
            free(next);
            printf("After Freeing data:\n");
            printf("current <%d> | Next <%d>\n", temp->data, next->data);
    }

    return;
}


int main (void) {

    struct node *head = NULL;

    push_on_front(&head, 1);
    push_on_front(&head, 1);
    push_on_front(&head, 1);
    push_on_front(&head, 1);
    push_on_end(&head, 5);
    push_on_end(&head, 6);
    push_on_end(&head, 9);
    push_on_end(&head, 9);

    print_list(head);
    remove_duplicates(&head);
    print_list(head);
    return 0;

}
