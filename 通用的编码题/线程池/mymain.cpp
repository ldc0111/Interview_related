/*************************************************************************
	> File Name: mymain.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月21日 星期六 11时04分21秒
 ************************************************************************/

#include<iostream>
#include "2.mythreadpool.h"
using namespace std;
using namespace threadpool;
int func(int n) {
    cout << "task : "<< n << endl;
}

int main() {
    thread_pool tp(8);
    tp.start();
    for (int i = 0; i < 1000; i++) {
        cout << "add : "<< i << endl;
        tp.add(func,i);
    }
    tp.stop();
    return 0;

}

