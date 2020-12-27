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

    struct msg send_msg = {
        msg_type: 1,
//        age: 15;
//        slary: 18000;
        name: "abcddddddddd"
    };

    msgsnd(msgid, &send_msg, sizeof(send_msg), 0);

    printf("data sent: %s\n", send_msg.name);

    return 0;
}
