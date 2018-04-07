//
//  main.cpp
//  sward offer
//
//  Created by 熊飞 on 2018/2/8.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <iostream>
#include <stack>
#include <exception>
#include <queue>
using namespace std;

//第二章

/*
 有序二维数组查找问题，考虑边界点，并且进行行列筛减
 */
bool Find(int *matrix, int rows, int columns, int number)
{
    bool found=false;
    if(matrix!=NULL && rows>0 && columns>0)
    {
        //设置两个游标
        //数组索引
        int row=0;
        int column=columns-1;
        //检索终止条件
        while(row<rows&& column>=0)
        {
            if(matrix[row*columns+column]==number)
            {
                found=true;
                break;
            }
            else if(matrix[row*columns+column]>number)
                column--;
            else
                row++;
        }
    }
    return found;
}
/*
 替换字符串中的字符，考虑字符串中的长度增加问题。
 思路：
 先遍历字符串，找出需要替换的字符的数量，确定好新的字符串的长度后，确定两个指针，分别指向新字符串的尾和旧字符串的尾。
 然后依次从后往前进行复制。最终计算复杂度为O(n)，注意判定字符串越界是‘\0’
 */
void ReplaceBlank(char string[],int length)
{
    //检查参数
    if (string==NULL||length<=0)
        return;
    //特殊字符为空格' '
    int old_length=0;
    int new_length=0;
    int number_blank=0;
    int i=0;
    while(string[i]!='\0')
    {
        old_length++;
        if(string[i]==' ')
            number_blank++;
        i++;
    }
    new_length=old_length+number_blank*2;
    //不创造新的数组的策略，判定是否有足够的存储空间
    if(new_length>length)
        return;
    int old_index=old_length;
    int new_index=new_length;
    while(old_index!=new_index)
    {
        if(string[old_index]==' ')
        {
            string[new_index--]='0';
            string[new_index--]='2';
            string[new_index--]='%';
        }
        else
        {
            string[new_index--]=string[old_index];
        }
        old_index--;
    }
}
/*
 合并两个有序数组或者字符串，并保持有序
 思路：
 设置三个工作指针，注意边界条件
 */
void MergeSortarrays(int a[],int b[],int len_a, int len_b)
{
    if(len_a<=0||len_b<=0)
        return;
    int merge_index=len_a+len_b-1;
    int index_a=len_a-1;
    int index_b=len_b-1;
    while(index_b>=0)
    {
        if(a[index_a]>b[index_b]||index_b<0)
        {
            a[merge_index--]=a[index_a--];
        }
        else if(a[index_a]<=b[index_b]||index_a<0)
        {
            a[merge_index--]=b[index_b--];
        }
    }
}
/*
链表操作
 */
struct ListNode
{
    int value;
    ListNode* next;
};
//尾插入
/*
 ListNode** head   头指针：指向指针的指针
 ListNode* cur=*head 头结点：指向ListNode结构的指针
 */
void Addtotail(ListNode** head,int value)
{
    ListNode* node=new ListNode();
    node->value=value;
    node->next=NULL;
    if(head==NULL)
    {
        *head=node;
    }
    else
    {
        ListNode* cur=*head;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=node;
    }
}
/*
 删除第一个找到的含有某值得结点并删除
 */
void RemoveNode(ListNode** head,int value)
{
    //头指针为空或不存在头结点
    if(head==NULL||*head==NULL)
    {
        return;
    }
    //删除时，用于记录，并且及时销毁
    ListNode* tmp_node=NULL;
    //删除第一个节点
    if((*head)->value==value)
    {
        tmp_node=*head;
        *head=(*head)->next;
    }
    else
    {
        ListNode* cur=*head;
        while(cur->next!=NULL&&cur->next->value!=value)
            cur=cur->next;
        if(cur->next!=NULL&&cur->next->value==value)
        {
            tmp_node=cur->next;
            cur->next=cur->next->next;
        }
    }
    //销毁
    if(tmp_node!=NULL)
    {
        delete tmp_node;
        tmp_node=NULL;
    }
}
/*
 从头到尾打印链表
 思路：
 1，改变链表结构，首先翻转链表，然后依次打印
 2，不改变，栈（鲁棒性高）递归（层数太多会造成栈溢出）
 */
//思路1
void printListReversing(ListNode* head)
{
    if(head==NULL||head->next==NULL)
        return;
    ListNode* pre=NULL;
    ListNode* cur=head;
    ListNode* net=NULL;
    while(cur!=NULL)
    {
        net=cur->next;
        cur->next=pre;
        pre=cur;
        cur=net;
    }
    //最终pre为新的头结点
    while(pre->next!=NULL)
    {
        cout<<pre->value<<endl;
        pre=pre->next;
    }
}
//思路2，stack 先入后出
void printList_reverse_stack(ListNode* head)
{
    //定义一个栈结构
    stack<ListNode*> nodes;
    ListNode* cur=head;
    while(cur->next!=NULL)
    {
        nodes.push(cur);
        cur=cur->next;
    }
    while(!nodes.empty())
    {
        cur=nodes.top();
        cout<<cur->value<<'\t'<<endl;
        nodes.pop();
    }
}
//思路2，递归
void printList_reverse_recursive(ListNode* head)
{
    if(head!=NULL)
    {
        if(head->next!=NULL)
        {
            printList_reverse_recursive(head->next);
        }
        cout<<head->value<<endl;
    }
}
//特殊测试：链表只有一个节点，链表头结点为空
/*
 树的遍历：前序遍历，中序遍历，后序遍历，宽度优先遍历
 树的特殊结构：二叉树，二叉搜索树，堆，红黑树
 */

