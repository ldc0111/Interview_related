/*************************************************************************
	> File Name: 1.2.vector.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 17时33分03秒
 ************************************************************************/

#include<iostream>
using namespace std;
template<typename T>
class vector{
    private:
    int size = 0;
    T * data = nullptr;
    bool expand();
    public:
    vector()=default;
    vector(const int n);
    vector(const vector & arr);
    vector(const vector && arr);
    vector & operator=(const vector &arr);
    vector & operator=(const vector &&arr);
    T & operator[](const int ind);
    const T & operator[](const int ind) const;
    ~vector();

    bool insert(const int ind,const T & x);
    bool erase(const int ind);
};
template<typename T>
vector<T>::vector(const int n):size(n){
    this->data = new T[n];
}
template<typename T>
vector<T>::vector(const vector & arr){
    this->size = arr.size;
    this->data = new T[this->size];
    for (int i = 0; i < this->size; i++) {
        this->data[i] = arr.data[i];
    }
}
template<typename T>
vector<T>::vector(const vector && arr){
    this->size = arr.size;
    this->data = arr.data;
    arr.size = 0;
    arr.data = nullptr;
}

template<typename T>
vector<T>& vector<T>::operator=(const vector<T> &arr){
    this->size = arr.size;
    this->data = new T[this->size];
    for (int i = 0; i < this->size; i++) {
        this->data[i] = arr.data[i];
    }
}

template<typename T>
vector<T> & vector<T>::operator=(const vector &&arr){
    this->size = arr.size;
    this->data = arr.data;
    arr.size = 0;
    arr.data = nullptr;
}
template<typename T>
T & vector<T>::operator[](const int ind){
    return this->data[ind];
}
template<typename T>
const T & vector<T>::operator[](const int ind) const{
    return this->data[ind];
}
template<typename T>
vector<T>::~vector(){
    delete[] this->data;
}

template<typename T>
bool vector<T>::expand(){
    this->size = this->size << 1;
    T * temp = this->data;
    this->data = new T[this->size];
    for (int i = 0; i < this->size; i++) {
        this->data[i] = temp[i];
    }
}
template<typename T>
bool vector<T>::insert(const int ind,const T & x){
    if (ind < 0 || ind > this->size) return false;
    for (int i = this->size; i > ind; i--) {
        this->data[i] = this->data[i - 1];
    }
    this->size += 1;
    return true;
}
template<typename T>
bool vector<T>::erase(const int ind){
    if (ind < 0 || ind >= this->size) return false;
    if (this->size < 1) return false;
    for (int i = ind; i < this->size;i++) {
        this->data[i] = this->data[i + 1];
    }

}
int main(){
    vector<int> arr(5);
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }
    vector<int>arr2(arr);
    for(int i = 0; i < 5; i++) {
        cout << arr2[i];
    }

    return 0;
}
    
