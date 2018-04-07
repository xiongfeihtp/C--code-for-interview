//
//  STL.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/18.
//  Copyright © 2018年 熊飞. All rights reserved.
//

//#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>


using namespace std;
struct square{
    int length;
    int width;
    square(int i, int j):length(i),width(j){}
};


//C++中定义比较方法
struct compare{
    bool operator() (square x, square y){
        return ((x.length*x.width)<(y.length*y.width));
    }
};

int main(){
    priority_queue<square,vector<square>,compare> p;
    srand((unsigned)time(NULL));
    for(int i=0;i<10;i++){
        p.push(square(rand()%100+1,rand()%100+1));
    }
    while(!p.empty()){
        cout<<p.top().length<<"*"<<p.top().width<<endl;
        p.pop();
    }
}
