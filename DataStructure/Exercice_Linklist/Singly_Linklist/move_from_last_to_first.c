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

int move_last_to_first (node **head) {

    node *temp = *head;
    node *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    temp->next = *head;
    *head = temp;
    prev->next = NULL;

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

    move_last_to_first(&head);

    print_list(head);

    return 0;

}
