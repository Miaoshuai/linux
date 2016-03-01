/*======================================================
    > File Name: exit.c
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月01日 星期二 20时09分33秒
 =======================================================*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int *p = NULL;

int main(void)
{
    int pid = fork();

    switch(pid)
    {
        case 0:
            sleep(1);
            printf("%d\n",*p);
            printf("挂了\n");
            break;
        case -1:
            printf("创建线程失败!\n");break;
        default:
            sleep(1000);
    }

    return 0;
}


