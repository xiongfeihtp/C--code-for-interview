//
//  coins.cpp
//  DP
//
//  Created by 熊飞 on 2018/3/12.
//  Copyright © 2018年 熊飞. All rights reserved.
//
#include <stdio.h>
#include <vector>
using namespace std;


//换钱的方法数
int coins(vector<int> arr, int aim){
    int coins_num=arr.size();
    
    if(arr.size()==0||aim<0)
        return 0;
    
    vector<vector<int>> dp(coins_num,vector<int>(aim+1));
    for(int i=0;i<coins_num;i++){
        dp[i][0]=1;
    }
    
    for(int j=1;arr[0]*j<=aim;j++){
        dp[0][arr[0]*j]=1;
    }
    for(int i=1;i<coins_num;i++){
        for(int j=1;j<=aim;j++){
            dp[i][j]=dp[i-1][j];
            dp[i][j]+=j-arr[i]==0 ? dp[i][j-arr[i]]:0;
        }
    }
    return dp[coins_num-1][aim];
}


//最小的换钱数目，每张钱只有一张
int coins2(vector<int> arr, int aim){
    if(arr.size() == 0 || aim < 0){
        return -1;
    }
                                       
    int n=arr.size();
    vector<int> dp(aim+1,-1);
    dp[0]=0;
    for(int i=0;i<n;i++){
        int item=arr[i];
        for(int j=item;j<=aim;j++){
            if(dp[j-item]!=-1){
                if(dp[j]==-1){
                    dp[j]=dp[j-item]+1;
                }else{
                    dp[j]=min(dp[j],dp[j-item])+1;
                }
            }
        }
    }
    return dp[aim];
}




