//
//  array_and _point.cpp
//  c_plus_code_test
//
//  Created by 熊飞 on 2017/12/6.
//  Copyright © 2017年 熊飞. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int * getRandom()
{
    static int r[10];
    srand((unsigned)time(NULL));
    for(int i=0;i<10;++i)
    {
        r[i]=rand();
        cout<<r[i]<<endl;
    }
    return r;
}
int main()
{
    int *p;
    p=getRandom();
    for(int i=0;i<10;++i)
    {
        cout<<"*(p+)"<<i<<"):";
        cout<<*(p+i)<<endl;
    }
    return 0;
    
}
