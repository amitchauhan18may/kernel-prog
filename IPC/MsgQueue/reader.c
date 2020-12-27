#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg {
    long msg_type;
//    int age;
//    int salary;
    char name[100];
};

int main () {

    key_t key = ftok("abc", 12);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msg rcv_msg;
    msgrcv(msgid, &rcv_msg, sizeof(rcv_msg), 1, 0);
    printf("data received: %s\n", rcv_msg.name);

    return 0;
}
