#ifndef _DAY47_
#define  _DAY47_
#include <iostream>
#define T1 //动态创建二叉树
using namespace std;
namespace DAY47
{
    template<typename T>
    struct Node
    {
        T data;//数据域
        Node<T>* next;//指针域
    };
    template<typename T>
    struct BiTree
    {
        T data;
        BiTree<T>* lp;
        BiTree<T>* rp;
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
    template<typename T>
    struct stack
    {
        stack():head(NULL),rear(NULL){}
        Node<T>* head;
        Node<T>* rear;
        void push(T data);
        T pop();
    };
    template<typename T>
    void CreateDoubleTree(BiTree<T>* head);
    template<typename T>
    void PreTransver(BiTree<T>* head);
}
#endif