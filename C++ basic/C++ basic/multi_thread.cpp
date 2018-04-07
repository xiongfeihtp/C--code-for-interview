//
//  multi_thread.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/17.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5


void *PrintHello(void *threadid){
    int tid=*((int*)threadid);
    cout<<"Hello Runoob！线程 ID，"<<tid<<endl;
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int indexs[NUM_THREADS];
    int rc;
    for(int i=0;i<NUM_THREADS;i++){
        cout<<"main() : 创建线程,"<<i<<endl;
        indexs[i]=i;
        rc=pthread_create(&threads[i],NULL,PrintHello,(void*)&(indexs[i]));
        if(rc){
            cout<<"Error:无法创建线程，"<<rc<<endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}
