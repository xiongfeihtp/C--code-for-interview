//
//  intelligent ptr.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/18.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>
#include <memory>
#include <list>
#include <vector>
using namespace std;



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

    while(Cur_Long != NULL && Cur_Short != NULL && Cur_Long != Cur_Short){
        Cur_Long = Cur_Long->next;
        Cur_Short = Cur_Short->next;
    }
    ListNode* Res_Node = Cur_Long;
    return Res_Node;
}

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
};

//假设n1,n2都存在
TreeNode* Find_YoungestNode(TreeNode* root, const int n1, const int n2){
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
    list<TreeNode*>::const_iterator it1=path1.begin();
    list<TreeNode*>::const_iterator it2=path2.begin();
    TreeNode* res=NULL;
    while(it1!=path1.end()&&it2!=path2.end()){
        if(*it1==*it2){
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

vector<int> inorderTraversal(TreeNode* root){
    vector<int> res;
    if(root == NULL){
        return res;
    }
    helper(root, res);
    return res;
}

void helper(TreeNode* root, vector<int> &res){
    if(root == NULL)
        return;
    if(root->left) helper(root->left,res);
    res.push_back(root->value);
    if(root->right) helper(root->right,res);
}




int main(){
    ;
}
