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

/**
* int getTypeIndex(char type_str[])
* 获取type对应的index(0~2)
*/
int getTypeIndex(char type_str[]);

int main(int argc,char *argv[])
{
    printf("石头剪刀布游戏 - roshambo_judge\n");
    key_t ipc_key_player1, ipc_key_player2, ipc_key_judge;
    int ipc_id_player1, ipc_id_player2, ipc_id_judge, ret;
    char msg_buf[MAX_TEXT], judgment[MAX_TEXT];
    struct msgbuf player1_msg, player2_msg, judge_msg;
    int has_player1_msg, has_player2_msg;
    int waiting_player, wait_count;
    int player1_type_index, player2_type_index;


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
        has_player1_msg = 0;
        has_player2_msg = 0;
        waiting_player = 0;    // 等待选手(消息先到达)，序号初始为0
        wait_count = 0;        // 等待次数
        
        while(!has_player1_msg || !has_player2_msg)
        {

            if(!has_player1_msg)    //　若无player1的消息，则尝试接收
            {
                /* msgrcv() */
                ret = msgrcv(ipc_id_player1, (void *)&player1_msg, MAX_TEXT, 0, IPC_NOWAIT);
                if(ret == -1) {
                    has_player1_msg = 0;
                }
                else{
                    if(player1_msg.mtype == i)  // 取到的消息应与比赛轮数对应（避免有超时消息进入下轮）
                    {
                        has_player1_msg = 1;
                        if(waiting_player == 0)     // 若player1先到达
                        {
                            waiting_player = 1;
                        }
                    }
                    else
                    {
                        has_player1_msg = 0;
                    }
                }
            }

            if(!has_player2_msg)    // 若无player2的消息，则尝试接收
            {
                /* msgrcv() */
                ret = msgrcv(ipc_id_player2, (void *)&player2_msg, MAX_TEXT, 0, IPC_NOWAIT);
                if(ret == -1) {
                    has_player2_msg = 0;
                }
                else{
                    if(player2_msg.mtype == i)  // 取到的消息应与比赛轮数对应（避免有超时消息进入下轮）
                    {
                        has_player2_msg = 1;
                        if(waiting_player == 0)     //　若player2先到达
                        {
                            waiting_player = 2;
                        }
                    }
                    else
                    {
                        has_player2_msg = 0;
                    }
                }
            }

            if(!has_player1_msg || !has_player2_msg)    // 若消息没到齐
            {
                usleep(20000);    // sleep 20ms usleep(20000us)
                if( waiting_player!= 0 )     // 如果有人先到达，则开始计算循环等待次数(wait_count)
                {
                    wait_count++;
                    // printf("wait_count = %d\n", wait_count);
                }
                
                /* 超时判定 */
                if(wait_count > 500)    // 500*20ms = 10s
                {
                    if(waiting_player == 1)
                    {
                        strcpy(judgment, "Player2超时,Player1胜");
                        strcpy(player2_msg.mtext, "超时");
                    }
                    else if(waiting_player == 2)
                    {
                        strcpy(judgment, "Player1超时,Player2胜");
                        strcpy(player1_msg.mtext, "超时");
                    }
                    // printf("超时错误，缺少连线玩家！　%s\n", judgment);
                    break;
                }
            }
        }

        if(wait_count <= 500 )  // 未超时
        {
            player1_type_index = getTypeIndex(player1_msg.mtext);
            player2_type_index = getTypeIndex(player2_msg.mtext);

            if(player1_type_index!=-1 && player2_type_index!=-1)    //　正常情况
            {
                if(player1_type_index == player2_type_index)
                {
                    strcpy(judgment, "平局");
                }
                else if( (player1_type_index+1)%3 == player2_type_index )
                {
                    strcpy(judgment, "Player1胜");
                }
                else
                {
                    strcpy(judgment, "Player2胜");
                }
            }
            else    // 异常处理
            {
                if(player1_type_index==-1 && player2_type_index==-1)
                {
                    strcpy(judgment, "Player1,2消息均有误");
                }
                else if(player1_type_index == -1)
                {
                    strcpy(judgment, "Player1消息有误");
                }
                else if(player1_type_index == -1)
                {
                    strcpy(judgment, "Player1消息有误");
                }
            }
        }

        /* 回执1：set msg_type & msg_buf */
        judge_msg.mtype = 1;      // 设1
        strcpy(msg_buf, judgment);   // 返回结果
        /* msgsnd() */
        memcpy(judge_msg.mtext, msg_buf, MAX_TEXT);
        ret = msgsnd(ipc_id_judge, (void *)&judge_msg, MAX_TEXT, 0);
        if(ret == -1) {
            exit(3);
            perror("msgsnd error\n");
        }

        /* 回执1：set msg_type & msg_buf */
        judge_msg.mtype = 2;      // 设2
        // strcpy(msg_buf, judgment);   // 返回结果
        /* msgsnd() */
        memcpy(judge_msg.mtext, msg_buf, MAX_TEXT);
        ret = msgsnd(ipc_id_judge, (void *)&judge_msg, MAX_TEXT, 0);
        if(ret == -1) {
            exit(3);
            perror("msgsnd error\n");
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

/**
* int getTypeIndex(char type_str[])
* 获取type对应的index(0~2)
*/
int getTypeIndex(char type_str[])
{
    int i;
    for(i=0; i<3; i++)
    {
        if(strcmp(type_str, type[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}