//
//  main.cpp
//  DP
//
//  Created by 熊飞 on 2018/2/24.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define N 20
using namespace std;

int dp[N];
int fun(int n)
{
    if(n==1||n==2)
        return n;
    dp[n-1]=fun(n-1);
    dp[n-2]=fun(n-2);
    dp[n]=dp[n-1]+dp[n-1];
    return dp[n];
}
bool invalid=false;
int maxSum(int numbers[],int length)
{
    if(numbers==NULL||length<=0)
    {
        invalid=true;
        return 0;
    }
    invalid=false;
    if(length==1)
        return numbers[0];
    //有正数也有负数
    int sumCurrent=0;
    int result=0x80000000;
    for(int i=1;i<length;i++)
    {
        if(sumCurrent<=0)
            sumCurrent=numbers[i];
        else
            sumCurrent+=numbers[i];
        if(sumCurrent>result)
            result=sumCurrent;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    fun(N);
    cout<<dp[5]<<endl;        //输出15阶的走法
    return 0;
}


