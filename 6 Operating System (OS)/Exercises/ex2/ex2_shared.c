#include <sys/shm.h>
//创建共享内存
int shmget(key_t key, size_t size, int shmflg);
//把共享内存连接到当前进程的地址空间
void *shmat(int shm_id, const void *shm_addr, int shmflg);
//将共享内存从当前进程中分离
int shmdt(const void *shmaddr);
//控制共享内存
int shmctl(int shm_id, int command, struct shmid_ds *buf);
int main()
{
    int running = 1;              //程序是否继续运行的标志
    void *shm = NULL;             //分配的共享内存的原始首地址
    struct shared_use_st *shared; //指向shm
    int shmid;                    //共享内存标识符
    //创建共享内存
    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
    if (shmid == ‐1)
    {
        fprintf(stderr, "shmget failed\n");
        exit(EXIT_FAILURE);
    }
    //将共享内存连接到当前进程的地址空间
    shm = shmat(shmid, 0, 0);
    if (shm == (void *)‐1)
    {
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
    }
    printf("\nMemory attached at %X\n", (int)shm); //设置共享内存
    shared = (struct shared_use_st *)shm;
    shared‐> written = 0;
    while (running) //读取共享内存中的数据
    {
        //没有进程向共享内存定数据有数据可读取
        if (shared‐> written != 0)
        {
            printf("You wrote: %s", shared‐> text);
            sleep(rand() % 3);
            //读取完数据,设置written使共享内存段
            可写
            shared‐> written = 0;
            //输入了end,退出循环(程序)
            if (strncmp(shared‐> text, "end", 3) == 0)
                running = 0;
        }
        else //有其他进程在写数据,不能读取数据
            sleep(1);
    }
    //把共享内存从当前进程中分离
    if (shmdt(shm) == ‐1)
    {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }
    //删除共享内存
    if (shmctl(shmid, IPC_RMID, 0) == ‐1)
    {
        fprintf(stderr, "shmctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}