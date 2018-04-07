//
//  main.cpp
//  tree
//
//  Created by 熊飞 on 2018/2/27.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <iostream>
#include <cstdlib>
# define MAX 26 //这里只针对标准英文字符串
using namespace std;
typedef struct TriedNode
{
    bool isStr;
    struct TriedNode *next[MAX];
}Tried;

void insert(Tried *root, const char *s)
{
    if(root==NULL||*s=='\0')
        return;
    int i;
    Tried *cur=root;
    while(*s!='\0')
    {
        if(cur->next[*s-'a']==NULL)
        {
            Tried *temp=(Tried *)malloc(sizeof(Tried));
            for(i=0;i<MAX;i++)
            {
                temp->next[i]=NULL;
            }
            temp->isStr=false;
            cur->next[*s-'a']=temp;
            cur=cur->next[*s-'a'];
        }
        else
        {
            cur=cur->next[*s-'a'];
        }
        s++;
    }
    //单词构建结束
    cur->isStr=true;
}

int search(Tried *root,const char *s)
{
    Tried *cur=root;
    while(cur!=NULL && (*s)!='\0')
    {
        cur=cur->next[*s-'a'];
        s++;
    }
    return ((cur!=NULL&&cur->isStr)==true);
}

//释放内存很重要
void del(Tried *root)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        if(root->next[i]!=NULL)
        {
            del(root->next[i]);
        }
    }
    free(root);
}
