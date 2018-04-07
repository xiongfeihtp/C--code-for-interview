//
//  main.cpp
//  sort_algorithm
//
//  Created by 熊飞 on 2018/2/3.
//  Copyright © 2018年 熊飞. All rights reserved.
//
#include<iostream>
using namespace std;
//插入维护有序序列，进行交换，外循环选择移动元素位置，内循环判定需要移动多少次，最坏情况是移动到位置为零处
void InsertSort(int a[],int n)
{
    if(n<=1)
        return;
    //外循环
    for(int i=1;i<n;i++)
    {
        int j=i;
        //循环移位最坏情况是在移动j=0，只要碰到一次大，就可以跳出
        while(j>0)
        {
            if(a[j]<a[j-1])
            {
                int tmp=a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
                j--;
            }
            else
                break;
        }
    }
}

//冒泡
#include <algorithm>

void BubbleSort(int a[],int n)
{
    if(n<=1)
        return;
    for(int j=1;j<n;j++)
    {
        for(int i=1;i<n-j;i++)
        {
            if(a[i]<a[i-1])
            {
                swap(a[i],a[i-1]);
            }
//            if(a[i]<a[i-1])
//            {
//                int tmp=a[i-1];
//                a[i-1]=a[i];
//                a[i]=tmp;
//            }
        }
    }
}

//选择未排序的元素中最小的部分来维护有序序列，先考虑内循环第一步，然后再设置外循环来控制内循环
//不稳定 升序时复杂度最大

void SelectSort(int a[], int n)
{
    if(n<=1)
        return;
    //开始的时候让0元素和1元素比较
    for(int j=0;j<n-1;j++)
    {
        int min_index=j;
        //初始化内循环，找到最小值位置
        for(int i=j+1;i<n;i++)
        {
            if(a[min_index]>a[i])
            {
                min_index=i;
            }
        }
        int tmp=a[min_index];
        a[min_index]=a[j];
        a[j]=tmp;
    }
}



//思路选择两个哨兵和key值，只要当两个哨兵不相交时，则进行移动互换，一直到两个相交，然后找到key的对应位置
//注意中间取两个等号
void QuickSort(int a[],int l, int r)
{
    int i=l,j=r,x=a[l];
    if(i<j)
    {
        while(i < j)
        {
            while(i < j && a[j]>=x)
                j--;
            if(i<j)
                a[i++]=a[j];
            while(i<j&&a[i]<=x)
                i++;
            if(i<j)
                a[j--]=a[i];
        }
        a[i]=x;
        QuickSort(a,l,i-1);
        QuickSort(a,i+1,r);
    }
}
void Merge(int a[],int start,int mid,int end,int result[])
{
    int n1=mid-start+1;
    int index1=start;
    int index2=start+n1;
    int result_index=start;
    while(index1<start+n1&&index2<end+1)
    {
        if(a[index1]<a[index2])
        {
            result[result_index++]=a[index1++];
        }
        else
        {
            result[result_index++]=a[index2++];
        }
    }
    while(index1<start+n1)
    {
        result[result_index++]=a[index1++];
    }
    while(index2<end+1)
    {
        result[result_index++]=a[index2++];
    }
}


void MergeSort(int a[],int start,int end, int result[])
{
    //两个元素直接排序
    if(end-start==1)
    {
        if (a[start]>a[end])
        {
            int tmp=a[end];
            a[end]=a[start];
            a[start]=tmp;
        }
        return;
    }
    else if(end-start==0)
    {
        return;
    }
    else
    {
        int mid=(start+end)/2;
        MergeSort(a,start,mid,result);
        MergeSort(a,mid+1,end,result);
        Merge(a,start,mid,end,result);
        for(int i=start;i<=end;i++)
        {
            a[i]=result[i];
        }
    }
}
/*
 堆排序
 建堆O(N)
 调整O(logN)
 复杂度：N*logN
 最小堆和最大堆规定系数
 n个元素，编号：0,1,2,....n-1
 最后的非叶节点为0,1,2,....n/2-1
 第i个非叶节点的左孩子为2*i+1和2*i+2,父节点为(i-1)/2
 */
void swap(int &a,int &b)
{
    if(a!=b)
    {
        a^=b;
        b^=a;
        a^=b;
    }
}

void siftdown(int a[],int len,int index)
{
//左右孩子
    int lchild=2*index+1;
    int rchild=2*index+2;
//记录最大index
    int max_index=index;
//找到最大的元素，并交换
    if(lchild<len&&a[lchild]>a[index])
    {
        max_index=lchild;
    }
    if(rchild<len&&a[rchild]>a[max_index])
    {
        max_index=rchild;
    }
//交换后进行递归
    if(max_index!=index)
    {
        swap(a[max_index],a[index]);
        siftdown(a,len,max_index);
    }
}
void heapSort(int a[],int len)
{
    if(a==NULL||len<=1)
        return;
    //通过数组进行建堆，注意从最后一个非叶节点开始
    for(int i=len/2-1;i>=0;i--)
        siftdown(a, len, i);
    //交换元素后对最大堆进行弹出和调整，最小堆只需要修改不等号即可
    //进行n-1次操作即可
    for(int i=len-1;i>0;i--)
    {
        swap(a[0],a[i]);
        siftdown(a,i,0);
    }
}
/*
 堆的插入：
 需要先将要插入的结点x放在最底层的最右边，插入后满足完全二叉树的特点；然后把x依次向上调整到合适位置满足堆的性质。对应堆的size也要变化
 复杂度O(logn)
 */
//传入一个编号，并进行向上调整
void siftup(int a[],int len,int index)
{
    if(index==0)
        return;
    while(index!=0)
    {
        int father=(index-1)/2;
        if(a[index]>a[father])
            swap(a[index],a[father]);
        else
            break;
        index=father;
    }
}
int capacity=100;
bool outofcapacity=false;
int HeapInsert(int a[],int len,int value)
{
    outofcapacity=false;
    if(len>=capacity)
        outofcapacity=true;
    a[len]=value;
    siftup(a, len, len);
    len++;
    return len;
}

/*
 堆的删除：
 当删除操作结点的数值时，原来的位置就会出现一个孔，填充这个孔的方法就是，把最后的叶子的值赋给该孔并下调到合适位置，最后把该叶子删除。对应堆的size也要变化
 复杂度O(logn)
 */
//删除最大的元素
bool invalidInput=false;
int HeapRemove(int a[],int len)
{
    invalidInput=false;
    if(a==NULL||len<=0)
        invalidInput=true;
    swap(a[0],a[len-1]);
    siftdown(a,len-1,0);
    len--;
    return len;
}
//删除堆中指定元素i
int HeapDelete(int a[],int len,int index)
{
    int tmp=a[len-1];
    if(a[index]==tmp)
    {
        len--;
    }
    else if(a[index]>tmp)
    {
        a[index]=tmp;
        len--;
        siftdown(a,len,index);
    }
    else if(a[index]<tmp)
    {
        a[index]=tmp;
        len--;
        siftup(a,len,index);
    }
    return len;
}
/*
 堆排序优化算法
 */
void print_array(int a[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int a[]={12,14,25,32,23,45,12,63,24,12};
//  int a[10]={71,18,151,138,160 ,63 ,174, 169 ,79 ,78 };
    cout<<"before sort:";
    print_array(a,10);
    //int result[10];
    //注意这里的输入索引
    BubbleSort(a,10);
    cout<<"after sort:";
    print_array(a,10);
    return 0;
}
