//
//  dynamic memory.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/16.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class Box{
public:
    Box(){
        cout<<"调用构造函数"<<endl;
    }
    ~Box(){
        cout<<"调用析构函数"<<endl;
    }
};

#define M 200
#define N 200
#define H 200
int main(void){
    //检查内存是否有空余
    /*
    double* pvalue=NULL;
    if(!(pvalue =new double)){
        cerr<<"Error: out of memory."<<endl;
        exit(1);
    }
    */
    //对数组的操作
    //一维数组
    int *array1=new int[M];
    delete [] array1;

    //二维数组
    int **array2;
    array2=new int*[M];
    for(int i=0;i<M;i++){
        array2[i]=new int[N];
    }
    for(int i=0;i<M;i++){
        delete[] array2[i];
    }
    delete [] array2;
    //对象数组
    Box* myBoxarray=new Box[4];
    delete[] myBoxarray;
    return 0;
}

