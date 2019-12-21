#ifndef _DAY44_
#define _DAY44_
#include <iostream>
#include <unistd.h>
#include <string.h>
//#define T1 //循环链表
//#define T2 //双向链表
//#define T3 //逆波兰表达式---后缀表达式输入
//#define T4 //中缀转后缀
#define T5 //队列
/*
    单链表有一定的缺陷，只能从一个节点到下一个节点，而不能
    访问到上一个节点，循环链表就可以解决这一问题，当然用
    双向链表更加方便
*/
using namespace std;
namespace DAY44
{
    typedef struct NODE
    {
        int data;//数据域
        NODE* next;//指针域
    }Node,*Pnode;
    void CircleList(Pnode p,int sum);//建立循环链表
    void Disp(Pnode p,int n);//遍历循环链表
    void Insert(Pnode p,int pos,int e);//插入循环链表
    void Delete(Pnode p,int pos);//删除循环链表
    void Ysfh(Pnode p,int sum,int pos);//待解决
}
namespace DAY44A
{
    typedef struct Node
    {
        int data;//数据域
        Node* prev;//前向指针
        Node* next;//后向指针
    }Node,*Pnode;
    void CreateDoubleList(Pnode p);//创建链表
    void Disp(Pnode p);//遍历链表
}
namespace DAY44B
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
        stack():head(NULL),rear(NULL){}
        Node<T> *head;//头结点
        Node<T> *rear;//尾结点
        void push(T data);//入栈
        T pop();//出栈
    };
}
namespace DAY44C
{
    template<typename T>
    struct Node
    {
        T data;//数据域
        Node<T>* next;//指针域
    };
    template<typename T>
    struct queue
    {
        queue():head(NULL),tail(NULL){}
        ~queue()
        {
            if(head != NULL)
            {
                delete [] head;
                head = NULL;
            }
            if(tail != NULL)
            {
                delete [] tail;
                tail = NULL;
            }
        }
        Node<T>* head;//头指针
        Node<T>* tail;//尾指针
        void push(T data);
        T pop();
    };
}

#endif