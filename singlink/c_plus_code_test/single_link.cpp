//  single_link.cpp
//  c_plus_code_test
//
//  Created by 熊飞 on 2018/2/2.
//  Copyright © 2018年 熊飞. All rights reserved.
//

//默认带头结点,结点的实际含义是同时包含数据域和指针域，结点的传递实际上传递的是指针域
//不管进行任何操作，一定要保证结点有上级
#define ERROR 0
#define OK 1
typedef int Status;
typedef int ElemType;

//为定义的数据类型定义一个新名字Node
typedef struct Node{
    ElemType data;
    struct Node *next //指向下一个节点
}Node;

//就是把 struct Node * 定义成了新类型 LinkList。这个类型是一个结构体的指针。
typedef struct Node *LinkList;

//链表初始化 L头指针,*L头结点
Status InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(Node)); //产生一个头结点
    if(!(*L))
    {
        return ERROR;
    }
    (*L)->next=NULL; //头结点指针域为NULL
    return OK;
}
int main()
{
    LinkList L; //定义了一个指向Node的指针，头指针
    InitList(&L); //初始化链表
}

//随机产生n个元素，创建带表头结点的单链表L,头插法
void CreateListHead(LinkList *L,int n)
{
    //L指针型变量,头指针
    LinkList p; //待插入结点
    int i;
    srand(time(0));
    //生成一个头结点
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;
    for (i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(Node)); //生成一个待插入结点，连续创建的语法
        p->data=rand()%100+1;
        p->next=(*L)->next; //指向头结点原来指的地方
        (*L)->next=p;
    }
}
void CreateListTail(LinkList *L,int n) //尾插法
{
    LinkList p,r;//p待插入结点,r记录指针
    int i;
    srand(time(0));
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;
    r=*L;
    for(i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1; //生成一个随机结点
        //插入尾部
        r->next=p;
        r=p;
    }
    r->next=NULL
}
//L代表头指针
LinkList ListReverse(LinkList L)
{
    LinkList pre,cur,net;
    if(L==NULL||L->next==NULL)
        return L;
    pre=L->next //头结点
    cur=pre->next;
    while(cur)
    {
        net=cur->next; //保证cur->next的上级存在
        cur->next=pre; //修改顺序
        pre=cur;
        cur=net;
    }
    //退出时cur=None
    L->next=pre;
    return L;
}

//查找单链表倒数第N个节点值，距离-标尺
//删除单链表的倒数第K个结点 K>1&&K<N
ElemType GetNthNodFromBack(Linklist L,int n)
{
    if(!L) return NULL;
    int i=0;
    LinkList firstNode=L;
    //第一个节点走到第n个位置
    while(i<n && firstNode->next !=NULL)
    {
        i++;
        firstNode=firstNode->next;
        printf("%d\n",i);
    }
    //n输入错误
    if(firstNode->next==NULL&& i<n-1)  //i=0 n-1   i=1 n
    {
        printf('超出链表长度\n');
        return ERROR;
    }
    LinkList secNode=L;
    //第一个节点走到尾部
    while (firstNode!=NULL)
    {
        secNode=secNode->next;
        firstNode=firstNode->next;
    }
    //返回结点
    *e=secNode->data;
    return OK;
    
    LinkList temp;
    //删除结点，一种是交换倒数第k个元素和它后一个元素的data,非尾元素
    secNode->data=secNode->next->data;
    temp=secNode->next;
    secNode->next=secNode->next->next;
    free(temp);
    temp=NULL; //避免变成野指针
}
//如何快速找到未知长度单链表的中间结点
//普通的方法很简单，首先遍历一遍单链表以确定单链表的长度L。然后再次从头节点出发循环L/2次找到单链表的中间节点。算法复杂度为O(L+L/2)=O(3L/2)。
//能否再优化一下这个时间复杂度呢？有一个很巧妙的方法：设置两个工作指针*search、*mid都指向单链表的头节点。其中* search的移动速度是*mid的2倍。当*search指向末尾节点的时候，mid正好就在中间了。这也是标尺的思想
Status GetMidNode(LinkList L,ElemType *e)
{
    LinkList search,mid;
    mid=search=L;
    while(search->next=NULL)
    {
        if(search->next->next!=NULL)
        {
            search=search->next->next;
            mid=mid->next;
        }
        else
        {
            search=search->next;
        }
    }
    *e=mid->value;
    return OK;
}

//判断单链表是否有环
int HasLoop(LinkList L)
{
    LinkList p=L
    LinkList q=L;
    while(p!=NULL && q!=NULL &&q->next!=NULL)
    {
        p=p->next;
        if(q->next!=NULL)
        {
            q=q->next->next;
        }
        if (p==q)
            return 1;
    }
    return 0;
}

//删除重复的结点
//移除无序链表中的重复结点
//method1:过程如下：1. 生成一个哈希表，因为头节点不用删除，所以先将头节点存入哈希表中
//        2. 从头节点的下一个节点开始遍历，每遍历到一个节点，记录当前节点cur和它上一个节点pre。先检查cur是否在哈希表中，如果存在则删除cur节点，如果不存在则存入哈希表中。操作完之后移动到下一个节点。
//未完待续


