#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};


void push_on_position (struct node **head, int data, int pos) {

    struct node *current = *head, *prev;
    struct node *last = (*head)->prev;
    struct node *new = (struct node *) malloc(sizeof(struct node));
    int i;

    printf("\nAddingDATA[%d] on -> LOCATION[%d] ->\n", data, pos);

    if (NULL == *head) {
        printf("\nEmpty List!\n");
        return;
    }

    for (i = 1; i < pos-1; i++) {
        current = current->next;
        if (current == last) {
            printf("No Specified location [%d] found!\n", pos);
            return;
        }
    }

    new->data = data;
    new->next = current->next;
    new->prev = current->next->prev;
    current->next = current->next->prev = new;

    return;

}


void push_on_end (struct node **head, int data) {

    struct node *new = (struct node *) malloc(sizeof(struct node));

    if (NULL == *head) {
        printf("\nEmpty List!\n");
        printf("Adding on end DATA[%d]\n", data);
        new->data = data;
        new->next = new->prev = new;
        *head = new;
        return;
    }

    printf("\nAdding on end DATA[%d]\n", data);

/*Step 1: First Ready new node
 *Step 2: Update new's next and prev pointer
 *Step 3: Update existing Head/Last
 */

    struct node *last = (*head)->prev;
    new->data = data;
    new->next = *head;
    new->prev = last->prev;
    (*head)->prev = last->next = new;

    return;

}



void push_on_front (struct node **head, int data) {

    struct node *new = (struct node *) malloc(sizeof(struct node));

    if (NULL == *head) {
        printf("\nEmpty List!\n");
        printf("Adding on front DATA[%d]\n", data);
        new->data = data;
        new->next = new->prev = new;
        *head = new;
        return;
    }

    printf("\nAdding on front DATA[%d]\n", data);

/*Step 1: First Ready new node
 *Step 2: Update new's next and prev pointer
 *Step 3: Update existing Head/Last
 *Step 4: Update Head
 */

    struct node *last = (*head)->prev;
    new->data = data;
    new->next = *head;
    new->prev = last;
    (*head)->prev = last->next = new;
    *head = new;

    return;

}


void print_list (struct node *head) {

    struct node *temp = head;

    printf("End <- start -> ");
    while (temp->next != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("%d -> ", temp->data);
    printf("End -> start\n");
    return;

}

int main (void) {

    struct node *head = NULL;

    push_on_front(&head, 1);
    print_list(head);

    push_on_front(&head, 2);
    print_list(head);

    push_on_front(&head, 3);
    print_list(head);

    push_on_front(&head, 4);
    print_list(head);

    push_on_end(&head, 10);
    print_list(head);

    push_on_end(&head, 20);
    print_list(head);

    push_on_end(&head, 30);
    print_list(head);

    push_on_end(&head, 40);
    print_list(head);

    push_on_position(&head, 120, 9);
    print_list(head);

    return 0;
}

