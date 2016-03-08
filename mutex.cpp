/*======================================================
    > File Name: mutex.cpp
    > Author: MiaoShuai
    > E-mail:  
    > Other :  
    > Created Time: 2016年03月08日 星期二 08时03分06秒
 =======================================================*/

#include<iostream>
#include<vector>
#include<string>
#include<mutex>
#include<thread>

std::mutex mutex1;
std::mutex mutex2;

void fun(void)
{
    while(true)
    {
        std::lock_guard<std::mutex> guard1(mutex1);
        std::lock_guard<std::mutex> guard2(mutex2);
        std::cout<<"哈哈"<<std::endl;
    }
}

void fun2(void)
{
    while(true)
    {
        std::lock_guard<std::mutex> guard1(mutex2);
        std::lock_guard<std::mutex> guard2(mutex1);
        std::cout<<"啊啊"<<std::endl;
    }
}

int main(int argc,char **argv)
{
  std::thread t1(fun);
  std::thread t2(fun2);
  t1.join();
  t2.join();

  return 0;
}
