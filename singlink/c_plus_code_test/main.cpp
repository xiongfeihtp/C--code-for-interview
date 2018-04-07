//
//  main.cpp
//  c_plus_code_test
//
//  Created by 熊飞 on 2017/12/5.
//  Copyright © 2017年 熊飞. All rights reserved.
//

#include <iostream>

using namespace std;
enum color{red,green=5,blue};
int main()
{
    cout<<red<<green<<blue<<endl;
    cout<<"Hello World"<<endl;
    return 0;
}
/*
int main(int argc, const char * argv[]) {
    int sum=0,value;
    
    std::cout<<"please input a number for sum";
    while(std::cin>>value)
        sum+=value;
    std::cout<<"sum is:"<<sum<<std::endl;
    return 0;
}
*/
