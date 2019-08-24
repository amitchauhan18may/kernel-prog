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

void swap (int *a, int *b) {

    int temp = *a;
    *a = *b; 
    *b = temp;

    return;

}

int swap_nodes_pairwise (node **head) {

    node *temp = *head;

    while (temp && temp->next != NULL) {
        swap(&temp->data, &(temp->next)->data);
        temp = temp->next->next; 
    }
    
    return 0;
}

void swap_nodes_pairwise_recursive (node **head) {

    node *temp = *head;

    if (temp && temp->next != NULL) {

        swap(&temp->data, &(temp->next)->data);
        swap_nodes_pairwise_recursive(&temp->next->next);
    }
    
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

    //swap_nodes_pairwise(&head);
    swap_nodes_pairwise_recursive(&head);
    print_list(head);

    return 0;

}







