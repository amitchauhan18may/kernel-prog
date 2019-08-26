#include <stdio.h>
#include "reg_callback.h"

void register_cb (callback ptr_reg_callback) {

    printf("Inside %s\n", __func__);
    (*ptr_reg_callback)();
    return;
}
