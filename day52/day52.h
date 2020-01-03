#ifndef _DAY52_
#define _DAY52_
#include <iostream>
using namespace std;
//#define T1 //邻接表复习
//#define T2 //拓扑排序
#define T3 //关键路径
/*
    拓扑排序具体步骤：
    1.新建node类，包含节点数值和它的指向；
    2.一个数组包含node.初始化，添加每个节点指向的时候同时
    被指的节点入度+1.
    3.扫描一遍所有node。将所有rudu为0的点加入一个栈(队列)；
    4.当栈(队列)不为空时，抛出其中任意一个node。如果某个点
    的入度被减为0，那么就将它加入栈(队列)
    5.重复上述步骤，直到栈为空。
    关键路径
    AOE网：在一个表示工程的带权有向图中，用顶点表示事件
    用有向边表示活动，用边上的权值表示活动的持续时间，这种
    有向图的边表示活动的网，称之为AOE网(Activity On Edge Network).
    性质：在AOE网中，所有活动都完成才能到达终点，因此完成整个
    工程所必须花费的时间应该为源点到终点的最大路径长度。
    具有最大路径长度的路径称为关键路径。
    几个概念：
    事件最早发生时间(针对顶点)ve[k]
    事件最迟发生时间(针对顶点)vl[k]
    活动最早发生时间(针对边)ee[i]
    活动最迟发生时间(针对边)el[i]
    活动的最早开始时间和最晚开始时间相等，则说明该活动属于
    关键路径上的活动，即关键活动。
    多条关键路径：
    用栈进行处理
*/
namespace DAY52
{
    struct Node
    {
        int u;
        int v;
        int w;
         friend istream& operator>>(istream& is,Node& p)
        {
            //is>>p.u>>p.v>>p.w;
            is>>p.u>>p.v;
            return is;
        }
        friend ostream& operator<<(ostream& os,Node& p)
        {
            os<<p.u<<" "<<p.v<<" "<<p.w;
            return os;
        }
    };
    template<typename T>
    struct _Node
    {
        T data;
        _Node* next;
    };
    template<typename T>
    struct queue
    {
        queue():head(NULL),rear(NULL){}
        _Node<T>* head;
        _Node<T>* rear;
        void push(T data);
        T pop();
    };

}
namespace DAY52A
{
    template<typename T>
    struct Node
    {
        T data;
        Node* next;
    };
    template<typename T>
    struct stack
    {
        stack():head(NULL),rear(NULL){}
        Node<T>* head;
        Node<T>* rear;
        void push(T data);
        T pop();
    };
    struct Edge
    {
        friend istream& operator>>(istream& is,Edge& p)
        {
            is>>p.u>>p.v>>p.w;
            return is;
        }
        friend ostream& operator<<(ostream& os,Edge p)
        {
            os<<p.u<<" "<<p.v<<" "<<p.w;
            return os;
        }
        int u;
        int v;
        int w;   
    };


}
#endif