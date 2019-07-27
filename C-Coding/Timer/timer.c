#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h> 
#include "stopwatch_timer.h"

static bool timer = true;
pthread_t thread_id;

/* prototypes */
void* g_start_timer(void *secs);

static clock_t _current_time = 0;

/* create the thread */
void start_timer(int seconds)
{
    int rc = 0;

    rc = pthread_create(&thread_id, NULL, g_start_timer, (void*) seconds);

    if(rc)
    {
        printf("=== Error Creating thread\n");
    } 
}

/* start the timing in another thread */
void* g_start_timer(void *secs)
{
    printf("Starting thread\n");
    int seconds = *((int *) secs);
    printf("g_start_timer: %d\n", (int) seconds);

    _current_time = clock() + seconds * CLOCKS_PER_SEC;

    /* loop until the 10 seconds has reached */
    while(clock() < _current_time){}
    timer = false;
    printf("Timer expired\n");
    pthread_exit(NULL);
}

/* get the current time of work */
int current_time()
{
    return (int) _current_time / CLOCKS_PER_SEC;
}

int main()
{
    printf("Start your timers\n");

    /* start the time and run for 10 seconds */
    start_timer(5);
    timer = true;
    int i = 0;
    /* do some work */
    while (timer == true) {
        sleep(0.25);
    }
    //for(i = 0; i < 100000; i++){}

    /* Check and display current time */
    printf("Curent time: %d\n", current_time());

    pthread_exit(NULL);

    return 0;
}
