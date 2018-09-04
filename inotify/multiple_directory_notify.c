#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <limits.h>

#define MAX_EVENTS 1024 /*Max. number of events to process at one go*/
#define LEN_NAME 16 /*Assuming that the length of the filename won't exceed 16 bytes*/
#define EVENT_SIZE  ( sizeof (struct inotify_event) ) /*size of one event*/
#define BUF_LEN     ( MAX_EVENTS * ( EVENT_SIZE + LEN_NAME )) /*buffer to store the data of events*/

int main( int argc, char **argv ) {
    int length, len[3],i = 0, wd[3];
    int fd;
    char buffer[BUF_LEN];
<<<<<<< HEAD
    printf("SIZE OF struct inotify_event: %zu\n", sizeof(struct inotify_event));
=======

>>>>>>> f9c70987da9ff6fae17a326f898d95c6c8241a18
    /* Initialize Inotify*/
    fd= inotify_init();
    if (fd < 0) {
        perror( "Couldn't initialize inotify");
    }

    /* add watch to starting directory */
    wd[0] = inotify_add_watch(fd, argv[1], IN_CREATE | IN_MODIFY | IN_DELETE);
    if (wd[0] == -1) {
        printf("Couldn't add watch to %s\n",argv[1]);
    } else {
        printf("Watching:: %s\n",argv[1]);
    }

    wd[1] = inotify_add_watch(fd, argv[2], IN_CREATE | IN_MODIFY | IN_DELETE);
    if (wd[1] == -1) {
        printf("Couldn't add watch to %s\n",argv[2]);
    } else {
        printf("Watching:: %s\n",argv[2]);
    }

    wd[2] = inotify_add_watch(fd, argv[3], IN_CREATE | IN_MODIFY | IN_DELETE);
    if (wd[2] == -1) {
        printf("Couldn't add watch to %s\n",argv[3]);
    } else {
        printf("Watching:: %s\n",argv[3]);
    }

    /* do it forever*/
    while(1)
    {
        i = 0;
        struct inotify_event *event1, *event2, *event3;
        length = read(fd, buffer, BUF_LEN);
        if ( length < 0 ) {
            perror( "read\n" );
        }

<<<<<<< HEAD
        event1 = ( struct inotify_event * ) &buffer[i];
=======
        event1 = ( struct inotify_event * ) &buffer[0];
>>>>>>> f9c70987da9ff6fae17a326f898d95c6c8241a18
        event2 = ( struct inotify_event * ) &buffer[length];
        event3 = ( struct inotify_event * ) &buffer[event2->len + length];

        //while ( event2 < event1 ) {
            if ( event1->len ) {
                if ( event1->mask & IN_CREATE) {
                    if (event1->mask & IN_ISDIR)
                        printf( "The directory %s was Created.\n", event1->name );
                    else
                        printf( "The file %s was Created with WD %d\n", event1->name, event1->wd );
                }

                if ( event1->mask & IN_MODIFY) {
                    if (event1->mask & IN_ISDIR)
                        printf( "The directory %s was modified.\n", event1->name );
                    else
                        printf( "The file %s was modified with WD %d\n", event1->name, event1->wd );
                }

                if ( event1->mask & IN_DELETE) {
                    if (event1->mask & IN_ISDIR)
                        printf( "The directory %s was deleted.\n", event1->name );
                    else
                        printf( "The file %s was deleted with WD %d\n", event1->name, event1->wd );
                }

                i += EVENT_SIZE + event1->len;
            }
            if ( event2->len ) {
                if ( event2->mask & IN_CREATE) {
                    if (event2->mask & IN_ISDIR)
                        printf( "The directory %s was Created.\n", event2->name );
                    else
                        printf( "The file %s was Created with WD %d\n", event2->name, event2->wd );
                }

                if ( event2->mask & IN_MODIFY) {
                    if (event2->mask & IN_ISDIR)
                        printf( "The directory %s was modified.\n", event2->name );
                    else
                        printf( "The file %s was modified with WD %d\n", event2->name, event2->wd );
                }

                if ( event2->mask & IN_DELETE) {
                    if (event2->mask & IN_ISDIR)
                        printf( "The directory %s was deleted.\n", event2->name );
                    else
                        printf( "The file %s was deleted with WD %d\n", event2->name, event2->wd );
                }

                i += EVENT_SIZE + event2->len;
        }
            if ( event3->len ) {
                if ( event3->mask & IN_CREATE) {
                    if (event3->mask & IN_ISDIR)
                        printf( "The directory %s was Created.\n", event3->name );
                    else
                        printf( "The file %s was Created with WD %d\n", event3->name, event3->wd );
                }

                if ( event3->mask & IN_MODIFY) {
                    if (event3->mask & IN_ISDIR)
                        printf( "The directory %s was modified.\n", event3->name );
                    else
                        printf( "The file %s was modified with WD %d\n", event3->name, event3->wd );
                }

                if ( event3->mask & IN_DELETE) {
                    if (event3->mask & IN_ISDIR)
                        printf( "The directory %s was deleted.\n", event3->name );
                    else
                        printf( "The file %s was deleted with WD %d\n", event3->name, event3->wd );
                }

                i += EVENT_SIZE + event3->len;
            }
<<<<<<< HEAD
            bzero(buffer, BUF_LEN);
=======
>>>>>>> f9c70987da9ff6fae17a326f898d95c6c8241a18
    }

    /* Clean up*/
    inotify_rm_watch(fd, wd[0]);
    inotify_rm_watch(fd, wd[1]);
    inotify_rm_watch(fd, wd[2]);
    close(fd);

    return 0;
}
