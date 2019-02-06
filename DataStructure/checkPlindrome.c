#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

void print_list (struct node *head) {

    printf("Printing LinkList\n");

    struct node *temp = head;

    while (NULL != temp) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return;

}

void push_on_front (struct node **head, int data) {

    printf("Pushing node at Front with Data:[%c]\n", data);

    struct node *new  = (struct node *) malloc(sizeof(struct node));

    new->data = data;
    new->next = *head;
    *head = new;

    return;

}

void isPalindrome (Node **head, Node *node) {

    if (NULL == node) {
        return;
    }

    isPalindrome(head, node->next);

    if (node->data == (*head)->data) {
        if (node == *head) {
            printf("Is palindrome\n");
            exit(0);
        }
        *head = (*head)->next;
        return;
    } else {
        printf("Is not palindrom\n");
        exit(1);
    }

    return;
}

int main (void) {
    Node *head = NULL;

    push_on_front(&head, 'R');
    push_on_front(&head, 'c');
    push_on_front(&head, 'D');
    push_on_front(&head, 'A');
    push_on_front(&head, 'R');

    print_list(head);
    Node *node = head;
    isPalindrome(&node, node);
    print_list(head);

    return 0;

}
