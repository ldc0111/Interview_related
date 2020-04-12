/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月19日 星期四 15时20分09秒
 ************************************************************************/


#include <iostream>
#include "ThreadPool.h"
#include <unistd.h>
void func()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"worker thread ID:"<<std::this_thread::get_id()<<std::endl;
}

void func2(int x){
    std::cout << x << std::endl;
    std::cout << "worker thread ID:" << std::this_thread::get_id() << std::endl;
}

int main()
{
    int c = 32;
    ThreadPool pool(4);
    while(1)
    {
        pool.enqueue(func2,c);
        pool.enqueue(func);
        sleep(2);
    }

}

