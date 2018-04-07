//
//  exception.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/16.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <exception>

using namespace std;
struct MyException:public exception{
    const char* what() const throw(){
        return "C++ Exception";
    }
};

int main(){
    try{
        throw MyException();
    }
    //捕获组
//在这里，what() 是异常类提供的一个公共方法，它已被所有子异常类重载。这将返回异常产生的原因。
    catch(MyException& e){
        cout<<"MyException caught"<<endl;
        cout<<e.what()<<endl;
    }
    catch(exception& e){
        ;
    }
}
