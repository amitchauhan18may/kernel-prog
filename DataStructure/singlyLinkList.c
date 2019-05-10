#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

void print_list (struct node *head) {

    printf("Printing LinkList\n");

    struct node *temp = head;

    while (NULL != temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return;

}

void push_on_front (struct node **head, int data) {

    printf("Pushing node at Front with Data:[%d]\n", data);

    struct node *new  = (struct node *) malloc(sizeof(struct node));

    new->data = data;
    new->next = *head;
    *head = new;

    return;

}

void push_on_end (struct node **head, int data) {

    printf("Pushing node at End with Data:[%d]\n", data);

    struct node *temp = *head;
    struct node *new  = (struct node *) malloc(sizeof(struct node));

    new->data = data;
    new->next = NULL;

    if (NULL == *head) {
        *head = new;
        return;
    }

    while (NULL != temp->next) {
        temp = temp->next;
    }

    temp->next = new;

    return;

}

void push_on_nth (struct node **head, int data, int pos) {

    printf("Pushing node at Position:[%d] | Data:[%d]\n", pos, data);

    if (NULL == *head) {
        printf("Empty LinkLIst");
        return;
    }

    struct node *temp_head, *temp;
    temp_head = *head;
    int i = 1;
    struct node *new  = (struct node *) malloc(sizeof(struct node));

    new->data = data;

    while (i < pos-1) {
        if (NULL == temp_head->next){
            printf("No specified location found!\n");
            return;
        }
        temp_head = temp_head->next;
        i++;
    }

    temp = temp_head->next;
    temp_head->next = new;
    new->next = temp;

    return;

}

void pop_on_position (struct node **head, int pos) {

    printf("Poping node at position: [%d]\n", pos);

    struct node *temp = *head;
    struct node *prev;

    if (NULL == *head) {
        printf("Empty LinkList !\nNothing to remove\n");
        return;
    }


    if (0 == pos) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (NULL != temp && pos--) {
        prev = temp;
        temp = temp->next;
    }

    if (NULL == temp) {
        printf("No pop-node present for this position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    return;

}

void reverse_linklist (struct node **head) {

    printf("Reversing LinkList\n");

    struct node *prev = NULL;
    struct node *next = NULL;
    struct node *current = *head;

    while (NULL != current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;

    return;

}

void recursive_reverse_linklist (struct node **head) {

    if (NULL == *head) {
        printf("Empty LinkList\n");
        return;
    }

    struct node *first = *head;
    struct node *rest  = first->next;

    if (NULL == rest) {
        printf("Reversing LinkList using recursion\n");
        return;
    }

    recursive_reverse_linklist(&rest);

    first->next->next = first;
    first->next = NULL;

    *head = rest;

    return;

}

void get_nth_node_from_end (struct node **node, int n) {

    static int i, total_nodes;
    struct node *temp = *node;

    if (NULL == temp) {

        if (n > total_nodes) {
            printf("Getting %dth node from End > TotalNodes: %d\n",
                    n, total_nodes);
            return;
        }

        return;

    } else {
        total_nodes++;
    }

    get_nth_node_from_end(&(temp->next), n);


    if (++i == n) {
        printf("Getting %dth Node from End: [%d]\n", n, temp->data);
        return;
    }

    return;

}


void get_middle_of_linklist (struct node **head) {

    printf("Getting middle of linklist\n");

    struct node *slow_ptr, *fast_ptr;

    slow_ptr = fast_ptr = *head;

    while ((NULL != fast_ptr) && (NULL != fast_ptr->next)) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    if (NULL != slow_ptr)
        printf("Mid-Node [%d]\n", slow_ptr->data);
}

void get_middle_single_pointer (struct node *head) {

    struct node *mid = head;
    int count        = 0;

    while (NULL != head) {

        if (count & 1)
            mid = mid->next;

        count++;
        head = head->next;
    }

    if (NULL != mid)
        printf("Mid Data: %d\n", mid->data);


    return;
}

void delete_linklist (struct node **head) {

    printf("%s\n", __func__);

    struct node *current = *head;
    struct node *next    =  NULL;

    if (NULL == *head) {
        printf("No node to delete in linklist\n");
        return;
    }

    while (NULL != current) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = current;

    return;

}

void recursive_delete_linklist (struct node **head_ref, struct node *head) {

    struct node *current = head;
    struct node *next    = current->next;

    if (NULL == next)
        return;

    recursive_delete_linklist(head_ref, next);

    current->next = next->next;
    printf("Freeing      <%d>\n", next->data);
    free(next);

    if (current == *head_ref) {
        printf("freeing head <%d>\n", current->data);
        *head_ref = current->next;
        free(current);
    }

    return;
}

int get_linklist_length (struct node *head) {

    if(NULL == head)
        return 0;

    return 1 + get_linklist_length(head->next);

}

bool search_key_in_linklist (struct node *head, int key) {

    if (NULL == head)
        return false;

    if (key == head->data)
        return true;

    return search_key_in_linklist(head->next, key);

}

int main (void) {

    struct node *head   = NULL;

    push_on_front(&head, 3);
    print_list(head);

    push_on_front(&head, 2);
    print_list(head);

    push_on_front(&head, 1);
    print_list(head);

    push_on_front(&head, 4);
    print_list(head);

    push_on_end(&head, 25);
    print_list(head);

    push_on_nth (&head, 112, 3);
    print_list(head);

//    push_on_nth (&head, 12, 3);
//    print_list(head);
//
    pop_on_position(&head, 0);
    print_list(head);

//    recursive_delete_linklist(&head, head);
//    print_list(head);
//
    get_middle_single_pointer(head);
//    printf("List Count: %d\n", get_linklist_length(head));
//    if(search_key_in_linklist(head, 525))
//        printf("Key found!\n");
//    else
//        printf("No key found!\n");
//    delete_linklist(&head);
//    print_list(head);
//    delete_linklist(&head);
//    reverse_linklist(&head);
//    print_list(head);
//
//    recursive_reverse_linklist(&head);
//    print_list(head);
//
//    get_nth_node_from_end(&head, 5);
//
//    get_middle_of_linklist(&head);

    return 0;

}
