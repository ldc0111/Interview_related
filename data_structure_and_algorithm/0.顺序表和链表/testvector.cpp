/*************************************************************************
	> File Name: testvector.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月01日 星期日 11时15分19秒
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;



int main() {
    vector<int> arr(5);
    cout << arr.size() << endl;
    arr.insert(arr.begin() + 3,3);
    cout << arr.size() << endl;
    arr[8] = 4;
    cout << arr.size() << endl;
    cout << arr[7] << endl;
    return 0;
}
