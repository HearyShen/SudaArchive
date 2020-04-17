/* 
	impletement of cross-process communication
	type: System-V message queue
    1427405017
    沈家赟
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_TEXT 50     // max size of message text

struct msgbuf { // struct of message buffer
    long mtype; 
    char mtext[MAX_TEXT ]; 
};


int main(int argc,char *argv[])
{
    pid_t pid;

    size_t len;
    int type;
    struct msgbuf snd;
    struct msgbuf rcv;
    char buf[MAX_TEXT];
    key_t key;
    int mid,ret;

    /* ftok() */
    key = ftok(".", 'a');

    /* msgget() */
    if((mid = msgget(key, IPC_CREAT|0770)) == -1) {
        perror("msgget error");
        exit(1);
    }
    printf("%d\n", mid);
    printf("\nipcs -q after running msgget()：\n");
    system("ipcs -q");
    
    /* input the message for transmission */
    fputs("Please input (msgbuf.type):", stdout);
    setbuf(stdin, NULL);       // flush input
    scanf("%d", &type);
    snd.mtype = type;
    fputs("Please input (msgbuf.text):", stdout);
    setbuf(stdin, NULL);        // flush input
    fgets(buf, MAX_TEXT, stdin);

    /* magsnd() */
    memcpy(snd.mtext, buf, MAX_TEXT);
    ret = msgsnd(mid, (void *)&snd, MAX_TEXT, 0);
    if(ret == -1) {
        exit(3);
        perror("msgsnd error");
    }
    printf("\nipcs -q after running msgsnd()：\n");
    system("ipcs -q");

    /* msgrcv() : receive message in child process 
       msgctl() : remid the message in message queue */
    pid=fork();
    if(pid==0){ // fork() - child process
        ret = msgrcv(mid, (void *)&rcv, MAX_TEXT, 0, 0);
        if(ret == -1) {
            exit(3);
            perror("msgrcv error");
        }
        printf("\nmessage got by msgrcv():\ntype: %ld    data: %s\n", rcv.mtype, rcv.mtext);
    }
    else{       // fork() - parent process
        wait(NULL);
        printf("\nipcs -q after running msgrcv()：\n");
        system("ipcs -q");
        msgctl(mid, IPC_RMID, (struct msqid_ds *)0);
        printf("\nipcs -q after running msgctl()：\n");
        system("ipcs -q");
        exit(0);
    }

}