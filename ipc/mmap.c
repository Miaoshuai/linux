/*======================================================
    > File Name: mmap.c
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年04月10日 星期日 10时14分47秒
 =======================================================*/
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <string.h>

int main(void)
{
    char buffer[] = "Hello,world\n";
    void *addr;
    int fd = open("file.txt",O_RDONLY | O_WRONLY);
    assert(fd > 0);

    addr = mmap(NULL,50,PROT_READ | PROT_WRITE,MAP_PRIVATE,fd,0);
    if(addr == MAP_FAILED)
    {
        ;
    }
    strcpy(addr,buffer);
    munmap(addr,50);
    close(fd);
    return 0;
}
