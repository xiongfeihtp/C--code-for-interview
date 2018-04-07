//
//  color.cpp
//  C++ basic
//
//  Created by 熊飞 on 2018/3/22.
//  Copyright © 2018年 熊飞. All rights reserved.
//

#include <stdio.h>
/*
四色问题:

四色问题是m图着色问题的一个特列，根据四色原理，证明平面或球面上的任何地图的所有区域都至多可用四种、颜色来着色，并使任何两个有一段公共边界的相邻区域没有相同的颜色。这个问题可转换成对一平面图的４－着色判定问题(平面图是一个能画于平面上而边无任何交叉的图)。将地图的每个区域变成一个结点，若两个区域相邻，则相应的结点用一条边连接起来。多年来，虽然已证明用5种颜色足以对任一幅地图着色，但是一直找不到一定要求多于4种颜色的地图。直到1976年这个问题才由爱普尔(k．i．apple)，黑肯(w．haken)和考西(j．koch)利用电子计算机的帮助得以解决。他们证明了4种颜色足以对任何地图着色。

在这一节，不是只考虑那些由地图产生出来的图，而是所有的图。讨论在至多使用m种颜色的情况下，可对一给定的图着色的所有不同方法。


m图着色问题：

题目大意：

1，已知一个图g和m>0种颜色，在只准使用这m种颜色对g的结点着色的情况下，是否能使图中任何相邻的两个结点都具有不同的颜色呢?这个问题称为m-着色判定问题。

2，在m-着色最优化问题则是求可对图g着色的最小整数m。这个整数称为图g的色数。这是求图的最少着色问题，求出m的值。

题目的解法：

第一个问题，m-着色判定问题：

可以通过回溯的方法，不断的为每一个节点着色，在前面n-1个节点都合法的着色之后，开始对第n个节点进行着色，这时候枚举可用的m个颜色，通过和第n个节点相邻的节点的颜色，来判断这个颜色是否合法，如果找到那么一种颜色使得第n个节点能够着色，那么说明m种颜色的方案是可行的。返回真即可：

[cpp] view plain copy
//用于判断当前节点上涂上这个颜色可不可行，与其邻接节点的颜色做判断，这里用邻接表来存储图的信息
 */
bool isok(int step)
{
    vector<int>::iterator iter;
    for(iter = input[step].begin(); iter != input[step].end(); iter++)
    {
        if(Color[step] == Color[*iter]) return false;
    }
    return true;
}
//step表示0->n的节点，color_num是指给color_num的颜色的个数可用
//判断如果给color_num的颜色的个数是否可行，如果可行返回true,否则false
bool DFS(int step, int color_num)
{
    if(step >= n) return true;
    else
    {
        int i;
        for(i = 1; i<= color_num; i++)
        {
            Color[step] = i;
            if(isok(step))
            {
                if(DFS(step + 1, color_num))
                    return true;
            }
            Color[step] = 0;
        }
    }
    return false;
}

/*
第二个问题：求出最少的着色数m

有了上面的问题的积累，对于这个问题就很简单了，只要从1到n枚举颜色数，来调用上面的DFS(0, m),如果有一次调用返回true，那么这时这个颜色就是我们要求的最少的着色数。

[cpp] view plain copy
 */
for(i = 1; i<= n; i++)
{
    if(DFS(0, i))
    {
        cout << "the min colors :" << i << endl;
        break;
    }
}
