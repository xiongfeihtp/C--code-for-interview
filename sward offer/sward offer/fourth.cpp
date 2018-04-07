//
//  fourth.cpp
//  sward offer
//
//  Created by 熊飞 on 2018/2/10.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <assert.h>
#include <exception>

using namespace std;
/*
 第四章
 画图是面试过程中帮助自己分析、推理的手段，还能够给面试官更清晰的讲解
 */
//二叉树的镜像
/*
 前序遍历二叉树结构，在左右子树都存在的时候，交换
 */
struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

void MirrorRecursively(BinaryTreeNode* Root)
{
    if(Root==NULL)
        return;
    if(Root->left==NULL||Root->right==NULL)
        return;
    //交换左右子树
    BinaryTreeNode* tmp=Root->left;
    Root->left=Root->right;
    Root->right=tmp;
    //收回tmp指向的内存
    delete tmp;
    //置空指针
    tmp=NULL;
    //前序遍历
    if(Root->left)
    {
        MirrorRecursively(Root->left);
    }
    if(Root->right)
    {
        MirrorRecursively(Root->right);
    }
}

//打印矩阵，从外向里以顺时针的顺序依次打印出每一个数字
/*
 分析边界条件和特殊情况，画图辅助
 */
void printNumber(int number)
{
    cout<<"->"<<number;
}
//打印函数，将打印分成有限步，并分析特殊情况，跳过一些步骤
void Printcircle(int** numbers,int columns,int rows,int start)
{
    int endX=columns-1-start;
    int endY=rows-1-start;
    //->打印一行
    for(int i=start;i<=endX;i++)
    {
        int number=numbers[start][i];
        printNumber(number);
    }
    
    if(start<endY)
    {
        for(int i=start+1;i<=endY;i++)
        {
            int number=numbers[i][endX];
            printNumber(number);
        }
    }
    
    if(start<endX && start<endY)
    {
        for(int i=endX-1;i>=start;i--)
        {
            int number=numbers[endY][i];
            printNumber(number);
        }
    }
    
    if(start<endX && start<endY-1)
    {
        for(int i=endY-1;i>=start+1;i--)
        {
            int number=numbers[i][endX];
            printNumber(number);
        }
    }
}

void printMatrixClockwisely(int** numbers,int columns,int rows)
{
    if(numbers==NULL||columns<=0||rows<=0)
        return;
    int start=0;
    while(columns>start*2&&rows>start*2)
    {
        Printcircle(numbers, columns, rows, start);
        start++;
    }
}

//实现栈的数据结构，得到栈的最小元素min函数，并且min,push,pop的时间复杂度都是O(1)
//构造一个数据栈和辅助栈，辅助栈每次压入的是此时的最小元素，弹出和push时，需要同时弹出和push两个栈结构

//tips：C++中引入了常量引用机制，引用最用要的意义在于作为函数的参数，以扩充函数传递参数的能力，实现真正的变量传递。
//希望传入一个对象，又不想让函数体修改这个对象。const T& value
//在类中的使用，返回一个类的成员，但不希望调用方修改这个成员，const T& min();
template <typename T>
class StackWithMin
{
public:
    StackWithMin(void);
    ~StackWithMin(void);
    void push(const T& value);
    void pop();
    const T& min();
private:
    stack<int> m_data;
    stack<int> m_min;
};

