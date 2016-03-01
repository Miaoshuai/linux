/*======================================================
    > File Name: signal.c
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月01日 星期二 20时42分49秒
 =======================================================*/
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch(int sig)
{
    printf("got signal\n");
    signal(SIGINT,SIG_DFL);
}

int main(void)
{
    signal(SIGINT,ouch);

    while(1)
    {
        printf("hello,world\n");
        sleep(1);
    }
    return 0;
}

