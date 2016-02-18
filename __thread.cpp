/*======================================================
    > File Name: __thread.cpp
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年02月18日 星期四 13时07分32秒
 =======================================================*/
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <thread>

__thread int sum = 5;

void func(void)
{
    std::cout<<++sum<<std::endl;
}

int main(void)
{
    std::thread t1(func);
    std::thread t2(func);
    t1.join();
    t2.join();    
    return 0;
}
