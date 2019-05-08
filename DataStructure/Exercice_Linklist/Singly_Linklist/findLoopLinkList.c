#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void push_on_front (Node **head, int data) {

    printf("Pushing node at Front with Data:[%d]\n", data);

    Node *new  = (Node *) malloc(sizeof(Node));

    new->data = data;
    new->next = *head;
    *head = new;

    return;

}

void detectLoop (Node **head) {
    Node *slow, *fast;
    slow = fast = *head;

    while ((NULL != fast) && (NULL != fast->next)) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            printf("Loop Detected: %d\n", slow->data);
            return;
        }
    }

    printf("No Loop Detected\n");

    return;
}

int main (void) {
    Node *head = NULL;

    push_on_front(&head, 1);
    push_on_front(&head, 2);
    push_on_front(&head, 3);
    push_on_front(&head, 4);

    head->next->next->next->next = head;

    detectLoop(&head);

    return 0;

}
