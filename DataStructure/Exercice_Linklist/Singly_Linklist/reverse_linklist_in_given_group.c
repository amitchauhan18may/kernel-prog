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


node * reverse_in_group (node *head, int group_size) {

    node *curr = head;
    node *prev = NULL;
    node *next = NULL;
    int count  = 0;

    while (curr && count < group_size) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;    
    }

    if (curr) {
        printf("Next: %d\n", next->data);
        head->next = reverse_in_group(next, group_size);
    }

    return prev;

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

    head = reverse_in_group(head, 3);
    print_list(head);

    return 0;

}
