//
//  monkey kin.cpp
//  c_plus_code_test
//
//  Created by 熊飞 on 2018/2/3.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
}LNode;

//总数n,起始报数的编号k,出局数字m
void Josephus(int n,int k,int m)
{
    int i;
    int totle = n;
    LNode *p,*prevP,*head,*s;//p为当前节点，head为头节点
    head=(LNode *)malloc(sizeof(LNode));
    head->data = 0;
    head->next = head;
    p = head;
    p->data = 1;
    p->next = p;
    //尾插法
    for(i=2;i<=n;i++)
    {
        LNode * temp = (LNode *)malloc(sizeof(LNode));
        temp->data = i;
        temp->next = p->next;
        p->next = temp;
        p=p->next;
    }
    p = head;
    for(i=1;i<k;i++)
        p=p->next;
    prevP = head;
    while(totle!=1)
    {
        for(i=1;i<m;i++)
            p=p->next;
        printf("%d 出局\n",p->data);
        while(prevP->next!=p)
            prevP=prevP->next;
        prevP->next = p->next;
        s = p;
        p = p->next;
        free(s);
        totle--;
    }
    printf("最后剩下的节点为%d",p->data);
}
int main()
{
    Josephus(13,4,1);
    return 0;
}
