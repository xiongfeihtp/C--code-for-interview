//
//  hash_map.cpp
//  c_plus_code_test
//
//  Created by 熊飞 on 2018/2/3.
//  Copyright © 2018年 熊飞. All rights reserved.
//
#include <iostream>
//#include <ext/hash_map>
#include <string>
#include <stdio.h>
#include <map>
using namespace std;
int main()
{
    map<int, string> mymap;
    mymap[9527]="唐伯虎点秋香";
    mymap[1000000]="百万富翁的生活";
    mymap[10000]="白领的工资底线";
    std::cout<<"927=>"<<mymap.find(9527)->second<<'\n';
}


