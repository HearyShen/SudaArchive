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

#define MAX_TEXT 20     // max size of message text

const char type[3][MAX_TEXT] = {"石头", "剪刀", "布"};

struct msgbuf { // struct of message buffer
    long mtype; 
    char mtext[MAX_TEXT]; 
};

int main(int argc,char *argv[])
{
    printf("石头剪刀布游戏 - roshambo_judge\n");
    key_t ipc_key_player1, ipc_key_player2, ipc_key_judge;
    int ipc_id_player1, ipc_id_player2, ipc_id_judge, ret;
    char msg_buf[MAX_TEXT], judgment[MAX_TEXT];
    struct msgbuf player1_msg, player2_msg, judge_msg;


    /* 获取player1的IPC信道 */
    /* ftok() : 生成key */
    ipc_key_player1 = ftok(".", 1);

    /* msgget() : 获取（创建）IPC信道　*/
    if((ipc_id_player1 = msgget(ipc_key_player1, IPC_CREAT|0770)) == -1) {
        perror("msgget error");
        exit(1);
    }
    printf("player1_id = %d\n", ipc_id_player1);

    /* 获取player2的IPC信道 */
    /* ftok() : 生成key */
    ipc_key_player2 = ftok(".", 2);

    /* msgget() : 获取（创建）IPC信道　*/
    if((ipc_id_player2 = msgget(ipc_key_player2, IPC_CREAT|0770)) == -1) {
        perror("msgget error");
        exit(1);
    }
    printf("player2_id = %d\n", ipc_id_player2);

    /* 获取judge的IPC信道*/
    /* ftok() : 生成key */
    ipc_key_judge = ftok(".", 0);

    /* msgget() : 获取（创建）IPC信道　*/
    if((ipc_id_judge = msgget(ipc_key_judge, IPC_CREAT|0770)) == -1) {
        perror("msgget error");
        exit(1);
    }
    printf("judge_id = %d\n", ipc_id_judge);

    /* 主循环：裁判100次判定结果 */
    for(int i=1; i<=100; i++)
    {
        /* 辅循环：循环等待直到player1发送完成 */
        while(1)
        {
            /* msgrcv() */
            ret = msgrcv(ipc_id_player1, (void *)&player1_msg, MAX_TEXT, 0, 0);
            if(ret == -1) {
                usleep(20);    // sleep 20ms
            }
            else{
                break;
            }
        }

        /* 辅循环：循环等待直到player2发送完成　*/
        while(1)
        {
            /* msgrcv() */
            ret = msgrcv(ipc_id_player2, (void *)&player2_msg, MAX_TEXT, 0, 0);
            if(ret == -1) {
                usleep(20);    // sleep 20ms
            }
            else{
                break;
            }
        }


        /* 回执1：set msg_type & msg_buf */
        judge_msg.mtype = 1;      // 设1
        strcpy(msg_buf, player1_msg.mtext);   // temp
        /* msgsnd() */
        memcpy(judge_msg.mtext, msg_buf, MAX_TEXT);
        ret = msgsnd(ipc_id_judge, (void *)&judge_msg, MAX_TEXT, 0);
        if(ret == -1) {
            exit(3);
            perror("msgsnd error\n");
        }

        /* 回执1：set msg_type & msg_buf */
        judge_msg.mtype = 2;      // 设2
        strcpy(msg_buf, player2_msg.mtext);   // temp
        /* msgsnd() */
        memcpy(judge_msg.mtext, msg_buf, MAX_TEXT);
        ret = msgsnd(ipc_id_judge, (void *)&judge_msg, MAX_TEXT, 0);
        if(ret == -1) {
            exit(3);
            perror("msgsnd error\n");
        }


        if(strcmp(player1_msg.mtext, type[0]) == 0)
        {
            if(strcmp(player2_msg.mtext, type[0]) == 0)
            {
                strcpy(judgment, "平局");
            }
            else if(strcmp(player2_msg.mtext, type[1]) == 0)
            {
                strcpy(judgment, "Player1胜");
            }
            else if(strcmp(player2_msg.mtext, type[2]) == 0)
            {
                strcpy(judgment, "Player2胜");
            }
            else
            {
                strcpy(judgment, "Player2信息出错");
            }
        }
        else if(strcmp(player1_msg.mtext, type[1]) == 0)
        {
            if(strcmp(player2_msg.mtext, type[0]) == 0)
            {
                strcpy(judgment, "Player2胜");
            }
            else if(strcmp(player2_msg.mtext, type[1]) == 0)
            {
                strcpy(judgment, "平局");
            }
            else if(strcmp(player2_msg.mtext, type[2]) == 0)
            {
                strcpy(judgment, "Player1胜");
            }
            else
            {
                strcpy(judgment, "Player2信息出错");
            }
        }
        else if(strcmp(player1_msg.mtext, type[2]) == 0)
        {
            if(strcmp(player2_msg.mtext, type[0]) == 0)
            {
                strcpy(judgment, "Player1胜");
            }
            else if(strcmp(player2_msg.mtext, type[1]) == 0)
            {
                strcpy(judgment, "Player2胜");
            }
            else if(strcmp(player2_msg.mtext, type[2]) == 0)
            {
                strcpy(judgment, "平局");
            }
            else
            {
                strcpy(judgment, "Player2信息出错");
            }
        }
        else
        {
            strcpy(judgment, "Player1信息出错");
        }


        printf("%d - P1: %s,\t P2: %s,\t Judge: %s\n", i, player1_msg.mtext, player2_msg.mtext, judgment);
    }

    sleep(1);
    printf("\n\n判定完成，此时ipcs -q如下（3条消息队列无数据）：\n");
    system("ipcs -q");
    msgctl(ipc_id_judge, IPC_RMID, (struct msqid_ds *)0);
    msgctl(ipc_id_player1, IPC_RMID, (struct msqid_ds *)0);
    msgctl(ipc_id_player2, IPC_RMID, (struct msqid_ds *)0);
    printf("\n\n关闭消息队列完成，此时ipcs -q如下（3条消息队列已释放）：\n");
    system("ipcs -q");
}