//设置两个指针依次遍历
LinkList RemoveDupNode(LinkList L)
{
    LinkList p,q,r;
    p=L->next;
    while(p)
    {
        q=p;
        if(q->next->data=p->data)
        //删除结点q->next
        {
            r=q->next;
            q->next=r->next;
            free(r);
        }
        else
            q=q->next;
    }
    p=p->next;
    return L;
}
//链表的冒泡排序,两个工作指针，每次进行冒泡到上次的前一个结点
LinkList BubbleSort(LinkList L)
{
    LinkList pre,cur;
    //NULL linklist
    if(L==NULL||L->next==NULL)
        return L;
    pre=L->next;
    while(pre!=cur)
    {
        while(pre->next!=cur) //控制cur在上一次的上一个结点
        {
            if(pre->data>pre->next->data)
            {
                ElemType med=pre->data;
                pre->data=pre->next->data;
                pre->next->data=tmp;
            }
            pre=pre->next
        }
        cur=pre;
        //回到头结点，重新冒泡
        pre=L->next;
    }
    return L;
}

//删除单链表的第i个结点
// 注: (1)设单链表的长度为n，则单链表删除第i个节点时，必须保证 1<= i <= n，否则不合法；
//     (2)当 i=n+1 时，虽然被删除节点不存在，但其前趋节点却存在，它是终端节点；所以，被删节点的直接前趋*p存在，并不意味着被删节点就一定存在，仅当*p存在(即p != NULL)且*p不是终端节点(即p->next != NULL)同时满足 j <= i时，才能确定被删节点存在。此时，算法的时间复杂度是O(n)。
Status ListDelete(LinkList *L,int i,ElemType *e)
{
    int j;
    LinkList p,temp;
    p=*L;
    j=1;
    while(p->next&&j<i)
    {
        p=p->next;
        ++j;
    }
    //经过循环，若最终p为空，或i为0或负数时，都说明位置不合理；
    if(!(p->next)||j>i)
        return ERROR;
    temp=p->next;
    p->next=temp->next;
    free(temp);
}
//以给定值x为基准将链表分割为两部分，所有小于x的结点排在大于或等于x的结点之前。

//循环报数问题
#include <iostream>
//创建循环队列，尾插法
LinkList CreateCycList(int n)
{
    LinkList L=NULL; //头结点
    LinkList p,q;  //尾结点  工作指针
    p=(LinkList *)malloc(sizeof(Node)); //尾节点
    L=p;
    p->data=1;
    for(i=2;i<n;i++)
    {
        q=(LinkList *)malloc(sizeof(Node));
        q->data=2;
        p->next=q;
        p=q;
    }
    p->next=L;
    return L
}

void Josephus(LinkList L,int n, int m, int k)
//L 链表  n 总人数  m报到的数字 从k个人报数
{
    LinkList p,q;
    int i;
    p=q=L->head;
    //找到第k个位置
    for(i=1;i<k;i++)
    {
        q=p;
        p=p->next;
    }
    //开始报数
    while(p->next!=p)
    {
        for(i=1;i<m;i++)
        {
            q=p;
            p=p->next;
        }
        //删除m
        q->next=p->next;
        cout<<p->data<<' ';
        free(p)
        p=q->next;
    }
    cout<<p->data<<endl;
}

//从尾到头打印单链表
//递归实现
void PrintListRevers(LinkList L)
{
    if(L)
    {
        if(L->next)
        {
            PrintListRevers(L->next);
        }
        printf('%d ',L->data);
    }
}
#include <stack>
//当链表非常长的时候，递归实现的会导致函数调用层级很深，可能导致调用栈溢出。用栈不会出现此类情况，显然用栈实现代码的鲁棒性会好一些。
void PrintListRever_stack(LinkList L)
{
    stack<LinkList> NodeStack;
    LinkList cur=L->next; //工作指针
    while(cur!=None)
    {
        NodeStack.push(cur)
        cur=cur->next;
    }
    while(!NodeStack.empty())
    {
        cur=NodeStack.top();
        printf("%d ",cur->data);
        NodeStack.pop();
    }
}

//删除一个不给头单链表的非尾结点
LinkList DelNonTailNode(LinkList node)
{
    assert(node&&node->next);
    node->data=node->next->data;
    LinkList temp=node->next;  //待删除结点
    node->next=node->next->next; //跳过
    free(temp);  //回收
    temp=NULL;
}

//在无给头单链表中节点前插入一个节点
//思路：因为不给头所以只能插在所给位置的后面，所以插在先所给位置的后面，然后再和前面结点的值交换即可。
void InsertNotHeadNode(LinkList pos,ElemType d)
{
    if(LinkList==NULL||LinkList->next==NULL)
        return L;
    LinkList temp;
    temp->data=pos->data;
    temp->next=pos->next;
    pos->next=temp;
    temp->data=d;
}

