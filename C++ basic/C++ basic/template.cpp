//
//  template.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/16.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
//模板函数
template <typename T>
//注意顺序 T const&
inline T const& MAX(T const &a,T const &b){
    return a < b ? b : a;
}


//模板类
template <typename T>
class Stack{
private:
    vector<T> elems;
public:
    void push(T const&);  //函数声明可以省略形参名字
    void pop();
    T top() const; //top不能改变数据成员
    bool empty() const{
        return elems.empty();
    }
};

template <typename T>
//要和类的声明一致，包括形参名字
void Stack<T>::push(T const& elem){
    elems.push_back(elem);
}

template <typename T>
void Stack<T>::pop(){
    if(elems.empty()){
        throw out_of_range("Stack<>::pop():empty stack");
    }
    elems.pop_back();
}

template <typename T>
//要和类的声明一致
T Stack<T>::top() const{
    if(elems.empty()){
        throw out_of_range("Stack<>::pop():empty stack");
    }
    return elems.back();
}

int main(void){
    int i=20,j=30;
    cout<<MAX(i,j)<<endl;
    return 0;
}



