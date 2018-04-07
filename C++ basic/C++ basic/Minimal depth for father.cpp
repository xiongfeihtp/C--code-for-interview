//
//  Minimal depth for father.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/22.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>
/*
问题1：
找到两个单链表的交汇点：
1，遍历两个链表，找出比较大的长度，并且计算gap
2，让长的链表首先移动，然后共同移动，直到找到相同的节点，这里的相同，是完全的相同

问题2：
如果这棵树是一颗普通的树，可能连二叉树都不算，但是有指向父节点的指针。
方案：其实这个问题可以转化为：求两个链表的公共结点，因为有指向父节点的指针，那么给的结点就在一个链表上，我们就可以查找这两个链表的第一个公共结点。查找两个链表的公共结点，我们已经在【5】中讲的比较详细了，这里就不多做介绍了！
*/
struct ListNode{
    int value;
    ListNode* next;
};

unsigned int GetListLength(ListNode* head){
    unsigned int Length = 0;
    ListNode* cur = head;
    while(cur != NULL){
        Length++;
        cur=cur->next;
    }
    return Length;
}

ListNode* FindFirstCommonNode(ListNode* head1, ListNode* head2){
    int Length1 = GetListLength(head1);
    int Length2 = GetListLength(head2);
    int gap = Length1 - Length2;
    ListNode* Cur_Long = head1;
    ListNode* Cur_Short = head2;
    if(Length1 < Length2){
        Cur_Long = head2;
        Cur_Short = head1;
        gap=Length2 - Length1;
    }
    
    for(int i = 0; i < gap; i++){
        Cur_Long = Cur_Long->next;
    }
    
    //这里的相同是完全的相同
    while(Cur_Long != NULL && Cur_Short != NULL && Cur_Long != Cur_Short){
        Cur_Long = Cur_Long->next;
        Cur_Short = Cur_Short->next;
    }
    ListNode* Res_Node = Cur_Long;
    return Res_Node;
}
/*
二叉树中的最低公共祖先
三种情况：
1，其中一个节点为根节点，不存在
2，root在n1和n2之间，直接返回root
3，root小于n1和n2，在右子树
4，root大于n1和n2，在左子树
5，一个节点为另一个节点的祖先，则取另一个节点的父节点
*/

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
};
//假设n1,n2都存在
TreeNode* Find_YoungestNode(TreeNode* root, int n1, int n2){
    int cur_num = root->value;
    //其中一个节点为根节点，则不存在公共最低祖先
    if(cur_num == n1 || cur_num == n2){
        return NULL;
    }
    while(root != NULL)
    {
        if(cur_num > n1 && cur_num > n2 && root->left->value != n1&& root->right->value != n2){
            root=root->left;
        }else if(cur_num<n1 && cur_num<n2 && root->left->value != n1 && root->right->value!=n2){
            root=root->right;
        }else{  //包括两种情况，1，满足中间条件，2，一个节点为另一个节点祖先
            return root;
        }
    }
    return NULL;
}


/*
条件三：这棵树是一棵普通的树，可能连二叉树都不是，也没有指向父节点的指针。
方案一：由于数据不是有序，也没有指向父节点的指针，也可能是N叉树，所以我们的初步想法是，逐个结点的找，如果发现一个结点包含输入的两个结点，则顺序遍历该结点的子结点，如果子节点是最后一个包含这两个输入结点的结点，它的子结点都不包含输入的两个子结点，则说明该结点是这两个输入结点的最低公共结点。
*/
//设置全局状态变量，针对一些特殊的不需要改变的参数设置为const，传入的容器统一取引用，这样减少内存复制
bool IsExistData1=true;
bool IsExistData2=true;


//一般的树结构
bool GetNodePath(TreeNode* root, const int n, list<TreeNode*> &path){
    if(root == NULL){
        return false;
    }
    path.push_back(root);
    if(root->value == n){
        return true;
    }else{
        //这里的逻辑要注意，先遍历左子树，如果没找到，在遍历右子树，否则这边没有可用路径，弹出当前节点。设置状态变量found
        bool found = false;
        found = GetNodePath(root->left, n, path);
        if(!found){
            found = GetNodePath(root->right, n, path);
        }
        
        if(!found){
            path.pop_back();
        }
        return found;
    }
}

TreeNode* GetLastComNode(list<TreeNode*> &path1,list<TreeNode*> &path2){
    list<TreeNode*>::const_iterator it1=path1.begin();   //遍历用的指针设置为const_iterator指针
    list<TreeNode*>::const_iterator it2=path2.begin();
    TreeNode* res=NULL;
    while(it1!=path1.end()&&it2!=path2.end()){
        if(*it1==*it2){  //完全相等的概念
            res=*it1;
        }
        it1++;
        it2++;
    }
    return res;
}

//一般的树，并且不存在父指针
TreeNode* GetLastCommonParent(TreeNode* root, const int n1, const int n2){
    if(root == NULL){
        return NULL;
    }
    list<TreeNode*> path1;
    if(!GetNodePath(root, n1, path1)){
        IsExistData1 = false;
        return NULL;
    }
    list<TreeNode*> path2;
    if(!GetNodePath(root, n2, path2)){
        IsExistData2 = false;
        return NULL;
    }
    return GetLastComNode(path1, path2);
}



