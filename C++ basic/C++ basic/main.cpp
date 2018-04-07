//
//  main.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/15.
//  Copyright © 2018年 熊飞. All rights reserved.
//
#include<iostream>
#include<time.h>
#include<string>
//通过宏定义函数，最好将表达式内所有的变量加上括号
#define RANDOM(x)(rand()%(x))
#define MAX(a,b)((a)>(b)?(a):(b))
using namespace std;
const int MAX=4;
int *getRandom();

struct Books{
    char title[50];
    char auther[50];
    char subject[100];
    int book_id;
};

class Distance
{
private:
    int feet;
    int inches;
public:
    Distance(){
        feet = 0;
        inches = 0;
    }
    
    Distance(int f, int i){
        feet = f;
        inches = i;
    }
    
    friend ostream& operator<<(ostream &output, const Distance &D){
        output<<"F : "<<D.feet<<"I : "<<D.inches;
        return output;
    }
    
    friend istream & operator>>(istream &input, Distance &D )
    {
        input >> D.feet >> D.inches;
        return input;
    }
};


int month;
int day;
int year;

void Set(int m,int d, int y){
    ::year=y;   //全局解析域
    ::day=d;
    ::month=m;
}

class Tdata{
public:
    void Set(int m,int d, int y){
        ::Set(m,d,y);
    }
private:
    int month;
    int day;
    int year;
}; //struct和class后面都要跟;




int main(){
    /*
     数组
    //定义了数组，但是没有初始化，数组元素为随机值
    int array[100];
    //定义并初始化，其他元素为0
    int array[100]={1,2};
    
    //动态创建，未初始化，内部值还是0
    int* array=new int[100];
    //动态创建，并初始化
    int* array=new int [100]{1,2};
    for(int i=0;i<100;i++){
        cout<<array[i]<<endl;
    }
    //销毁动态创建的数组
    delete []array;
     */
    
    
    /*
     C风格字符串
     末尾会自动补零
    char greeting[]="Hello";
    char array_greeting[6] = {'x', 'i', 'o', 'n', 'g', '\0'};
    cout<<greeting<<endl;
    cout<<array_greeting<<endl;
    cout<<strcat(greeting,array_greeting)<<endl;
    cout<<greeting<<endl;
    char* p=strchr(greeting,'i');
     
     操作函数：
     strcpy(str1,str2)
     strcat(str1,str2) 原地操作
     strlen(str)
     strcmp(str1,str2)
     strchr(s1,ch)  返回指针
     strstr(s1,s2)  返回指针
     
    C++中的String类
    string str1="xiongfei";
    string str2="tianchi";
    string str3;
    cout<<"str1:"<<str1<<endl;
    cout<<"str2:"<<str2<<endl;
    cout<<"str3:"<<str3<<endl;
    
    str3=str1;
    cout<<"str3:"<<str3<<endl;
    str3=str1+str2;
    cout<<"str3:"<<str3<<endl;
    //这里size_t 表示地址线宽度，一般是大于int和unsigned int的
    size_t len=str3.size();
    cout<<"str3 size:"<<len<<endl;
    if(str1<str2)
        cout<<str1<<endl;
    else
        cout<<str2<<endl;
     
    string类型的扩展函数：
     append()
     find()
     insert()
     length()
     replace()
     substr() 左闭，右开
     string str="xiongfei";
     cout<<str.append("ong")<<endl;
     cout<<str.find_first_of("g")<<endl;
    */
    /*
//字符
    const char *names[MAX]={
        "Zara Ali",
        "Hina Ali",
        "Nuha Ali",
        "Sara Ali",
    };
    for(int i=0;i<MAX;i++){
        //指针数组，遍历元素
        cout<<names[i]<<endl;
    }
    
//整型
    int var[MAX]={10,100,200,300};
    int *ptr[MAX];
    for(int i=0;i<MAX;i++){
        ptr[i]=&var[i];
    }
    for(int i=0;i<MAX;i++){
        cout<<*ptr[i]<<endl;
    }
    */
    return 0;
}
/*
 C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
 C++中返回数组的操作，返回的是对应类型的指针，并且内部创建的临时数组需要设置为static，避免局部变量调用完而销魂。
int * getRandom(){
    static int r[10];
    srand((unsigned)time(NULL));
    for(int i=0;i<10;i++){
        r[i]=RANDOM(10);
        cout<<r[i]<<endl;
    }
    return r;
}
 */
