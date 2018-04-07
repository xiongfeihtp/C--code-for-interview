#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
#define N 6
#define m 5
using namespace std;

int sum=0;
vector<vector<int>> make_matrix(int parts_num)
{
    vector<vector<int>> input(parts_num,vector<int>(parts_num));
    for(int i=0;i<parts_num;i++){
        if(i>0 && i<parts_num-1){
            input[i][i-1]=1;
            input[i][i+1]=1;
        }else if(i==0){
            input[i][parts_num-1]=1;
            input[i][i+1]=1;
        }else if(i==parts_num-1){
            input[i][0]=1;
            input[i][i-1]=1;
        }
    }
    return input;
}

bool OK(int t,int i,vector<vector<int>> a, vector<int> x)
{
    for(int j=0;j<t;j++)
    {
        if(a[t][j])
        {
            if(x[j]==i)return false;
        }
    }
    return true;
}



void Backtrace(int t,vector<vector<int>> a, vector<int> x)
{
    if(t==N)
    {
        sum++;
//        cout<<"the possible plan "<<sum<<endl;
//        for(int i=0;i<N;i++)
//        {
//            cout<<x[i]<<" ";
//        }
//        cout<<endl;
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            if(OK(t,i,a,x))
            {
                x[t]=i;
                Backtrace(t+1, a, x);
            }
        }
        x[t]=0;
    }
}

int main()
{
    vector<vector<int>> inputs=make_matrix(N);
    vector<int> res(N,0);
    Backtrace(0, inputs, res);
    cout<<sum<<endl;
    if(sum==0)
    {
        cout<<"invalid for color num "<<N<<endl;
    }
    return 0;
}

