//
//  Tree summary.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/22.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>

/*
94. Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
1
\
2
/
3
return [1,3,2].
*/


//递归实现
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> res;
        inorder_Recursive(root,res);
        return res;
    }
    void inorder_Recursive(TreeNode* root,vector<int>& res){
        if(!root){
            return;
        }
        //中序遍历
        if(root->left) inorder_Recursive(root->left,res); //左子树
        res.push_back(root->val);  //根节点
        if(root->right) inorder_Recursive(root->right,res);  //右子树
    }
};


/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3
*/


//动态规划，卡塔兰树的形式
class Solution {
public:
    int numTrees(int n) {
        vector <int> res;
        res.push_back(1);
        res.push_back(1);
        int sum=0;
        for(int i=2;i<=n;i++){
            sum=0;
            for(int j=0;j<i;j++){
                sum+=res[j]*res[i-j-1];
            }
            res.push_back(sum);
        }
        return res.back();
    }
};


/*
95. Unique Binary Search Trees II

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3
*/
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if(n==0){
            vector<TreeNode*> trees;
            return trees;
        }
        return generateTrees_helper(1, n);
    }
    
private:
    vector<TreeNode*> generateTrees_helper(int start, int end)
    {
        vector<TreeNode*> trees;
        if(start > end)
        {
            trees.push_back(NULL);
            return trees;
        }
        
        if(start == end)
        {
            trees.push_back(new TreeNode(start));
            return trees;
        }
        for(int i = start; i <= end; i++)
        {
            //产生以i为根结点的左右子树的所有可能。i取值start到end
            vector<TreeNode*> leftTree = generateTrees_helper(start, i-1);
            vector<TreeNode*> rightTree = generateTrees_helper(i+1, end);
            
            //将左子树的所有可能和右子树的所有可能连接.leftTree[0]表示第一个节点。
            for(int j = 0; j < leftTree.size(); j++)
            {
                for(int k = 0; k < rightTree.size(); k++)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree[j];
                    root->right = rightTree[k];
                    trees.push_back(root);  //trees保存当前的根结点
                }
            }
        }
        return trees;
    }
};

/*
100. Same Tree   树的遍历采取递归的思想。递归，递归，确定递归的返回

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
/ \       / \
2   3     2   3

[1,2,3],   [1,2,3]

Output: true
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        
        if(p==NULL && q!=NULL)
            return false;
        
        if(p!=NULL && q==NULL)
            return false;
        
        if(p->val==q->val){
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right) ? true :false;
        }else
            return false;
    }
};


/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its zigzag level order traversal as:
[
 [3],
 [20,9],
 [15,7]
 ]
 */

//广度搜索，记录层数，dq,size()判定层
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        //树的广度遍历，需要交叉顺序，设置双端队列
        deque <TreeNode*> dq;
        dq.push_back(root);
        int layer=0;
        while(dq.size()){
            vector<int> tmp;
            int h=dq.size();
            int cur=0;
            TreeNode* t;
            while(cur<h){
                //奇数层
                if(layer%2){
                    t=dq.front();
                    dq.pop_front();
                    if(t->right) dq.push_back(t->right);
                    if(t->left) dq.push_back(t->left);
                    tmp.push_back(t->val);
                    h--;
                }else{
                    t=dq.back();
                    dq.pop_back();
                    if(t->left) dq.push_front(t->left);
                    if(t->right) dq.push_front(t->right);
                    tmp.push_back(t->val);
                    h--;
                }
            }
            res.push_back(tmp);
            layer++;
        }
        return res;
    }
};


105. Construct Binary Tree from Preorder and Inorder Traversal
从前序和中序重建树结构，输入数据结构为vector所以可以通过传入迭代器来进行截取和查找，记住定位的位置，并找到对应的左右子树部分
class Solution {
    typedef vector<int>::iterator iter;
    typedef vector<int>& vec;
public:
    TreeNode* helper(vec preorder,iter pre_begin, iter pre_end, vec inorder, iter in_begin, iter in_end){
        if(pre_begin>=pre_end||in_begin>=in_end)
            return NULL;
        int value=*pre_begin;
        TreeNode* root=new TreeNode(value);
        iter it=find(in_begin,in_end,value);
        int leftLength=it-in_begin;
        root->left=helper(preorder, pre_begin+1, pre_begin+leftLength+1, inorder, in_begin, it);
        root->right=helper(preorder, pre_begin+leftLength+1, pre_end, inorder, it+1, in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, preorder.begin(), preorder.end(), inorder, inorder.begin(), inorder.end());
    }
};

