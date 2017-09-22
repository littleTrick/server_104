#include <stdio.h>
#include <pthread.h>
#include "data_cache.h"
#include "thread_101.h"
#include "thread_104.h"
#include "thread_101_slave.h"

using namespace std;

int main(int /*argc*/, char ** /*argv*/)
{
    DatabaseInit();//数据缓存区初始化

    pthread_t tid_104_slave;
    if (pthread_create(&tid_104_slave, NULL, thread_main_104, NULL))
    {
        perror("pthread_create");
        return -1;
    }

    pthread_t tid_101_master;
    if (pthread_create(&tid_101_master, NULL, thread_main_101, NULL))
    {
        perror("pthread_create");
        return -1;
    }

    pthread_t tid_101_slave;
    if(pthread_create(&tid_101_slave,NULL,thread_main_101_slave,NULL))
    {
        perror("pthread_create");
        return -1;
    }

    pthread_join(tid_104_slave, NULL);//阻塞至线程结束
    pthread_join(tid_101_master, NULL);
    pthread_join(tid_101_slave,NULL);

    return 0;
}

