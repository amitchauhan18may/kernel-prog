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


node *get_tail (node **head) {

    node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    return temp;

}


node *partition (node **head, node **tail, node **new_head, node **new_tail) {

    node *pivot = *tail;
    node *curr  = *head;
    node *prev  = NULL;
    node *end   = *tail;

    while (curr != pivot) {
        if (curr->data < pivot->data) {
            if (*new_head == NULL)
                *new_head = curr;
            prev = curr;
            curr = curr->next;
        } else {
                if (prev)
                    prev->next = curr->next;
            node *temp = curr->next;
            curr->next = NULL;
            end->next = curr;
            end = curr;
            curr = temp;
        }
    }

    if (*new_head == NULL)
        *new_head = pivot;

    *new_tail = end;

    return pivot;
}


node *quick_sort_recur (node **head, node **tail) {

    if (!*head || *head == *tail)
        return NULL;

    node *new_head = NULL;
    node *new_tail = NULL;

    node *pivot = partition(head, tail, &new_head, &new_tail);
    if (new_head != pivot) {
        node *temp = new_head;
        while (temp->next != pivot) {
            temp = temp->next;
        }

        temp->next = NULL;

        quick_sort_recur(&new_head, &temp);

        temp = get_tail(&new_head);

        temp->next = pivot;
    }

    pivot->next = quick_sort_recur(&(pivot->next), &new_tail);


    return new_head;

}


void quickSort(node **headRef)
{
    node *tail = get_tail(headRef);
    (*headRef) = quick_sort_recur(headRef, &tail);
    return;
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

    quickSort(&head);
    printf("Main:\n");
    print_list(head);

    return 0;

}
