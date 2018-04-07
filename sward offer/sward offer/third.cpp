//
//  third.cpp
//  sward offer
//
//  Created by 熊飞 on 2018/2/9.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
//第三章 高质量代码
/*
 1，代码规范性
 代码书写清晰
 代码布局清晰
 代码变量命名清晰
 2，代码完整性
 功能测试：例如，正数，负数，零，或者意想不到的内存溢出的问题
 边界测试：循环或者递归的退出条件
 负面测试：不符合规范的输入
 3，三种错误处理的方法：
 返回值：不方便使用计算结果
 全局变量：方便使用计算结果
 异常：可以为不同的错误原因定义不同的异常类，思路清晰
 */

/*
 数值的整数次方，
 思路：
 考虑输入的整数是零，正数，负数，或者输入的数值为0
 C++中比较小数的大小不能用==，只能限制差在一定范围0.0000001
 */
bool g_InvalidInput=false;
bool equal(double num1,double num2)
{
    if((num1-num2)<0.0000001&&(num1-num2)>-0.0000001)
        return true;
    else
        return false;
}
double GetResult(double base,unsigned int exponent)
{
    double result=1.0;
    for(int i=0;i<exponent;i++)
        result*=base;
    return result;
}

double Power(double base,int exponent)
{
    g_InvalidInput=false;
    //零的零次方，特殊情况0或者1都行
    if(equal(base,0)&&exponent<0)
    {
        g_InvalidInput=true;
        return 0.0;
    }
    //标准正整数，转换为无符号整形
    unsigned int absexponent=(unsigned int)exponent;
    if(exponent<0)
    {
        absexponent=(unsigned int)(-exponent);
    }
    double result=GetResult(base,absexponent);
    if(exponent<0)
    {
        result=1.0/result;
    }
    return result;
}
//快速乘方，对于有明显重复计算的过程可以考虑优化过程，对于exponent判定奇数还是偶数，偶数的话递归log2(n)次，否则log2(n)+1次
double SpeedGetResult(double base,unsigned int exponent)
{
    if(exponent==0)
        return 1;
    if(exponent==1)
        return base;
    double result=SpeedGetResult(base, exponent>>1);
    result*=result;
    //判断奇偶性
    if((exponent&0x1)==1)
    {
        result*=base;
    }
    return result;
}


void memset(char* number,char init_char,int n)
{
    //全部重置为init_char
    for(int i=0;i<n;i++)
    {
        number[i]=init_char;
    }
}
//指向字符串数组的指针，相当于同时具有字符串特性和数组特性
bool Increment(char* number)
{
    bool isOverflow=false;
    int nTakeOver=0;
    int nLength=strlen(number);
    for(int i=nLength-1;i>=0;i--)
    {
        int nSum=number[i]-'0'+nTakeOver;
        if(i==nLength-1)
            nSum++;
        if(nSum>=10)
        {
            if(i==0)
            {
                isOverflow=true;
            }
            else
            {
                nSum-=10;
                nTakeOver=1;
                number[i]=nSum+'0';
            }
        }
        else
        {
            number[i]='0'+nSum;
            break;//没有进位就终止
        }
    }
    return isOverflow;
}
void PrintNumber(char* number)
{
    //为了符合用户习惯，从第一个非零开始打印
    bool isBegin0=true;
    int nLength=strlen(number);
    for(int i=0;i<nLength;i++)
    {
        if(isBegin0&&number[i]!='0')
        {
            isBegin0=false;
        }
        if(!isBegin0)
        {
            cout<<number[i];
        }
    }
}
//打印1到最大的n位数，大数陷阱（数值溢出），通过字符串或者数组上的操作模型数字的递增加法
void PrintToMaxOfNDigits(int n)
{
    if(n<=0)
        return;
    //创建动态数组
    char* number=new char[n+1];
    //初始化为全'0'
    memset(number,'0',n);
    number[n]='\0';
    //到第一位进位就停止
    while(!Increment(number))
    {
        PrintNumber(number);
    }
    //消去内存
    delete[] number;
}
//待改进点
//通过char型字符8bit表示是十进制的字符的一个，最多可以表示256个字符，可以有内存优化方法
//另外输出从1到最大的数，等价于全排列，可以通过递归的思想写出
void PrintToMaxOfNDigits_Recursively(char* number,int nLength, int index)
{
    //递归退出条件
    if(index==nLength-1)
    {
        PrintNumber(number);
        return;
    }
    for(int i=0;i<10;i++)
    {
        number[index+1]=i+'0';
        PrintToMaxOfNDigits_Recursively(number, nLength, index+1);
    }
}
void Print1ToMaxOfNDigits(int n)
{
    if(n<=0)
        return;
    char* number=new char[n+1];
    number[n]='\0';
    //进行全排列，并对每一个全排列进行打印
    //设置第一位
    for(int i=0;i<10;i++)
    {
        number[0]='0'+i;
        PrintToMaxOfNDigits_Recursively(number,n,0);
    }
}
//O(1)时间复杂度内删除链表结点
//时间复杂度计算方法和链表的时间复杂度常用分析
/*
 遍历和查找链表时间复杂度都是O(n)，具有多种情况时计算的是平均时间复杂度
 ((n-1)*O(1)+O(n))/n=O(1)
 */
