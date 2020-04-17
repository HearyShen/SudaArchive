#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    // key_t ipc_key_player1, ipc_key_player2, ipc_key_judge;
    // int ipc_id_player1, ipc_id_player2, ipc_id_judge, ret;

    // printf("\nclosing all IPC!\n\n");

    // /* 获取player1的IPC信道 */
    // /* ftok() : 生成key */
    // ipc_key_player1 = ftok(".", "roshambo_player1");

    // /* msgget() : 获取（创建）IPC信道　*/
    // if((ipc_id_player1 = msgget(ipc_key_player1, IPC_CREAT|0770)) == -1) {
    //     perror("msgget error");
    //     exit(1);
    // }
    // printf("player1_id = %d\n", ipc_id_player1);

    // /* 获取player2的IPC信道 */
    // /* ftok() : 生成key */
    // ipc_key_player2 = ftok(".", "roshambo_player2");

    // /* msgget() : 获取（创建）IPC信道　*/
    // if((ipc_id_player2 = msgget(ipc_key_player2, IPC_CREAT|0770)) == -1) {
    //     perror("msgget error");
    //     exit(1);
    // }
    // printf("player2_id = %d\n", ipc_id_player2);

    // /* 获取judge的IPC信道*/
    // /* ftok() : 生成key */
    // ipc_key_judge = ftok(".", "roshambo_judge");

    // /* msgget() : 获取（创建）IPC信道　*/
    // if((ipc_id_judge = msgget(ipc_key_judge, IPC_CREAT|0770)) == -1) {
    //     perror("msgget error");
    //     exit(1);
    // }
    // printf("judge_id = %d\n", ipc_id_judge);

    msgctl(1409024, IPC_RMID, (struct msqid_ds *)0);
    msgctl(1441793, IPC_RMID, (struct msqid_ds *)0);
    msgctl(1474562, IPC_RMID, (struct msqid_ds *)0);
    // msgctl(851971, IPC_RMID, (struct msqid_ds *)0);
    // msgctl(884740, IPC_RMID, (struct msqid_ds *)0);
    //msgctl(163845, IPC_RMID, (struct msqid_ds *)0);
    
    
    
    
    system("ipcs -q");
}