//
//  C++ Primer plus.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/17.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define N 10

struct Test1{
    int a;
    Test1(){
        cout<<"Construct Test1"<<endl;
    }
    Test1(const Test1 &t1){
        cout<<"Copy constructor for Test1"<<endl;
        this->a=t1.a;
    }
    Test1& operator=(const Test1 &t1){
        cout<<"assignment for Test1"<<endl;
        this->a=t1.a;
        return *this;
    }
};

struct Test2{
    Test1 test1;
    Test2(const Test1 &t1):test1(t1){}
};

int main(void){
    char s[10] = "xiongfei";
    cout<<s[8]<<endl;
    return 0;
}
