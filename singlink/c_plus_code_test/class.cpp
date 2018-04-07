//
//  class.cpp
//  c_plus_code_test
//
//  Created by 熊飞 on 2017/12/6.
//  Copyright © 2017年 熊飞. All rights reserved.
//

#include<iostream>

using namespace std;
class shape
{
    public:
    void setWidth(int w)
    {
        width=w;
    }
    void setHeight(int h)
    {
        height=h;
    }
protected:
    int width;
    int height;
};


class PaintCost
{
public:
    int getCost(int area)
    {
        return area*70;
    }
};


class Rectangle: public shape,public PaintCost
{
public:
    int getArea()
    {
        return (width*height);
    }
};

int main(void)
{
    Rectangle Rect;
    Rect.setWidth(5);
    Rect.setHeight(7);
    cout<<"Total area:"<<Rect.getArea()<<endl;
}
