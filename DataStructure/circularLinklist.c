#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print_circular_list (struct node *end) {

    if (NULL == end) {
        printf("Circular LIst is Empty!\n");
        return;
    }

    struct node *temp = end->next;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != end->next);

    printf("HEAD\n\n");

    return;

}

void push_to_empty_circular_list (struct node **end, int data) {

    printf("Adding Data To Empty Circular List DATA:[%d]\n", data);

    if (NULL != *end) {
        printf("It's not a EmptyCircularList! \nReturning!\n");
        return;
    }

    struct node *new = (struct node *) malloc(sizeof(struct node));

    new->data = data;
    new->next = new;
    *end      = new;

    return;

}

void pust_at_start_circular_list (struct node **end, int data) {

    printf("Adding data at start of CircularList DATA:[%d]\n", data);

    if (NULL == *end) {
        printf("Empty CircularList Found!\n");
        push_to_empty_circular_list(end, data);
        return;
    }

    struct node *new = (struct node *) malloc(sizeof(struct node));

    new->data        = data;
    new->next        = (*end)->next;
    (*end)->next     = new;

    return;

}

void pust_at_end_circular_list (struct node **end, int data) {

    printf("Adding data at end of CircularList DATA:[%d]\n", data);

    if (NULL == *end) {
        printf("Empty CircularList Found!\n");
        push_to_empty_circular_list(end, data);
        return;
    }

    struct node *new = (struct node *) malloc(sizeof(struct node));

    new->data        = data;
    new->next        = (*end)->next;
    (*end)->next     = new;
    *end             = new;

    return;

}

void pop_key_from_circular_list (struct node *head, int key) {

    printf("Poping DATA:[%d]\n", key);

    if (NULL == head) {
        printf("Empty Circular List!\n");
        return;
    }

    struct node *temp = head, *prev;

    if (key == head->data) {
        head = temp->next;
        free(temp);
        return;
    }

    while ((head != temp->next) && (key != temp->data)) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == head) {
        printf("No key:[%d] found to delete in Circular List\n", key);
        return;
    }

    prev->next = temp->next;

    free(temp);

    return;

}

int main (void) {

    struct node *end = NULL;

    pust_at_start_circular_list(&end, 0);
    print_circular_list(end);

    pust_at_start_circular_list(&end, 1);
    print_circular_list(end);

    pust_at_start_circular_list(&end, 2);
    print_circular_list(end);

    pust_at_end_circular_list(&end, 3);
    print_circular_list(end);

    pust_at_end_circular_list(&end, 4);
    print_circular_list(end);

    pust_at_end_circular_list(&end, 5);
    print_circular_list(end);

    pop_key_from_circular_list(end->next, 2);
    print_circular_list(end);

    return 0;

}
