/*======================================================
    > File Name: cache2.c
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月07日 星期一 23时51分33秒
 =======================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int num_0;
int num_1;

void *thread_0(void *args)
{
        int i = 100000000;
        while (i--) {
                num_0++;
        }
}

void *thread_1(void *args)
{
        int i = 100000000;
        while (i--) {
                num_1++;
        }
}

int main(int argc, char *argv[])
{
        pthread_t thread[2];

        pthread_create(&thread[0], NULL, thread_0, NULL);
        pthread_join(thread[0],NULL);
        pthread_create(&thread[1], NULL, thread_1, NULL);

        //pthread_join(thread[0], NULL);
        pthread_join(thread[1], NULL);

        return EXIT_SUCCESS;
}
