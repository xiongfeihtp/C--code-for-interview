//
//  virtual.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/18.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

//抽象类
class Shape{
protected:
    float x;
    float y;
public:
    Shape(float i, float j):x(i),y(j){};
    virtual void printArea()=0;
};


//具体子类
class Rectangle: public Shape{
public:
    //列表初始化显示调用父类构造函数
    Rectangle(float i, float j):Shape(i,j){};
    void printArea(){
        cout<<"Rectangle Area: "<<x*y<<endl;
    }
};

class Triangle: public Shape{
public:
    Triangle(float i, float j):Shape(i,j){};
    void printArea(){
        cout<<"Triangle: "<<x*y/2<<endl;
    }
};