/*
106. Construct Binary Tree from Inorder and Postorder Traversal
同样的思路，但是要注意迭代器的范围操作，end-1是最后一个元素，begin+n是第1+n个元素，并且可以逆向操作
 */

class Solution {
    typedef vector<int>& vec;
    typedef vector<int>::iterator iter;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, inorder.begin(), inorder.end(), postorder, postorder.begin(), postorder.end());
    }
    TreeNode* helper(vec inorder, iter in_begin, iter in_end, vec postorder, iter post_begin, iter post_end){
        if(in_begin >= in_end || post_begin >= post_end)
            return NULL;
        
        //end-1才是最后一个元素
        int value = *(post_end-1);
        iter it = find(in_begin, in_end, value);
        TreeNode* root = new TreeNode(value);
        int left_len = it - in_begin;
        
        root->left = helper(inorder, in_begin, it, postorder, post_begin, post_begin + left_len);
        root->right = helper(inorder, it + 1, in_end, postorder, post_begin + left_len, post_end-1);
        return root;
    }
};

/*
107. Binary Tree Level Order Traversal II
广度搜索，但是反序，直接调用reverse方法，对vector进行逆序
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            int h=q.size();  //第n层的数目
            while(h){
                TreeNode* t;
                t=q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                tmp.push_back(t->val);
                h--;
            }
            res.push_back(tmp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};



//树的遍历，前序， 递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        helper(res, root);
        return res;
    }
    void helper(vector<int>& res, TreeNode* root){
        if(!root)
            return;
        res.push_back(root->val);
        if(root->left) helper(res, root->left);
        if(root->right) helper(res, root->right);
    }
};

//树的遍历，前序， 循环
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        //结构体非空判断用！=NULL
        while((root!=NULL) || (!stk.empty())){
            if(root!=NULL){
                res.push_back(root->val);
                stk.push(root);
                root=root->left;
            }else{
                root=stk.top();
                stk.pop();
                root=root->right;
            }
        }
        return res;
    }
};

//树的遍历，后序
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        helper(res, root);
        return res;
    }
    void helper(vector<int>& res, TreeNode* root){
        if(!root)
            return;
        if(root->left) helper(res, root->left);
        if(root->right) helper(res, root->right);
        res.push_back(root->val);
        return;
    }
};
//树的遍历，后序，递归
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while(root!=NULL || !stk.empty()){
            if(root!=NULL){
                stk.push(root);
                res.insert(res.begin(), root->val);
                root->right;
            }else{
                root=stk.top();
                stk.pop();
                root=root->left;
            }
        }
        return res;
    }
};


/*
110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

3
/ \
9  20
/  \
15   7
Return true.
 */


