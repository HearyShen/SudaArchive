/* 
    impletement of cross-process communication
    type: System-V message queue
    1427405017
    沈家赟
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_TEXT 40     // max size of message text

const char type[3][MAX_TEXT] = {"石头", "剪刀", "布"};

struct msgbuf { // struct of message buffer
    long mtype; 
    char mtext[MAX_TEXT]; 
};

int main(int argc,char *argv[])
{
    printf("石头剪刀布游戏 - roshambo_player1\n");
    key_t ipc_key_player, ipc_key_judge;
    int ipc_id_player, ipc_id_judge, random_idx, ret;
    char msg_buf[MAX_TEXT];
    struct msgbuf snd_msg, rcv_msg;

    /* 获取player1的IPC信道 */
    /* ftok() : 生成key */
    ipc_key_player = ftok(".", 1);

    /* msgget() : 获取（创建）IPC信道　*/
    if((ipc_id_player = msgget(ipc_key_player, IPC_CREAT|0770)) == -1) {
        perror("msgget error");
        exit(1);
    }

    /* 获取judge的IPC信道*/
    /* ftok() : 生成key */
    ipc_key_judge = ftok(".", 0);

    /* msgget() : 获取（创建）IPC信道　*/
    if((ipc_id_judge = msgget(ipc_key_judge, IPC_CREAT|0770)) == -1) {
        perror("msgget error");
        exit(1);
    }

    printf("player1 ipc_id = %d\n", ipc_id_player);
    srand(time(0));
    /* 主循环：各玩家1oo次出招 */
    for(int i=1; i<=100; i++)
    {
        /* 出招：set msg_type & msg_buf */
        snd_msg.mtype = i;      // 玩家id, default msg type(player-1)
        // srand(time(0));
        random_idx = rand()%3;  // idx = 0~2
        strcpy(msg_buf, type[random_idx]);   // 玩家出招, set a random type

        /* msgsnd() */
        memcpy(snd_msg.mtext, msg_buf, MAX_TEXT);
        ret = msgsnd(ipc_id_player, (void *)&snd_msg, MAX_TEXT, 0);
        if(ret == -1) {
            exit(3);
            perror("msgsnd error\n");
        }
        printf("%d - player1: %s\n", i, snd_msg.mtext);

        /* 辅循环：循环等待直到当前结果得出，再发送下一个消息 */
        while(1)
        {
            /* msgrcv() */
            ret = msgrcv(ipc_id_judge, (void *)&rcv_msg, MAX_TEXT, 0, 0);
            if(ret == -1) {
                usleep(20000);    // sleep 20ms
            }
            else{
                if(rcv_msg.mtype != 1){     // 取错了，还回去，继续循环等待
                    ret = msgsnd(ipc_id_judge, (void *)&rcv_msg, MAX_TEXT, 0);
                    if(ret == -1) {
                        exit(3);
                        perror("msgsnd error\n");
                    }
                }
                else{   // 取对了，则显示结果，并跳出辅循环，发送下一条消息
                    printf("%d - Judge Result: %s\n", i, rcv_msg.mtext);
                    break;
                }
            }
        }
    }
}