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
#if 0
node *reverse_alternate_k (node *head, int alternate_counter) {

    node *curr = head;
    node *next = NULL;
    node *prev = NULL;
    int count  = 0;


    while (curr && count < alternate_counter) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    printf ("Head: %d\n", (head)->data);

    if(head)
        (head)->next = curr;

    count = 0;
    while (curr && count < alternate_counter-1)
        curr = curr->next;

    if (curr)
        curr->next = reverse_alternate_k(curr->next, alternate_counter);

    return prev;

}
#endif

node *kAltReverse(node *head, int k)
{
    node* current = head;
    node* next;
    node* prev = NULL;
    int count = 0;

    /*1) reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
    }

    /* 2) Now head points to the kth node.
    So change next  of head to (k+1)th node*/
    if(head != NULL)
    head->next = current;

    /* 3) We do not want to reverse next k
       nodes. So move the current
        pointer to skip next k nodes */
    count = 0;
    while(count < k-1 && current != NULL )
    {
    current = current->next;
    count++;
    }

    /* 4) Recursively call for the list
    starting from current->next. And make
    rest of the list as next of first node */
    if(current != NULL)
    current->next = kAltReverse(current->next, k);

    /* 5) prev is new head of the input list */
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

    head = kAltReverse(head, 3);

    print_list(head);

    return 0;

}