//两层递归，递归，递归思想，只用求一步给一个条件
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if(abs(height(root->left) - height(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};


/*
111. Minimum Depth of Binary Tree
//深度优先搜索，用递归栈实现，求最小时要考虑根节点左右为空时，返回NULL为无效叶节点的情况
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lmin=minDepth(root->left);
        int rmin=minDepth(root->right);
        if(lmin==0)
            return rmin+1;
        else if(rmin==0)
            return lmin+1;
        else
            return min(lmin,rmin)+1;
    }
};

//深度优先搜索，max
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int max_dep=max(maxDepth(root->left),maxDepth(root->right))+1;
        return max_dep;
    }
};


/*
112. Path Sum
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,

5
/ \
4   8
/   / \
11  13  4
/  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

递归形式，递归进行条件为sum减去root值。退出条件为root==NULL或者到达叶节点
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        //深度优先搜索
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
            return sum==root->val;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

/*
113. Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \    / \
7    2  5   1
return
[
 [5,4,11,2],
 [5,8,4,5]
 ]

vector<int> nums记录结果
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> nums;
        if(root==NULL)
            return res;
        helper(res, root, sum, nums);
        return res;
    }
    
    void helper(vector<vector<int>>& res, TreeNode* root, int sum, vector<int> nums){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            if(root->val==sum){
                //判断成功也要进行添加
                nums.push_back(root->val);
                res.push_back(nums);
                return;
            }
        }
        /每迭代一次进行一次添加
        nums.push_back(root->val);
        if(root->left!=NULL) helper(res, root->left, sum-root->val, nums);
        if(root->right!=NULL) helper(res, root->right, sum-root->val, nums);
    }
};

/*
437. Path Sum III
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

10
/  \
5   -3
/ \    \
3   2   11
/ \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

*/

//遍历树的所有路径的递归方法，路径可以不包含根和叶节点
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        int res = helper(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum); //这里很特征，两层递归
        return res;
    }
    
    
    int helper(TreeNode* root, int curSum, int sum){
        if(root==NULL)
            return 0;
        curSum += root->val;
        return (curSum == sum) + helper(root->left, curSum, sum) + helper(root->right, curSum, sum);
    }
};



/*
687. Longest Univalue Path
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

5
/ \
4   5
/ \   \
1   1   5
Output:

2

*/

//特殊情况  两边都存在时。通过全局变量来保存结果
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL)
            return 0;
        helper(root);
        return ans;
    }
    
    int helper(TreeNode* root){
        if(root == NULL)
            return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        
        //这里注意是左右子树为空的时候进入条件：意义在于
        if((root->left == NULL || root->left->val == root->val) && (root->right == NULL || root->right->val == root->val)){
            ans = max(ans, l+r);  //两边夹
            return max(l, r)+1;
        }else if((root->left == NULL || root->left->val != root->val) && (root->right == NULL || root->right->val != root->val)){
            return 1;    //都不满足
        }else if(root->left == NULL || root->left->val != root->val){
            ans = max(ans, r);   //左边
            return r+1;
        }else if(root->right == NULL || root->right->val != root->val){
            ans = max(ans, l);  //左边
            return l+1;
        }else
            return 1;
    }
private:
    int ans;
};


/*
124. Binary Tree Maximum Path Sum
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

1
/ \
2   3
Return 6.

*/

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        helper(root);
        return max_sum;
    }
    
    int helper(TreeNode* root){
        if(root==NULL)
            return 0;
        
        //取一次下一层递归出栈的结果，一般是左右节点的满足一些条件的值
        // 左子树最大路径值(路径特点：左右节点只能选一个)
        int l= helper(root->left);
        // 右子树最大路径值(路径特点：左右节点只能选一个)
        int r = helper(root->right);
        
        
        //针对上面的值和此时的根节点对全局变量或者输入的引用变量进行跟新
        // 以node节点的双侧路径((node节点以及左右子树))
        int root_value = root->val;
        if(l > 0){
            root_value += l;
        }
        
        if(r > 0){
            root_value += r;
        }
        max_sum = max(max_sum, root_value);
        
        //确定这一次递归出栈的操作，这里是返回以当前节点为路径向上一层的最大路径和。
        //前面是为了跟新max_sum，接下来是为了完成递归的出栈
        if(max(l, r) > 0){
            return max(l, r) + root->val;
        }
        else{
            return root->val;
        }
    }
private:
    int max_sum=INT_MIN;
};

/*
114. Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

1
/ \
2   5
/ \   \
3   4   6
The flattened tree should look like:
1
\
2
\
3
\
4
\
5
\
6
*/
//安装前序遍历的顺序进行flatten
递归，习惯树的节点操作
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        TreeNode* cur;
        if(root->left!=NULL){
            cur=root->left;
            while(cur->right!=NULL){
                cur=cur->right;
            }
            cur->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        flatten(root->right);
    }
};
/*
循环
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root != NULL){
            TreeNode* cur;
            if(root->left != NULL){
                cur = root->left;
                while(cur->right != NULL){
                    cur = cur->right;
                }
                cur->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};

