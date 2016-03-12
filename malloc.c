/*======================================================
    > File Name: malloc.c
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月12日 星期六 18时44分32秒
 =======================================================*/
#include <stdio.h>
#include <stdio.h>

int main(void)
{
    int * p1 = (int *)malloc(8);
    int  *p2 = (int *)malloc(8);
    printf("%p   %p\n",p1,p2);
    *p2 = 5;
    *++p2 = 6;
    p1 = p1 + 9;
    printf("p1 = %d\n  p = %p\n",*p1,p1);
    return 0;
}

