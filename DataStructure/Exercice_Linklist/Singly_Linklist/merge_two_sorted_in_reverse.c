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


node *sorted_merge (node **head1, node **head2) {

    if (((*head1) == NULL) && ((*head1) == NULL))
        return NULL;

    node *res  = NULL;
    node *temp = NULL;

    while (((*head1) != NULL) && ((*head2) != NULL)) {
        
        if ((*head1)->data <= (*head2)->data) {
            temp = (*head1)->next;
            (*head1)->next = res;
            res = *head1;
            *head1 = temp;
        } else {
            temp = (*head2)->next;
            (*head2)->next = res;
            res = *head2;
            *head2 = temp;
        }
    
    }/*Loop End*/

    while (*head1 != NULL) {
        temp = (*head1)->next;
        (*head1)->next = res;
        res = *head1;
        *head1 = temp;
    }

    while (*head2 != NULL) {
        temp = (*head2)->next;
        (*head2)->next = res;
        res = *head2;
        *head2 = temp;
    }

    return res;
}


int main (void) {
    node *head1 = NULL;
    node *head2 = NULL;
    node *res   = NULL;

    push_on_front(&head1, 90);
    push_on_front(&head1, 44);
    push_on_front(&head1, 22);
    push_on_front(&head1, 21);
    push_on_front(&head1, 10);
    push_on_front(&head1, 2);

    print_list(head1);

    push_on_front(&head2, 9);
    push_on_front(&head2, 8);
    push_on_front(&head2, 4);
    push_on_front(&head2, 2);
    push_on_front(&head2, 1);

    print_list(head2);

    res = sorted_merge(&head1, &head2);
    //res = SortedMerge(head1, head2);

    print_list(res);

    return 0;

}
