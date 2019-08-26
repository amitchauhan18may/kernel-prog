#include <stdio.h>
#include "reg_callback.h"

void my_callback (void) {

    printf("Inside %s\n", __func__);
    return;
}

int main (void) {

    printf("Inside %s\n", __func__);

    callback ptr_to_cb = my_callback;
    register_cb(ptr_to_cb);

    return 0; 
}
