//
//  file_io.cpp
//  c_plus_code_test
//
//  Created by 熊飞 on 2017/12/6.
//  Copyright © 2017年 熊飞. All rights reserved.
//
#include <stdio.h>
/*
标准输入和标准输出流
 ofstream 创建文件并向文件写入信息
 ifstream   用于从文件读取信息
 fstream    同时包含上述两种功能
 在进行文件读写之前，先要打开文件open
*/

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    char data[100];
    ofstream outfile;
    outfile.open("afile.dat");
    cout<<"writing to the file"<<endl;
    cout<<"enter your name";
//读取一行数据到data中
    cin.getline(data,100);
    outfile<<data<<endl;
    cout<<"Enter your age:";
    cin>>data;
    //ignore会忽略读语句留下的多余字符
    cin.ignore();
    outfile<<data<<endl;
    outfile.close();
}
