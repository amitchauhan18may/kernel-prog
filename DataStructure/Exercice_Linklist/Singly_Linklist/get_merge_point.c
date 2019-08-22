#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int print_list (struct node *head) {

    printf("Printing LinkList\n");

    struct node *temp = head;
    int len = 0;

    while (NULL != temp) {
        printf("%d -> ", temp->data);
        len++;
        temp = temp->next;
    }

    printf("NULL\n");

    return len;
}

void push_on_front (struct node **head, int data) {

    printf("Pushing node at Front with Data:[%d]\n", data);

    struct node *new  = (struct node *) malloc(sizeof(struct node));

    new->data = data;
    new->next = *head;
    *head = new;

    return;

}

void get_linklists_merge_point (struct node *head1, struct node *head2) {

    int length1, length2, i;
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    length1 = print_list(head1);
    length2 = print_list(head2);

    printf("length1: %d | length2: %d\n", length1, length2);

    if (length1 > length2) {
        for (i = 0; i < length1-length2; i++)
            temp1 = temp1->next;
    } else {
        for (i = 0; i < length2-length1; i++) {
            temp2 = temp2->next;
            printf("head2: %d\n", temp2->data);
        }
    }

    while ((NULL != temp1) && (temp1->next != temp2->next)) {
        printf("%d | %d\n", temp1->data, temp2->data);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if ((NULL == temp1->next) || (NULL == temp2->next))
        printf("There is no merge point\n");
    else
        printf("Merge Node [%d]\n", temp1->data);

    return;
}

int main (void) {

    struct node *head1 = NULL;
    struct node *head2 = NULL;

/* Creating first linklist */
    push_on_front(&head1, 6);
    push_on_front(&head1, 8);
    push_on_front(&head1, 5);
    push_on_front(&head1, 2);
    push_on_front(&head1, 9);
    push_on_front(&head1, 1);

    push_on_front(&head2, 2);
    push_on_front(&head2, 4);

/* Merging second linklist */
    head2->next->next = head1->next->next->next;

    get_linklists_merge_point(head1, head2);

    return 0;

}
