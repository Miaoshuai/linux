/*======================================================
    > File Name: libaio.cpp
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年01月12日 星期二 11时38分51秒
 =======================================================*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <linux/aio_abi.h>
#include <assert.h>
#include <asm-generic/unistd.h>


int main(void)
{
    aio_context_t ctx;
    memset(&ctx,0,sizeof(ctx));
    int ret = syscall(0,5,&ctx);
    //int ret = io_setup(10,&ctx);            //最大监听10个异步io
    printf("ret = %d\n",ret);
    assert(ret == 0);
    
    int fd = open("/home/shreck/Express_help/express_help.conf",O_RDONLY);

    struct iocb cbp[10];
    cbp[0].aio_lio_opcode = IOCB_CMD_PREAD;   //读操作码
    cbp[0].aio_fildes = fd;
    
    char buf[10240];    //用来保存读到的内容的用户缓冲区
    cbp[0].aio_buf = (unsigned long long)buf;

    cbp[0].aio_nbytes = 10240;
    cbp[0].aio_offset = 0;

    syscall(__NR_io_submit,ctx,1,cbp);

    struct io_event events;
    syscall(__NR_io_getevents,ctx,1,1,&events,NULL);

    struct iocb *p = (struct iocb *)&(events.obj);
    printf("%s\n",p->aio_buf);

       
    return 0;
}
