//
//  Sort.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/22.
//  Copyright © 2018年 熊飞. All rights reserved.
//
#include <stdio.h>
void QuickSort(int a[], int l, int r){
    int i = l, j = r, x = a[i];
    if(i < j){
        while(i < j){
            while(i < j && a[j] >= x)
                j--;
            if(i < j)
                a[i++] = a[j];
            while(i < j && a[i] <= x)
                i++;
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        QuickSort(a, l, i-1);
        QuickSort(a, i+1, r);
    }
}


#include <stdlib.h>
#include <algorithm>
using namespace std;
int Partition(int data[], int length, int start, int end){
    if(data == NULL || length <= 0 || start < 0 || end >= length)
        throw "Invalid input";
    int index = rand()%(end -start) + start;
    swap(data[start],data[index]);
    int x = data[start], i = start, j = end;
    while(i < j){
        while(i < j && data[j] >= x)
            j--;
        if(i < j)
            data[i++]=data[j];
        while(i < j && data[i] <= x)
            i++;
        if(i < j)
            data[j--]=data[i];
    }
    return i;
}

#include <iostream>
#include <string>
using namespace std;
int main(){
    string s = "xiongfei";
    cout<<s+char('a'+1);
}
