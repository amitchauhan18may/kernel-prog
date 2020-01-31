#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define COUNT1          3
#define COUNT2          7
#define COUNTER_DONE    10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_mutex = PTHREAD_COND_INITIALIZER;

int counter;
pthread_t tid[2];

void *func1() {

    while (1) {

        pthread_mutex_lock(&mutex);

        if (counter > COUNT1 && counter < COUNT2) {

            pthread_cond_signal(&cond_mutex);

        } else {

            printf("Func1 counter %d\n", ++counter);

        }

        pthread_mutex_unlock(&mutex);

        if (counter >= COUNTER_DONE) {
            printf("if counter :%d\n", counter);
            exit(0);
        }
    }
        return NULL;

}


void *func2() {

    while (1) {

            pthread_mutex_lock(&mutex);

            pthread_cond_wait(&cond_mutex, &mutex);
            printf("Func2 counter %d\n", ++counter);

            pthread_mutex_unlock(&mutex);

            if (counter > COUNTER_DONE)
                return NULL;
    }

    return NULL;
}


int main (void) {
    if (pthread_create(&tid[0], NULL, func1, NULL)) {
        printf("Failed to create thread1\n");
        return -1;
    }
    if (pthread_create(&tid[1], NULL, func2, NULL)) {
        printf("Failed to create thread1\n");
        return -1;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    return 0;
}
