/*************************************************************************
	> File Name: logger.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 20时26分51秒
 ************************************************************************/

#include<iostream>
#include "./2.2.mythreadpool.h"
#include "./logger.h"
#include <unistd.h>
using namespace std;

void func1(){
    cout << "1" << "2" << "3" << "4" << '5' << endl;
}
void func2(){
    LOG_INFO << "info: " << "1" << "2" << "3" << "4" << '5';
    LOG_DEBUG << "DEBUG: " << "1" << "2" << "3" << "4" << '5';
    LOG_WARN << "WARN: " << "1" << "2" << "3" << "4" << '5';
    LOG_ERROR << "ERROR: " << "1" << "2" << "3" << "4" << '5';
}

int main() {
    haizei::thread_pool tp(8);
    tp.start();
    for (int i = 1; i <= 10; i++) {
        tp.add_one_task(func1);
        sleep(1);
    }
    tp.stop();
    sleep(2);

    LOG_SET(10);
    tp.start();
    for (int i = 1; i <= 10; i++) {
        tp.add_one_task(func2);
        sleep(1);
    }
    tp.stop();
    sleep(2);
    return 0;
}
