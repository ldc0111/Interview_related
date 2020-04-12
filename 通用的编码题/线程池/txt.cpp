/*************************************************************************
	> File Name: txt.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月19日 星期四 16时31分41秒
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
int func(T &&n) {
    cout << n << endl;
}


int main() {
    int x = 0;
    func(x);
    func(0);
    return 0;
}
