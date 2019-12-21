#ifndef _DAY49_
#define _DAY49_
#include <iostream>
using namespace std;
//#define T1 //重载函数复习
//#define T2 //图结构--链式前向性邻接表
#define T3 //图的遍历
/*
    图结构基本概念
    图数学式：
    G = (V,E)其中V表示顶点,E表示边
    V(G)是图结构中所有顶点的集合，E(G)是图结构中所有边的集合
    图结构中顶点集合V(G)不能为空，必须包含一个顶点
    1.无向图
    所有的边都没有方向性
    无向图可以理解成一个特殊的有向图，就是边互指向对方节点
    2.有向图
    边有方向性
    3.顶点的度
    连接顶点的边的数量称为该顶点的度，记为D(V)
    无向图只只有度，即顶点连接的边的数量；
    有向图包含出度和入度；
    入度记为ID(V);
    出度记为OD(V).
    有向图中，一个顶点V的总度便是入度和出度之和，即
    D(V) = ID(V) + OD(V);
    4.邻接顶点
    对于无向图中，与该顶点相连的顶点；
    对于有向图中，包含两种
    --入边邻接顶点：连接该顶点的边中的起始顶点；
    --出边邻接顶点：连接该顶点的边中的结束顶点。
    5.无向完全图
    如果在一个无向图中，每两个顶点之间都存在条边，那么这种
    图结构称为无向完全图。
    性质：假设有M个顶点，则边的总数为M(M-1)/2
    6.有向完全图
    如果在一个有向图中，每两个顶点之间都存在方向相反的两天边
    那么这种图结构称为有向完全图。
    性质：假设有N个点，则边的总数为N(N-1).
    7.有向无环图(DAG图)
    如果一个有向图无法从某个顶点出发警告若干条边回到该点
    则这个图是一个有向无环图。
    应用领域：区块链技术中。
    8.无权图和有权图
    即节点与节点之间这条边是否有一个数组与它对应。
    9.图的连通性
    无向图：
    连通图：无向图G中任意一对顶点都是连通的，则称此图为连通图。
    割顶集与连通度：设V1是连通图G中的一个顶点子集，在G中删去
    V1以及与V1相关联的边后图不连通，则称为V1是G的割顶集。如果
    v1的任何真子集都不是割顶集，则称v1是极小割顶集。顶点
    个数最小的极小割顶集称为最小割顶集。最小割顶集中顶点
    的个数，称作图G的顶点连通度，记作k(G),且称图G是k-连通
    图。
    割点：如果割顶点集中只有一个顶点，则该顶点称为割点。
    点双连通图：连通度k(G)>1;
    点双连通分量：
    割边集与边连通度：设E1是G的边子集，在G中删去E1后图不连通，则
    称E1是G的割边集，如果割边集E1的任何真子集都不是割边集，则
    称E1为极小割边集。边数最小的极小割边集称为最小割边集合。最小
    割边集中边的个数，称作图G的边连通度。
    割边：如果割边集中只有一条边，称为割边；
    边双连通图：没有割边或边连通度大于1；
    边双连通分量：删除割边后，剩下的连通分量称为边双连通分量；
    有向图：
    强连通：若G是有向图，如果对图G中任意两个顶点u和v,既
    存在从u到v的路径，也存在从v到u的路径，则称该图为强连通图
    单连通：存在从u到v的路径或v到u的路径；
    弱连通:非强连通和单连通下，忽略图中每条有向边方向，得到的无向图连通，称为弱连通
    9.简单图
    存在两种特殊的边：
    1.自环边：节点自身的边，自己指向自己；
    2.平行边：两个节点存在多个边相连接；
    不考虑这两种情况的图称为简单图。
    邻接矩阵得到入度出度信息
    入度：第i列的各数之和；
    出度：第i行的各数之和

    ××十字链表--邻接表和逆邻接表结合
    对于有向图来说，邻接表有缺陷，只有出度没有入度，而逆
    邻接表解决了入度但没解决出度。

*/
namespace DAY49
{
    class A
    {
        public:
        A():a(1),b(2){}
        ~A(){}
        int operator+(A& p)
        {
            
            return a+p.a;
        }
        double operator*(A& p)
        {
            return b*p.a;
        }
        friend istream& operator>>(istream& is,A& p)
        {
            cout<<"请输入a的值:\n";
            is>>p.a;
            cout<<"请输入b的值:\n";
            is>>p.b;
            return is;
        }
        friend ostream& operator<<(ostream& os,A& p)
        {
            os<<p.a<<"****"<<p.b<<endl;
            return os;
        }
        private:
        int a;
        int b;
    };
}
namespace DAY49A
{
    struct Node
    {
        int u;
        int v;
        int w;
        friend istream& operator>>(istream& is,Node& p)
        {
                is>>p.u>>p.v>>p.w;
                return is;
        }
        friend ostream& operator<<(ostream& os,Node& p)
        {
            os<<p.u<<" "<<p.v<<" "<<p.w;
            return os;
        }
    };
    
}
namespace DAY49B
{
    template<typename T>
    struct Node
    {
        T data;//数据域
        Node* next;//指针域
    };
    template<typename T>
    struct stack
    {
        stack():head(NULL),tail(NULL){}
        Node<T>* head;
        Node<T>* tail;
        void push(T data);
        T pop();
    };
    int visit[4] = {-1,-1,-1,-1};
    void TraverGraph(int a[][4],int pos);
    void TraverGraph_1(int a[][4]);
}
#endif