//单链表排序问题
//冒泡排序
//时间n2 空间n2 最好情况n
void BubbleSort(LinkList L)
{
    if(L==NULL||L->next==NULL)
    {
        return L;
    }
    LinkList p,q;
    p=L->next;
//冒泡循环次数
    while(p!=q)
    {
        while(p->next!=q)
        {
            if(p->data>p->next->data)
            {
                //交换
                ElemType med=p->data;
                p->data=p->next->data;
                p->next->data=med;
            }
            p=p->next;
        }
        //重新冒泡
        q=p;
        p=L->next;
    }
}
//快速排序
//时间 nlgn 空间 1 or nlgn
/*
由于单链表不能像数组那样随机存储，和数组的快排序相比较，还是有一些需要注意的细节：

1、支点的选取，由于不能随机访问第K个元素，因此每次选择支点时可以取待排序那部分链表的头指针。
2、遍历量表方式，由于不能从单链表的末尾向前遍历，因此使用两个指针分别向前向后遍历的策略实效，
事实上，可以可以采用一趟遍历的方式将较小的元素放到单链表的左边。具体方法为：
1)定义两个指针pslow，pfast，其中pslow指向单链表的头结点，pfast指向单链表头结点的下一个结点;
2)使用pfast遍历单链表，每遇到一个比支点小的元素，就令pslow=pslow->next，然后和pslow进行数据交换。
3、交换数据方式，直接交换链表数据指针指向的部分，不必交换链表节点本身。值交换
*/
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
//最终将单链表切成lgn段
LinkList GetKey(LinkList Bnode, LinkList Bnode)
{
    int key=Bnode->data;
    LinkList p,q;
    p=Bnode;
    q=p->next;
    while(q!=Bnode)
    {
        if(q->data<key)
        {
            p=p->next;
            swap(p->data,q->data);
        }
        q=q->next;
    }
    swap(p->data,Bnode->data);
    return p;
}

void QuickSort(LinkList BNode, LinkList SNode)
{
    if(BNode!=SNode)
    {
        LinkList keyNode=GetKey(BNode,SNode)
        QuickSort(BNode,keyNode);
        QuickSort(keyNode,SNode);
    }
}
LinkList sortList(LinkList L)
{
    if(L==NULL||L->next==NULL)
        return L;
    QuickSort(L,NULL);
    return L;
}
//归并排序
//时间 nlgn 空间 1
/*
归并排序的也是基于分治的思想，但是与快排不同的是归并是先划分，然后从底层开始向上合并。
　　归并排序的主要思想是将两个已经排好序的分段合并成一个有序的分段。除了找到中间节点的操作必须遍历链表外，其它操作与数组的归并排序基本相同。
*/
LinkList MergeSort(LinkList L)
{
    if(L==NULL||L->next==NULL)
        return L;
    //分为两个链表
    LinkList L1=L->next;
    LinkList L2=getMid(L);
    L1=MergeSort(L1);
    L2=MergeSort(L2);
    return merge(L1,L2);
}

LinkList getMid(LinkList L)
{
 //和找中间节点的思路一样，但是多了链表分开的机制，指向为NULL
    LinkList fast=L->next;
    LinkList slow=L->next;
    LinkList pre;
    while(true)
    {
        if(fast==NULL) break;
        fast=fast->next;
        if(fast==NULL) break;
        fast=fast->next;
        pre=slow; //记录切分节点，返回的前一个
        slow=slow->next;
    }
    pre->next=NULL //切分
    return slow;
}
//合并两个有序链表
/*
由于两个链表是有序的，因此我们可以分别从两个链表的第一个节点开始比较，把用于指向新链表的指针指向头节点值比较大的链表，记这个链表为list1。然后指向list1的第二个节点，而lsit2则不动，仍然指向头节点，list1的第二个节点继续比较，取较大者为新的节点。

如果两个链表不等长，那么必有一个链表先遍历完，只需要把还没有遍历完的链表剩下的部分加入到新的链表即可。
用这种方式，就可以在O(len1+len2)完成任务，且不需要再构造新的存储空间。
*/
//递归实现，有重复比较的过程，一直将小的加入到新的队列，并向后移动
LinkList merge(LinkList L1,LinkList L2)
{
    if(!L1)return L2;
    if(!L2)return L1;
    LinkList newhead;
    if(L1->data<L2->data)
    {
        newhead=L1;
        newhead->next=merge(L1->next,L2);
    }
    else
    {
        newhead=L2;
        newhead->next=merge(L1,L2->next);
    }
    return newhead;
}
//非递归实现
LinkList merge(LinkList L1, LinkList L2)
{
    if(!L1) return L2;
    if(!L2) return L1;
    LinkList newhead=NULL;//头结点
    LinkList newtail=newhead;
    while(L1&&L2)
    {
        if(L1->data<=L2->data)
        {
            newtail->next=L1;
            L1=L1->next;
        }
        else
        {
            newtail->next=L2;
            L2=L2->next;
        }
    }
    if(L1) newtail->next=L1;
    if(L2) newtail->next=L2;
    return newhead->next; //返回的是头结点
}