//栈和队列
//两个栈实现一个队列，两个队列实现一个栈一样的思路
template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};

template<typename T> void CQueue<T>::appendTail(const T& element)
{
    stack1.push(element);
}

template <typename T> T CQueue<T>::deleteHead()
{
    if(stack2.size()<=0)
    {
        while(stack1.size()>0)
        {
            T &data=stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if(stack2.size()==0)
    {
        throw new runtime_error("queue is empty");
    }
    T head=stack2.top();
    stack2.pop();
    return head;
}


template <typename T>
class CStack
{
public:
    CStack(void);
    ~CStack(void);
    void add_push(const T& node);
    T delete_pop();
private:
    queue<T> Queue1;
    queue<T> Queue2;
};

template <typename T>
void CStack<T>::add_push(const T& element)
{
    Queue1.push(element);
}

template <typename T>
T CStack<T>::delete_pop()
{
    if(Queue2.size()<=0)
    {
        while(Queue1.size>0)
        {
            T &data=Queue1.front();
            Queue1.pop();
            Queue2.push(data);
        }
    }
    if(Queue2.size()==0)
    {
        throw new runtime_error("stack is empty");
    }
    T head=Queue2.pop();
    return head;
}

/*
 算法和数据操作：
 二分查找，归并排序，快速排序
 */
//算法是需要适应问题的，虽然快速排序的平均效率是最好的，但是对于有序数组，快速排序的效率只有O(n2)
//比如，如果数字的大小在较小的范围，并且可以使用辅助空间，那么可以通过桶排序来实现，例如排序，保证时间效率为O(n)
void SortAges(int ages[], int length)
{
    if(ages==NULL||length<=0)
        return;
    //不修改的变量设置为常量
    const int oldestAge=99;
    int Age_block[oldestAge+1];
    for(int i=0;i<=oldestAge;i++)
    {
        Age_block[i]=0;
    }
    //排序
    for(int i=0;i<length;i++)
    {
        int age=ages[i];
        if(age<0||age>oldestAge)
        {
            throw new runtime_error("age out of range");
        }
        ++Age_block[age];
    }
    int index=0;
    for(int i=0;i<=oldestAge;++i)
    {
        for(int j=0;j<Age_block[i];j++)
        {
            ages[index]=i;
            ++index;
        }
    }
}

/*
 旋转数组的最小数字
 思路：二分查找
 1，正常递增数组
 2，对0的旋转，首元素就最小值
 3，index1,mid,index2指向的数字都相同，顺序查找
 */

int MininOrder(int* numbers,int index1, int index2)
{
    int result=numbers[index1];
    for(int i=index1+1;i<index2;i++)
    {
        if(result>numbers[i])
        {
            result=numbers[i];
        }
    }
    return result;
}

int Min(int* numbers,int length)
{
    if(numbers==NULL||length<=0)
        throw new runtime_error("Invalid parameters");
    if(length==1)
        return numbers[0];
    int index1=0;
    int index2=length-1;
    int mid=index1;
    while(numbers[index1]>=numbers[index2])
    {
        if(index2==index1-1)
        {
            mid=index2;
            break;
        }
        mid=(index1+index2)/2;
        if(numbers[index1]==numbers[mid]&&numbers[index1]==numbers[index2])
        {
            //顺序查找
            return MininOrder(numbers,index1,index2);
        }
        else
        {
            if(numbers[index1]<=numbers[mid])
            {
                index1=mid;
            }
            if(numbers[mid]<=numbers[index2])
            {
                index2=mid;
            }
        }
    }
    return numbers[mid];
}

/*
 递归和循环
 重复计算相同的问题的时候可以选择递归和循环
 优缺点分析：
 一般而言递归的形式比循环简单，但是
 1，重复函数调用对空间和时间更损耗
 2，计算有可能会是重复的
 3，会导致调用栈溢出
 */
long long Fibonacci(unsigned n)
{
    int result[2]={1,2};
    if(n<2)
    {
        return result[n];
    }
    long long ONE=0;
    long long TWO=1;
    long long N=0;
    for(unsigned i=2;i<n;i++)
    {
        N=ONE+TWO;
        ONE=TWO;
        TWO=N;
    }
    return N;
}
//斐波那契数列相关问题
/*
 1，青蛙跳楼梯
 2，小矩形填充
 分析问题时，分析开始时的选择情况和后面的剩下情况是否可以是递归的形式。
 */

/*
 位运算
 1,任意进制的转换
 2，位运算：与，或，异或，左移，右移(如果是无符号数，补零，有符号数补符号位)
 3，右移计算相对于除法效率要高的多
 */
//任意进制相互转换

//输出二进制中1的数量
int Numberof1(int n)
{
    int count=0;
    unsigned int flag=1;
    while(flag)
    {
        if(n&flag)
            count++;
        flag=flag<<1;
    }
    return count;
}

//特殊技巧，一个整数减去1，再和原整数做与运算，会把该整数最右边的1变成0
int Numberof1_sp(int n)
{
    int count=0;
    while(n)
    {
        count++;
        n=(n-1)&n;
    }
    return count;
}


//判断一个数是不是2的整数次方
int Numberis2(int n)
{
    return n&(n-1)?false:true;
}

//判断两个整数的二进制表达形式的编辑距离
int distant(int n,int m)
{
    return Numberof1_sp(n^m);
}


int main(int argc, const char * argv[]) {
    cout<<Numberis2(4)<<endl;
}
