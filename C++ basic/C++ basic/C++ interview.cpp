//
//  C++ interview.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/17.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

//移除指定字符集
/*
 1，数组下标查找
 2，删除优化
 3，截取进行返回
 */
string removeChars(string str, const string remove_str){
    int dst=0;
    vector<int> table(256,0);
    for(int i=0;i<remove_str.size();i++){
        table[remove_str[i]]=1;
    }
    for(int i=0;i<str.size();i++){
        //不删除
        if(table[str[i]]==0){
            str[i]=str[dst];
            dst++;
        }
    }
    return str.substr(0,dst);
}


int main(void){
    string str="xiongfei";
    string remove_str="gf";
    string res=removeChars(str,remove_str);
    cout<<res<<endl;
    return 0;
}

