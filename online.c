#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#define MAX_LINE 1024

int parser_online (void) {
    int sockfd,val;
    char buffer[MAX_LINE];
    struct hostent *google_ent=NULL;
    struct sockaddr_in google_addr;

    sockfd = -1;

    if ((google_ent = gethostbyname("www.google.com")) != NULL) {
        printf("Getting host by name\n");
        if ((sockfd = socket(google_ent->h_addrtype,SOCK_STREAM,IPPROTO_TCP)) != -1) {
            val = 1;
            printf("Opened socket\n");
            if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR, (char *) &val, sizeof(val)) == 0 &&
                setsockopt(sockfd,IPPROTO_TCP,TCP_NODELAY, (char *) &val, sizeof(val)) == 0) {
                google_addr.sin_family = google_ent->h_addrtype;
                memcpy(&(google_addr.sin_addr), google_ent->h_addr, google_ent->h_length);
                google_addr.sin_port = htons(80);

                if (connect(sockfd,(struct sockaddr *) &google_addr,sizeof(google_addr)) == 0) {
                    printf("Connecting.....\n");
                    if (write(sockfd,"GET /index.html HTTP/1.1\r\n\r\n", 29) >= 28) {
                        printf("Writing on index.html\n");

                        if (shutdown(sockfd, SHUT_WR)) {
                            printf("Failed to shutdown sockfd\n");
                        }

                        if (read(sockfd, buffer, MAX_LINE) != -1) { // all right!
                            printf("Read from socket: %s\n", strerror(errno));
                            close(sockfd);
                            return 1;
                        } else {
                            printf("Read Error\n");
                        }
                    } else {
                        printf("Write Error\n");
                    }
                } else {
                    printf("Connect Error\n");
                }
            } else {
                printf("setsockopt() Error\n");
            }
        } else {
            printf("socket() Error\n");
        }
    } else {
        printf("cannot resolve IP for mom Google."); // this is is the most common error.
    }

    if (sockfd != -1) {
        printf("Socket: %s\n", strerror(errno));
        close(sockfd);
    }
    return 0; // no internet
}

int main () {
    if (parser_online()) {
        printf("Internet available\n");
    } else {
        printf("No Internet available\n");
    }
    return 0;
}
