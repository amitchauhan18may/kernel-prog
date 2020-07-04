#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SHM_MEM     1024

int main (int argc, char argv[]) {

    char *sh_memory = NULL;
    char *shm       = NULL;
    int ret         = -1;
    int shm_id      = -1;
    key_t key       = -1;
    int len         = 0;

    shm_id = shmget(0x1234, SHM_MEM, 0666 | IPC_CREAT);
    if (-1 == shm_id) {
        printf("Failed to get shared-memory id: %s\n", strerror(errno));
        return errno;
    }

    sh_memory = (char *)shmat(shm_id, NULL, 0);
    if (sh_memory == (void *) -1) {
        printf("Failed to attach memory: %s\n", strerror(errno));
        return errno;
    }

    strncpy(sh_memory, "ABC", 3);
    sh_memory[3] = '\0';
    shm = sh_memory;
    printf("Data: %s\n", sh_memory);

    while (*shm != '*') {
        printf("Waiting...\n");
        sleep(1);
    }

    return 0;

}