template <typename T>
void StackWithMin<T>::push(const T& value)
{
    m_data.push(value);
    if(m_min.size()==0||value<m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

template <typename T>
void StackWithMin<T>::pop()
{
    assert(m_data.size()>0 && m_min.size()>0);
    m_data.pop();
    m_min.pop();
}

template <typename T>
const T& StackWithMin<T>::min()
{
    assert(m_data.size()>0 && m_min.size()>0);
    return m_min.top();
}

//判定栈的压入和弹出序列
/*
 思路：
 1，创建一个辅助栈
 2，遍历pop序列，当辅助栈的栈顶元素不是的时候，依次push，当是栈顶元素时就弹出，并继续遍历
 3，当最后元素全部pop并且辅助栈为空时，判定为相似序列，否则不相似
 */
bool IsPopOrder(const int* pPush,const int* pPop, int nLength)
{
    bool bPossible=false;
    if(pPush!=NULL && pPop!=NULL && nLength>0)
    {
        //定义两个工作指针
        const int* pPush_point=pPush;
        const int* pPop_point=pPop;
        stack<int> stackData;
        //遍历pop序列
        while(pPop_point-pPop<nLength)
        {
            //遍历push序列，直到pPop_point的元素位于栈顶
            while(stackData.empty()||stackData.top()!=*pPop_point)
            {
                if(pPush_point-pPush==nLength)
                    break;
                stackData.push(*pPush_point);
                pPush_point++;
            }
            if(stackData.top()!=*pPop_point)
                break;
            stackData.pop();
            pPop_point++;
        }
        //如果最终遍历全部成功，stackData没有元素则表示是相同的栈过程
        if(stackData.empty()&&pPop_point-pPop==nLength)
            bPossible=true;
    }
    return bPossible;
}
//广度优先遍历二叉树
/*
 思路：
 遍历的过程满足先入先出的原则，可以维护一个辅助队列
 tips：
 deque的操作:
 deque<Type> k;      ------      定义一个deque的变量(定义时已经初始化)      例如: deque<int> k;

 k.empty()      ------      查看是否为空范例,是的话返回1,不是返回0
 
 k.clear()      ------      清除队列里的所有数据
 
 k.push_front(i)      ------      从已有元素前面增加元素i(队伍大小不预设)
 
 k.push_back(i)      ------      从已有元素后面增加元素i(队伍大小不预设)
 
 k.pop_front()      ------      清除第一个元素
 
 k.pop_back()      ------      清除最后一个元素
 
 k.front()      ------      显示第一个元素      例如n = k.front();
 
 k.back()      ------      显示最后一个元素
 
 k.size()      ------      输出现有元素的个数
 */
void PrintFromToptoBottom(BinaryTreeNode* Root)
{
    if(Root==NULL)
        return;
    //deque中保存的是二叉树节点
    deque<BinaryTreeNode* >dequeTreeNodes;
    //加入根节点
    dequeTreeNodes.push_back(Root);
    //直到打完所有节点
    while(!dequeTreeNodes.empty())
    {
        //打印出队节点
        BinaryTreeNode* curNode=dequeTreeNodes.front();
        dequeTreeNodes.pop_front();
        cout<<curNode->value<<endl;
        if(curNode->left!=NULL)
        {
            dequeTreeNodes.push_back(curNode->left);
        }
        if(curNode->right!=NULL)
        {
            dequeTreeNodes.push_back(curNode->right);
        }
    }
}
//拓展：不管是广度优先遍历一个有向图还是一棵树，都需要用到队列，第一步将初始点放入队列中，然后每一次从队列的头部取出一个节点，并且遍历这个节点之后可以到达的节点，并以此放入队列当中


//二叉搜索树的后序遍历序列
//二叉搜索树需要满足所有左树节点值小于根节点，所有的右树节点值大于根节点
bool VerifySequenceOfBST(int sequence[],int length)
{
    if(sequence==NULL||length<=0)
        return false;
    //找到根节点
    int root_value=sequence[length-1];
    //定位左子树
    int i=0;
    for(;i<length-1;i++)
    {
        if(sequence[i]>root_value)
            break;
    }
    int j=i;
    for(;j<length-1;j++)
    {
        if(sequence[j]<root_value)
            return false;
    }
    //左子树序列[0,i-1] 右子树序列[i,length-2]
    //转换为相同的输入形式
    bool left=true;
    if(i>0)
    {
        left=VerifySequenceOfBST(sequence, i);
    }
    bool right=true;
    if(i<length-1)
    {
        right=VerifySequenceOfBST(sequence+i,length-i-1);
    }
    return (left && right);
}
//tips：此解法也使用于二叉搜索树的前序遍历，当面试题是处理一课二叉树的遍历序列时，我们可以先找到二叉树的根结点，然后将树拆分成两个部分，再继续递归的调用和处理两个子序列，最后合并结果。


/*
 vector迭代器
 std::vector<int>::iterator iter=path.begin();
 for(;iter!=path.end();iter++)
    std::cout<<*iter;
 */
//打印所有满足一定条件的二叉树路径，这里的条件是路径结点之和一定。因为stack每次只能访问栈顶元素，这里采用vector更加方便打印路径，这里是通过迭代器来实现。这里也可以视为回溯问题的一般解法，通过栈来保存结果。
void FindPath(BinaryTreeNode* Root,int Sum_value, vector<int>& path, int currentSum)
{
    currentSum+=Root->value;
    path.push_back(Root->value);
    //判断是否满足条件，叶结点，和。
    bool isleaf=(Root->left==NULL)&&(Root->right==NULL);
    if(currentSum==Sum_value&&isleaf)
    {
        cout<<"A path is found: ";
        //迭代器遍历vector
        vector<int>::iterator iter=path.begin();
        for(;iter!=path.end();iter++)
            cout<<*iter;
        cout<<endl;
    }
    if(Root->left!=NULL)
    {
        FindPath(Root->left,Sum_value,path,currentSum);
    }
    if(Root->right!=NULL)
    {
        FindPath(Root->right,Sum_value,path,currentSum);
    }
    //这里currentSum进行的是值传递，所以回溯的时候还是原来传入时的值，所以不需要减去
    path.pop_back();
}
void FindPath(BinaryTreeNode* Root,int Sum_value)
{
    if(Root==NULL)
        return;
    vector<int> path;
    int currentsum=0;
    FindPath(Root, Sum_value, path, currentsum);
}

//分解复杂问题
/*
 1，纵向分解，分解成解决问题的步骤
 2，横向分解，分解成子问题(递归)
 */

//复杂链表复制
/*
 思路：
 1，复制原始链表，并定位原始复杂链表的复合链接，计算复杂度O(n2)
 2,空间获取时间，在复制原始链表的时候，通过创建<N,N'>的hashtable，通过O(1)进行定位，空间复杂度O(n)
 3,通过将链表合并复制，并进行复合链接复制和再拆分，同样是O(n)但是没有消耗空间。
 */
struct ComplexListNode
{
    int value;
    ComplexListNode* next;
    ComplexListNode* pin;
};
//联合复制
void CloneNodes(ComplexListNode* head)
{
    ComplexListNode* cur=head;
    while(cur!=NULL)
    {
        //新建的过程new，右边分配创建空间，左边创建指针
        ComplexListNode* cloneNode=new ComplexListNode();
        cloneNode->value=cur->value;
        //添加节点在head之后
        cloneNode->next=cur->next;
        cloneNode->pin=NULL;
        //初始化任何类或者变量一定记得赋予初始值，这里容易忘记给cloneNode->pin=NULL;
        cur->next=cloneNode;
        //cur移动到下一个原链表
        cur=cloneNode->next;
    }
}
//定位pin，定义两个工作指针
void ConnectPin(ComplexListNode* head)
{
    ComplexListNode* cur_raw=head;
    while(cur_raw!=NULL)
    {
        //这句话放到循环外和循环内对边界条件有影响，注意分析，不要有NULL->next的操作
        ComplexListNode* cur_clone=cur_raw->next;
        if(cur_raw->pin!=NULL)
        {
            cur_clone->pin=cur_raw->pin->next;
        }
        cur_raw=cur_clone->next;
    }
}

ComplexListNode* Reconnected(ComplexListNode* head)
{
    //赋值一个链表，需要两个工作指针，一个保存头，一个游标用于移动和遍历
    //初始化多结点时，不要赋值，方便后面计算边界条件
    ComplexListNode* raw_cur=head;
    ComplexListNode* cloned_cur=NULL;
    ComplexListNode* cloned_head=NULL;
    //保证raw_cur在所有结点的前面，这样可以通过NULL来判断
    if(raw_cur!=NULL)
    {
        cloned_head=cloned_cur=raw_cur->next;
        raw_cur=cloned_head->next;
        raw_cur=raw_cur->next;
    }
    while(raw_cur!=NULL)
    {
        cloned_cur->next=raw_cur->next;
        cloned_cur=cloned_cur->next;
        raw_cur->next=cloned_cur->next;
        raw_cur=raw_cur->next;
    }
    return cloned_head;
}
ComplexListNode* Clone(ComplexListNode* head)
{
    if(head==NULL)
        return NULL;
    CloneNodes(head);
    ConnectPin(head);
    return Reconnected(head);
}

/*
 转换二叉搜索树到双向排序链表，并要求不能创建任何新的节点
 思路：
 按照中序遍历二叉搜索树，从小到大。当遍历到根节点时，左子树已经转换为一个排序的链表，然后将根结点和左子树中最后一个结点相连，然后去遍历转换右子树，构成递归逻辑。
 书写程序时，输出双向链表的头结点，递归的时候需要在双向链表的尾结点增加结点（遍历搜索的最大值）
 */
void ConvertNode(BinaryTreeNode* Root,BinaryTreeNode** LastNodeinLink)
{
    if(Root==NULL)
        return;
    BinaryTreeNode* cur=Root;
    if(cur->left!=NULL)
        ConvertNode(cur->left,LastNodeinLink);
    //双向连接
    cur->left=*LastNodeinLink;
    if(*LastNodeinLink!=NULL)
        (*LastNodeinLink)->right=cur;
    //完成左子树和根结点
    *LastNodeinLink=cur;
    //遍历转换右子树
    if(cur->right!=NULL)
    {
        ConvertNode(cur->right, LastNodeinLink);
    }
}

BinaryTreeNode* Convert(BinaryTreeNode* Root)
{
    BinaryTreeNode* LastNodeinLink=NULL;
    ConvertNode(Root,&LastNodeinLink);
    //LastNodeinLink为双向链表的尾结点，需要向前遍历，输出头结点
    BinaryTreeNode* HeadNodeinLink=LastNodeinLink;
    //可以根据位移的方式，边界条件
    while(HeadNodeinLink!=NULL && HeadNodeinLink->left!=NULL)
        HeadNodeinLink=HeadNodeinLink->left;
    return HeadNodeinLink;
}

//输出字符串的全排列
/*
 思路：
 一次固定一个字母的位置并求所有的空字符，然后递归求取后面的字符的全排列
 
 字符串输入
 char pstr[]="abc";
 */
//程序运行处bug，后面没有进行递归，递归时的输入有问题,for循环的cur执行的是交换，既给出当前位置的所有可能，继续进入递归的是下一个位置也就是changeStr+1
void Permutation(char* sourceStr,char* changeStr)
{
    assert(sourceStr&&changeStr);
    if(*changeStr=='\0')
    {
        cout<<sourceStr<<'\t';
        return;
    }
    else
    {
        for(char* cur=changeStr;*cur!='\0';cur++)
        {
            //交换指针指向的内容
            char temp=*cur;
            *cur=*changeStr;
            *changeStr=temp;
            Permutation(sourceStr,changeStr+1);
            temp=*cur;
            *cur=*changeStr;
            *changeStr=temp;
        }
    }
}
void Permutation_main(char* sourceStr)
{
    if(sourceStr==NULL)
        return;
    Permutation(sourceStr,sourceStr);
}
//引申出的全排列问题
/*
 全排列去重问题，从一个数起分别于它后面非重复出现的数字交换
 */
bool IsSwapable(char* changeStr,char* cur)
{
    //cur在changeStr和cur-1之间是否出现过
    char *p;
    for(p=changeStr;p<cur;p++)
    {
        if(*p==*cur)
            return false;
    }
    return true;
}
//问题，重写函数进行递归调用时，调用错了。
void Permutation_delete(char* sourceStr,char* changeStr)
{
    assert(sourceStr&&changeStr);
    if(*changeStr=='\0')
    {
        //问题1 局部静态变量
        static int num=1;
        printf("第%d个排列\t%s\n",num++,sourceStr);
        return;
    }
    else
    {
        for(char* cur=changeStr;*cur!='\0';cur++)
        {

            if(IsSwapable(changeStr,cur))
            {
                //交换指针指向的内容
                char temp=*cur;
                *cur=*changeStr;
                *changeStr=temp;
                Permutation_delete(sourceStr,changeStr+1);
                temp=*cur;
                *cur=*changeStr;
                *changeStr=temp;
            }
        }
    }
}
/*
 字符全组合问题
 思路：
 扫描到某个字符，有两种选择，一种是放入组合并在剩下的n-1个字符中选m-1个字符，另外一种是放入组合，则在剩下的n-1个字符中选m个字符，递归结束条件，达到m的上限，或者已经选完。
 */
//容器在递归函数的传递过程引用
void Combiantion(char* string,int number,vector<char> &result)
{
    assert(string);
    if(number==0)
    {
        static int num=1;
        printf("第%d个组合\t",num++);
        vector<char>::iterator iter=result.begin();
        for(;iter!=result.end();iter++)
        {
            printf("%c",*iter);
        }
        printf("\n");
        return;
    }
    if(*string=='\0')
        return;
    result.push_back(*string);
    Combiantion(string+1, number-1,result);
    result.pop_back();
    Combiantion(string+1, number, result);
}
void Combination_main(char* string)
{
    assert(string);
    vector<char> result;
    int length=strlen(string);
    //输出1到length的全组合
    for(int i=1;i<=length;i++)
    {
        Combiantion(string,i,result);
    }
}
/*
 找出一个数组中出现次数超过数组长度一半的数
 */
/*
 快速排序的思路：如果存在，排序之后n/2位置的数一定是次数超过一半的数，会交换原数组中元素
 */
int RandomInRange(int start, int end)
{
    return start;
}


int Partition(int data[], int length, int start, int end)
{
    if(data==NULL||length<=0||start<0||end>=length)
        throw new runtime_error("Invalid Parameters");
    int index=RandomInRange(start,end);
    int tmp=data[index];
    data[index]=data[end];
    data[end]=tmp;
    int small=start-1;
    for(index=start;index<end;++index)
    {
        if(data[index]<data[end])
        {
            ++small;
            if(small!=index)
            {
                tmp=data[index];
                data[index]=data[small];
                data[small]=tmp;
            }
        }
    }
    ++small;
    tmp=data[small];
    data[small]=data[end];
    data[end]=tmp;
    return small;
}

void QuickSort(int data[], int length, int start, int end)
{
    if(start==end)
        return;
    int index=Partition(data,length,start,end);
    if(index>start)
        Partition(data, length, start, index-1);
    if(index<end)
        Partition(data, length, index+1, end);
}

bool InputError=false;
bool CheckResult(int *numbers,int length,int result)
{
    int times=0;
    for(int i=0;i<length;i++)
    {
        if(numbers[i]==result)
            times++;
    }
    bool isMoreThanHalf=true;
    if(times*2<=length)
    {
        isMoreThanHalf=false;
        InputError=true;
    }
    return isMoreThanHalf;
}
int MoreThanHalfNum(int *numbers,int length)
{
    if(numbers==NULL||length<=0)
        InputError=true;
    int mid=length>>1;
    int start=0;
    int end=length-1;
    int index=Partition(numbers, length, start, end);
    while(index!=mid)
    {
        if(index>mid)
        {
            end=index-1;
            index=Partition(numbers, length, start, end);
        }
        else
        {
            start=index+1;
            index=Partition(numbers, length, start, end);
        }
    }
    int result=numbers[mid];
    if(!CheckResult(numbers,length,result))
        result=0;
    return result;
}

/*
 思路2：
 说明一个数字的次数比其他所有次数都要多
 */
int MoreThanHalfNum_2(int *numbers,int length)
{
    if(numbers==NULL||length<=0)
        return 0;
    int result=numbers[0];
    int times=1;
    for(int i=1;i<length;i++)
    {
        if(times==0)
        {
            result=numbers[i];
            times=1;
        }
        else if(numbers[i]==result)
            times++;
        else
            times--;
    }
    if(!CheckResult(numbers, length, result))
        result=0;
    return result;
}

/*
 找出数组中最小的k个数
 */
/*
 思路一：
 快速排序思路 O(n)
 */
void GetLeastNumbers(int* numbers,int length, int k)
{
    if(numbers==NULL||k>length||length<=0||k<=0)
        return;
    int start=0;
    int end=length-1;
    int index=Partition(numbers, length, start, end);
    while(index!=k-1)
    {
        if(index>k-1)
        {
            end=index-1;
            Partition(numbers, length, start, end);
        }
        else
        {
            start=index+1;
            Partition(numbers, length, start, end);
        }
    }
    for(int i=0;i<k;i++)
    {
        cout<<numbers[i];
    }
}

/*
 海量数据队列输入，不能采取快排思路因为不能一次导入所有数据O(nlogk)，维护一个最大堆，或者采取其他的容器
 */
//维护一个容量为k的容器，因为要进行重复删除和查询，所以采用最大堆或者红黑树
#include <set>
#include <functional>
//实现最大堆 greater<int>之后默认为降序排列，类似的还有升序less<int>
/*
 // TEMPLATE STRUCT greater
 emplate<class _Ty>
 struct greater
 : public binary_function<_Ty, _Ty, bool>
 {   // functor for operator>
 bool operator()(const _Ty& _Left, const _Ty& _Right) const
 {   // apply operator> to operands
 return (_Left > _Right);
 }
 };
 
类似与调用操作符和函数对象
 struct absInt
 {
    int operator (int val)
    {
        return val<0?-val:val;
    };
 };
 调用
 int i=-42;
 absInt absF;
 unsigned int ui=absF(i);
 
 或者:
 #include<iostream>
 #include<algorithm>//因为用了sort()函数
 #include<functional>//因为用了greater<int>()
 using namespace std;
 void main()
 {
     int a[]={3,1,4,2,5};
     int len=sizeof(a)/sizeof(int);//这里切记要除以sizeof(int)!
     sort(a,a+len,greater<int>());//内置类型的由大到小排序
     for(int i=0;i<len;i++)
     cout<<a[i]<<" ";
 }
 */
typedef multiset<int,greater<int>> intSet;
typedef multiset<int,greater<int>>::iterator setIterator;
void GetLeastNumbers(const vector<int> &data, intSet &leastNumbers,int k)
{
    //清空容器
    leastNumbers.clear();
    //检查输入
    if(k<=0||data.size()<k)
        return;
    //遍历vector
    //const vector<int>::iterator，指针不能移动
    //const_iterator 传递来的容器存的const对象
    //iterator
    //iterator可以改元素值,但const_iterator不可改
    vector<int>::const_iterator iter=data.begin();
    for(;iter!=data.end();iter++)
    {
        if(leastNumbers.size()<k)
            leastNumbers.insert(*iter);
        else
            //替换最大堆
        {
            //遍历找到*iter的位置并进行替换
            //最大值在起点
            //拿出堆顶元素
            setIterator iter_k=leastNumbers.begin();
            if(*iter<*(leastNumbers.begin()))
            {
                //删除元素和添加元素的操作
                leastNumbers.erase(iter_k);
                leastNumbers.insert(*iter);
            }
        }
    }
}
int main()
{
    const vector<int> data={1,2,4,5,3,5,6,2,5,7,5};
    intSet numbers;
    GetLeastNumbers(data,numbers,3);
    setIterator iter=numbers.begin();
    for(;iter!=numbers.end();iter++)
        cout<<*iter<<" ";
    return 0;
}






