//
//  hash.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/22.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>
/*
202. Happy Number
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

//无限的迭代过程，如果出现循环则判定退出并且返回false，或者满足某个条件。判断循环的话，建立hash_map进行查找
C++中存在简单实现set<int> sum_set;   插入： sum_set.insert(n)   查找 sum_set.find(n)==sum_set.end() 不存在
/*
 
class Solution {
public:
    int SUM(int n){
        int sum=0;
        while(n){
            int c=n%10;
            n=n/10;
            sum+=c*c;
        }
        return sum;
    }//对一个整数按位进行操作
    
    bool isHappy(int n) {
        set<int> sum_set;
        int sum=SUM(n);
        while(sum!=1){
            if(sum_set.find(sum) == sum_set.end()){
                sum_set.insert(sum);
                sum=SUM(sum);
            }else
                return false;
        }
        return true;
        
    }
};

