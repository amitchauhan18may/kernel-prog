#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF_SIZE        5

struct node *end   = NULL;
struct node *front = NULL;

/*Generic Circular Buffer Node*/
struct node {
    void *data;
    struct node *next;
};

void print_circular_buffer (struct node *end) {

    if (NULL == end) {
        printf("Circular Buffer is Empty!\n");
        return;
    }

    struct node *temp = end->next;

    do {
        printf("%s \n", (unsigned char *)temp->data);
        temp = temp->next;
    } while (temp != end->next);

    printf("HEAD\n\n");

    return;

}


void push_to_empty_circular_buffer (struct node **end, void *data) {

    printf("Adding To EmptyBuffer DATA:[%s]\n", (char *)data);

    if (NULL != *end) {
        printf("It's not a EmptyCircularBuffer! \nReturning!\n");
        return;
    }

    struct node *new = (struct node *) malloc(sizeof(struct node));

    new->data = data;
    new->next = new;
    *end      = new;

    return;

}


void pust_at_end_circular_buffer (struct node **end, void *data) {
    printf("Data: %s", (char *)((&data)[0]));
    printf("Adding at end DATA:[%s]\n", (char *)data);

    if (NULL == *end) {
        printf("Empty CircularBuffer Found!\n");
        push_to_empty_circular_buffer(end, data);
        return;
    }

    struct node *new = (struct node *) malloc(sizeof(struct node));

    new->data        = data;
    new->next        = (*end)->next;
    (*end)->next     = new;
    *end             = new;

    return;

}


int main (void) {

    //pust_at_start_circular_buffer(&end, 0);
    //print_circular_buffer(end);

    //pust_at_start_circular_buffer(&end, 1);
    //print_circular_buffer(end);

    //pust_at_start_circular_buffer(&end, 2);
    //print_circular_buffer(end);

    static unsigned char a[3] = {0x80, 0x00, 0x17};
    static unsigned char b[]  = {0x80, 0x00, 0x17, '{', 'T', 'i', 'd', ':', '0',
                                 'C', 'i', 'd', ':', '1', '}'};
    static unsigned char c[]  = {0x80, 0x00, 0x17, '{', 'T', 'i', 'd', ':', '1',
                                 'C', 'i', 'd', ':', '2', '}'};


    pust_at_end_circular_buffer(&end, a, strlen(a));
    print_circular_buffer(end);

    pust_at_end_circular_buffer(&end, b);
    print_circular_buffer(end);

    pust_at_end_circular_buffer(&end, c);
    print_circular_buffer(end);

    //pop_key_from_circular_buffer(end->next, 2);
    //print_circular_buffer(end);

    //pop_key_from_circular_buffer(end->next, 4);
    //print_circular_buffer(end);

    return 0;

}

