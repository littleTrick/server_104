#include <stdio.h>
#include <pthread.h>
#include "thread_101.h"
#include "thread_104.h"

using namespace std;

int main(int /*argc*/, char ** /*argv*/)
{
    pthread_t tid_104;
    if (pthread_create(&tid_104, NULL, thread_main_104, NULL))
    {
        perror("pthread_create");
        return -1;
    }

    pthread_t tid_101;
    if (pthread_create(&tid_101, NULL, thread_main_101, NULL))
    {
        perror("pthread_create");
        return -1;
    }

    pthread_join(tid_104, NULL);//阻塞至线程结束
    pthread_join(tid_101, NULL);

    return 0;
}

