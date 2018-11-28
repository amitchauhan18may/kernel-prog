#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};


void print_doubly_list (struct node *head) {

    struct node *last = head;
    struct node *rev;

    printf("\nPrinting list in forward\n");

    printf("NULL -> ");

    while (NULL != last) {
        printf("%d -> ", last->data);
        rev = last;
        last = last->next;
    }

    printf("NULL\n");

    printf("\nPrinting list in Backward\n");

    printf("NULL -> ");

    while (NULL != rev) {
        printf("%d -> ", rev->data);
        rev = rev->prev;
    }

    printf("NULL\n");

    return;

}


void append_on_doubly_list (struct node **head, int data) {

    printf("\nAppending DATA[%d]\n", data);

    struct node *last = *head;

    struct node *new = (struct node *) malloc(sizeof(struct node));
    if (NULL == new) {
        printf("Failed to allocate memory\n");
        return;
    }

    new->data = data;
    new->next = NULL;

    if(NULL == *head) {
        new->prev = NULL;
        *head = new;
        return;
    }


    while (NULL == last->next)
        last = last->next;

    last->next = new;
    new->prev = last;

    return;

}


void push_on_front (struct node **head, int data) {

    printf("\nPushing on front DATA[%d]\n", data);

    if (NULL == *head) {
        printf("Empty DoublyList FOund!\n");
        append_on_doubly_list(head, data);
        return;
    }

    struct node *temp = *head;

    struct node *new = (struct node *) malloc(sizeof(struct node));

    new->data = data;
    new->next = *head;
    new->prev = NULL;

    (*head)->prev = new;
    *head = new;

    return;

}


void pop_dulbly_list (struct node **head, struct node *pop_node) {

    if ((NULL == *head) || (NULL == pop_node)) {
        printf("Either Head || Pop_Node is NULL!\n");
        return;
    }

    printf("Poping DATA[%d]\n", pop_node->data);

    if (*head == pop_node)
        *head = pop_node->next;

    if (NULL != pop_node->next)
        pop_node->next->prev = pop_node->prev;

    if (NULL != pop_node->prev)
        pop_node->prev->next = pop_node->next;

    free(pop_node);

    return;

}


void pop_nth_node (struct node **head, int pos) {

    struct node *current = *head;
    int i;

    printf("\nPoping at position [%d]\n", pos);

    if (NULL == *head || pos <= 0) {
        printf("Please pass position greater than ZERO or Not-Null HEAD\n");
        return;
    }

    for (i = 1; (NULL != current) && (i < pos); i++)
        current = current->next;

    if (NULL == current) {
        printf("No Position: %d found\n", pos);
        return;
    }

    pop_dulbly_list(head, current);

    return;

}


int main (void) {

    struct node *head = NULL;

    push_on_front(&head, 1);
    print_doubly_list(head);

    push_on_front(&head, 2);
    print_doubly_list(head);

    push_on_front(&head, 3);
    print_doubly_list(head);

    pop_nth_node(&head, 1);
    print_doubly_list(head);

    return 0;

}
