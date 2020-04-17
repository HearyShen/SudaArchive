#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
// // 根据关键字生成标识符。
// key_t ftok(const char *pathname, int proj_id);
// // 打开或创建消息队列
// int msgget(ket_t key, int msgflg);
// // 向队列传递消息
// int msgsnd(int msqid, struct msgbuf *msgp, size_t msgsz, int msgflg);
// // 从队列中获得消息
// int msgrcv(int msqid, struct msgbuf *msgq, size_t msgsz, long msgtype, int msgflg);
// // 消息队列的属性控制
// int msgctl(int msgqid, int cmd, struct msqid_ds *buf);

struct msgbuf
{
    long type;
    char data[100];
};

int main()
{
    int mqid;
    key_t key;


    if((key = ftok(".", 'a')) == -1)
    {
        perror("ftok() error");
        exit(-1);
    }

    msgctl(mqid,IPC_RMID,NULL);
    exit(0);
    return 0;
}