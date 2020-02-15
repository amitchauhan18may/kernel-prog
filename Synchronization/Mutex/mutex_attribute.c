#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

pthread_mutexattr_t m_attr;
pthread_mutex_t mutex;
int counter;

void *func () {

    int i;
    pthread_mutex_lock(&mutex);
    printf("%d-Thread stared\n", pthread_self());
    for (i = 0; i < 0xFFFFFF; i++);
    printf("%d-Thread Counter: %d\n", pthread_self(), ++counter);
    pthread_mutex_unlock(&mutex);
    printf("%d-Thread Exited\n", pthread_self());

    return NULL;
}


int main (void) {

    int i;
    int ret = -1;
    pthread_t tid[2];
    printf("Counter %d\n", counter);
    ret = pthread_mutexattr_init(&m_attr);
    if (ret < 0) {
        printf("Failed to initialize mutex attribute\n");
    }

    ret = pthread_mutexattr_settype(&m_attr, PTHREAD_MUTEX_RECURSIVE);
    if (ret < 0) {
        printf("Failed to set mutex attribute\n");
    }

    ret = pthread_mutex_init(&mutex, &m_attr);
    if (ret < 0) {
        printf("Failed to initialize mutex\n");
    }

    for (i = 0; i < 2; i++) {
        if (pthread_create(&tid[i], NULL, func, NULL)) {
            printf("Failed to create thread: %d\n", i);
            return errno;
        }
    }

    for (i = 0; i < 2; i++) {
        if (pthread_join(tid[i], NULL)) {
            printf("Failed to create thread: %d\n", i);
            return errno;
        }
    }

    return 0;
}
