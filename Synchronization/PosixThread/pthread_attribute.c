#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_attr_t attr;
pthread_t tid;
int run = 1;

void *func() {

    printf("Enterd into Detached thread-func\n");
    sleep(5);
    printf("Exiting from Detached thread-func\n");
    run = 0;
}

int main (void) {

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    if(pthread_create(&tid, &attr, func, NULL)) {
        printf("Failed to cretd thread\n");
        return -1;
    }

    while (run == 1) {
        printf("Waiting for thread-func to Exit\n");
        sleep(1);
    }


    return 0;
}
