#ifndef _DAY50_
#define _DAY50_
#include <iostream>
#include <ctime>
using namespace std;
//#define T1 //广度优先遍历BFS
#define T2 //骑士周游问题
/*
    广度优先搜索类似于树的层次遍历过程，它需要借助一个队列
    来实现，具体步骤：
    1.创建一个visited数组，用来记录已被访问过的顶点，创建一个
    队列，用来存放每一层的顶点，初始化图G;
    2.从图中的v0开始访问，将访问的visit[v0]的值设置为true,同时
    将v0入队；
    3.只要队列不为空，则重复如下操作
    骑士周游问题
    利用回溯法，遍历棋盘上的每一个点，一次只走一个
*/
namespace DAY50
{
    template<typename T>
    struct Node
    {
        T data;
        Node* next;
    };
    template<typename T>
    struct queue
    {
        queue():head(NULL),tail(NULL){}
        Node<T>* head;
        Node<T>* tail;
        void push(T data);
        T pop();
    };
    //广度优先遍历
    void BFS(int a[][4]);
}
namespace DAY50A
{
    int k = 0;
    int SelPoint(int &x,int &y,int sel);
    void TravelChessBoard(int a[][8],int x,int y,int cnt);
}
#endif