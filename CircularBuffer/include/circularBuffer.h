#include <stdio.h>
#include <stdlib.h>
#include <string .h>

struct node {
    void *data;
    struct node *next;
};


void print_circular_buffer(struct node *end);

int push_to_empty_circular_buffer(struct node **start, struct node **end,
                                  void *data, int size);

int pust_at_circular_buffer(struct node **start, struct node **end,
                            void *data, int size);

int pop_from_circular_buffer (struct node *head, struct node *tail);

int is_circular_buffer_empty(int buf, int buf_limit);

int is_circular_buffer_full(int buf, int buf_limit);
