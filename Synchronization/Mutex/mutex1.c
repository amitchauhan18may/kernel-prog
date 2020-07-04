
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int counter;
pthread_t tid[2];
pthread_mutex_t lock;

void *trythis (void *arg) {

    pthread_mutex_lock(&lock);

    unsigned long i = 0;
    counter += 1;

    printf("Job %d started\n", counter);

    for (i = 0; i < (0xFFFFFFFF); i++)
        ;
    printf("Job %d has finished\n", counter);

    pthread_mutex_unlock(&lock);

    return NULL;

}

int main () {

    int i = 0;
    int error = -1;

    while (i < 2) {

        error = pthread_create(&(tid[i]), NULL, &trythis, NULL);
        if (error) {
            printf("Thread can't be created: %s\n", strerror(error));
        }

        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    return 0;

}
