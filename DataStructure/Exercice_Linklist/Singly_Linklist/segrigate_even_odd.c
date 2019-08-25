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

int segrigate (node **head) {

    node *curr = *head;
    node *prev = NULL;
    node *end = *head;
    node *new_end = NULL;

    while (end->next != NULL)
        end = end->next;

    new_end = end;

    printf("END: %d\n", end->data);

    while (curr != end) {
        
        printf("CURR: %d\n", curr->data);
        if (curr->data % 2) {
            /*Odd value*/
            if (prev) {
                prev->next = curr->next;
                curr->next = NULL;
                new_end->next = curr;
                curr = prev->next;
                new_end = new_end->next;
            } else {
                if (!prev)
                    *head = (*head)->next;
                new_end->next = curr;
                curr = curr->next;
                new_end->next->next = prev;
                new_end = new_end->next;
            }
            
        } else {
            /*Even value*/
            prev = curr;
            curr = curr->next;
        }
    
    }/*Loop End*/

    if (end->data % 2) {
        prev->next = curr->next;
        curr->next = NULL;
        new_end->next = curr;
        curr = prev->next;
        new_end = new_end->next;
    }

}

int main (void) {
    node *head = NULL;

    push_on_front(&head, 5);
    push_on_front(&head, 2);
    push_on_front(&head, 3);
    push_on_front(&head, 6);
    push_on_front(&head, 1);
    push_on_front(&head, 4);
    push_on_front(&head, 7);

    print_list(head);

    segrigate(&head);

    print_list(head);

    return 0;

}