struct ListNode
{
    int value;
    ListNode* next;
};
void DeleteNode(ListNode** head,ListNode* Del_Node)
{
    if(head==NULL||Del_Node==NULL)
        return;
    //非尾结点
    if(Del_Node->next !=NULL)
    {
        ListNode* tmp=Del_Node->next;
        Del_Node->value=tmp->value;
        Del_Node->next=tmp->next;
        //清空链表结点的方法，delete and NULL
        delete tmp;
        tmp=NULL;
    }
    //删除的是头结点
    //如果删除的是头结点，头指针一定要指向NULL
    else if(*head==Del_Node)
    {
        delete Del_Node;
        Del_Node=NULL;
        *head=NULL;
    }
    //遍历删除尾结点
    else
    {
        ListNode* cur=*head;
        //找到Del_Node前一个结点
        while(cur->next==Del_Node)
        {
            cur=cur->next;
        }
        cur->next=NULL;
        delete Del_Node;
        Del_Node=NULL;
    }
}
//还需要考虑一种特殊情况，如果Del_Node不在链表中，但是判断一个结点在不在链表内是O(n)复杂度，可以在面试的时候提出这个假设

//调整数组顺序使得奇数位于偶数前面,通过两个工作指针，当前面是偶数后面是奇数时进行交换，借鉴快排的思路，可以找到一个分界，并且保证分界的左右满足不同的条件，可以将这条件模式，抽象成一类函数。
void RecorderOddEven(int* numbers,unsigned int length)
{
    //numbers是指针
    if(numbers==NULL||length<=0)
        return;
    int *p1=numbers;
    int *p2=numbers+length-1;
    //判断奇偶性(number&0x1)!=0偶数
    while(p1<p2)
    {
        //移动p1到一个偶数
        while(p1<p2&&(*p1&0x1)!=0)
            p1++;
        //移动p2到一个奇数
        while(p1<p2&&(*p2&0x1)==0)
            p2--;
        if(p1<p2)
        {
            //交换
            int tmp=*p1;
            *p1=*p2;
            *p2=tmp;
        }
    }
}
//输入头结点
ListNode* OutputkNodeReverse(ListNode* headNode,int k)
{
    if(headNode==NULL||k<=0)
        return NULL;
    ListNode *first=headNode;
    ListNode *second=NULL;
    //前移k个，如果超出length的范围则返回
    for(unsigned int i=0;i<k-1;i++)
    {
        if(first->next!=NULL)
        {
            first=first->next;
        }
        else
        {
            return NULL;
        }
    }
    second=headNode;
    while(first->next!=NULL)
    {
        first=first->next;
        second=second->next;
    }
    return second;
}
//这里给的是头结点，如果是头指针后面输出会有区别
ListNode* ReverseList(ListNode* headNode)
{
    if(headNode==NULL||headNode->next==NULL)
        return headNode;
    //只有一个结点
    ListNode* pre=NULL;
    ListNode* cur=headNode;
    ListNode* net=NULL;
    while(cur!=NULL)
    {
        net=cur->next;
        cur->next=pre;
        pre=cur;
        cur=net;
    }
    //cur=NULL pre为尾结点
    return pre;
}
//链表反向递归实现
ListNode* ReverseList_recursion(ListNode* headNode)
{
    if(headNode==NULL||headNode->next==NULL)
        return headNode;
    //首先一直递归到尾结点，此时headNode为倒数第二个结点
    ListNode* newHead=ReverseList_recursion(headNode->next);
    headNode->next->next=headNode;
    headNode->next=NULL;
    return newHead;
}

//合并两个有序链表，归并排序有用，递归或者循环
ListNode* Merge(ListNode* headNode1,ListNode* headNode2)
{
    if(headNode1==NULL)
        return headNode2;
    else if(headNode2==NULL)
        return headNode1;
    ListNode* MergeheadNode=NULL;
    if(headNode1->value<=headNode2->value)
    {
        MergeheadNode=headNode2;
        MergeheadNode->next=Merge(headNode1,headNode2->next);
    }
    else
    {
        MergeheadNode=headNode1;
        MergeheadNode->next=Merge(headNode1->next,headNode2);
    }
    return MergeheadNode;
}

//判断是否为二叉树的子结构
/*
 1，找到相同的根节点
 2，遍历查看剩下的结构是否相同
tips：在和指针相关的操作中，一定要注意NULL指针，避免程序崩溃
 */
struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};
//遍历两颗二叉树，判断是否结构完全相同
bool HasSubTree2(BinaryTreeNode* Root1,BinaryTreeNode* Root2)
{
    if(Root1==NULL)
        return false;
    if(Root2==NULL)
        return true;
    if(Root1->value!=Root2->value)
        return false;
    return HasSubTree2(Root1->left,Root2->left)&&HasSubTree2(Root1->right,Root2->right);
}

bool HasSubTree(BinaryTreeNode* Root1,BinaryTreeNode* Root2)
{
    bool result=false;
    //遍历找到通过的根节点
    while(Root1!=NULL||Root2!=NULL)
    {
        if(Root1->value==Root2->value)
            //遍历结构判断是否具有完全相同的结构
            result=HasSubTree2(Root1,Root2);
        
        if(!result)
            result=HasSubTree(Root1->left,Root2);
        if(!result)
            result=HasSubTree(Root1->right,Root2);
    }
    return result;
}


int main(int argc, const char * argv[]) {
}

