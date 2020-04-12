/*************************************************************************
	> File Name: ClassString.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 15时45分40秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;

class mystring{
    private:
    //知识点1
    int length = 0;
    char *str = nullptr;
    public:
    //知识点2
    mystring() = default;
    //知识点3const
    mystring(const char *str);
    mystring(const mystring & st);
    //知识点4 &&
    mystring(mystring && st);
    mystring & operator=(const mystring &st);
    mystring & operator=(mystring &&st);
    char & operator[](const int ind);
    //知识点5 为啥又写一个
    const char & operator[](const int ind) const;
    ~mystring();
    //知识点6 返回值 和友元函数
    friend ostream & operator<<(ostream &os, const mystring &st);
};
mystring::mystring(const char *str){
    length = strlen(str);
    this->str = new char[length + 1];
    strncpy(this->str,str,length + 1);
}
mystring::mystring(const mystring & st){
    length = st.length;
    this->str = new char[length + 1];
    strncpy(this->str,st.str,length + 1);
}
mystring::mystring(mystring && st) {
    length = st.length;
    st.length = 0;
    this->str = st.str;
    st.str = nullptr;
}
mystring & mystring::operator=(const mystring &st){
    if (this == &st) {
        return *this;
    }
    length = st.length;
    this->str = new char[length + 1];
    strncpy(this->str,st.str,length + 1);
    return *this;
}
mystring & mystring::operator=(mystring &&st){
    if (this == &st){
        return *this;
    }
    length = st.length;
    st.length = 0;
    this->str = st.str;
    st.str = nullptr;
    return *this;
}
char & mystring::operator[](const int ind){
    return this->str[ind];
}
const char & mystring::operator[](const int ind)const {
    return this->str[ind];
}
mystring::~mystring(){
    this->length = 0;
    delete [] this->str;
}
ostream & operator<<(ostream &os, const mystring &st){
    os << st.str;
    return os;
}

int main(){
    char *st = "data";
    mystring st1;
    mystring st2(st);
    st1 = st2;
    cout << st1 << endl;

    return 0;
}
