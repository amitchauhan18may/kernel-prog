/* An exit value greater than 255 returns an exit code modulo 256.
 * For example, exit 9999 gives an exit code of 15 i.e. (9999 % 256 = 15).
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        exit(9999);
    }

    int status;

    waitpid(pid, &status, 0);

    if ( WIFEXITED(status) ) {
        int exit_status = WEXITSTATUS(status);
        printf("Exit status: %d\n", exit_status);
    }

    return 0;
}

