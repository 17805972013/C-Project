#ifndef _DAY51_
#define _DAY51_
#include <iostream>
using namespace std;
#define T1 //普利姆算法
#define T2 //克鲁斯卡尔算法
/*
    普利姆算法原理：
    设图G顶点集合为U，首先任意选择图G中的一点作为起始点a，
    将该点加入集合V，再从集合U-V中找到另一点b使得点b到
    v中任意一点的权值最小，此时将b点也加入集合v；以此类推，
    现在的集合V={a,b},再从集合U-V中找到另一点c使得点c到
    V中任意一点的权重最小，此时将c点加入集合v，直至所有顶点
    全部被加入V，此时就构建出了MST.
    克鲁斯卡尔算法：
    1.将图中的所有边都去掉；
    2.将边按权值从小到达的顺序添加到图中，保证添加的过程中
    不会形成环；
    3.重复上一步直到连接所有顶点，此时就生成了最小生成树
    难点：判断某条边<u,v>的加入是否会在已经选定的边集集合中
    形成环。
    解决办法：使用并查集，分别找出两个顶点u,v所在树的根节点。
    若根节点形同，说明u,v在同一棵树中，则u,v连起来会形成环。



*/
namespace DAY51
{
    template<typename T>
    struct Node
    {
        T data;//数据域
        Node* next;//指针域
    };
    template<typename T>
    struct queue
    {
        queue():head(NULL),rear(NULL){}
        Node<T>* head;
        Node<T>* rear;
        void push(T data);
        T pop();
    };
    int sum = 0;
    void Pulimu(int a[][6],queue<int> s,queue<int> s1);
}
#endif