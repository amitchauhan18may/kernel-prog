#include <circularBuffer.h>

/*Generic node for storing any type of data*/
struct node {
    void *data;
    struct node *next;
};
