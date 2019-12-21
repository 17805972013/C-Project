#ifndef _DAY43_
#define _DAY43_
#include <iostream>
#include <string.h>
//#define T1//模板类和函数复习
//#define T2//线性表链式存储结构
//#define T3 //线性表头插法和尾插法
//#define T4 //栈
//#define T5 //模板栈
#define T6 //模板队列
/*
    数据结构基本概念：
    时间复杂度----代码运行时间
    空间复杂度----代码所占的内存
    线性表
    顺序存储结构(数组)---用一段地址连续的存储单元依次存储
    线性表的数据元素
    描述顺序存储结构三个属性：
    存储空间的起始位置，线性表的最大存储容量，线性表的
    当前长度。
    线性表顺序存储结构的优点：
    1.无需为表示表中元素之间的逻辑增加额外的存储空间；
    2.可以快速地存取表中任一位置元素
    线性表顺序存储结构的缺点：
    1.插入和删除操作需要移动大量元素
    2.当线性表长度变化较大时，难以确定存储空间的容量
    3.造成存储空间的碎片
    线性表链式存储结构---用一组任意的存储单元存储线性表
    的数据元素，这组存储单元可以是连续的，也可以是不连续的
    头指针特点：
    1.头指针是指链表指向第一个节点的指针，若链表有头节点
    则是指向头节点的指针；
    2.头指针具有标识作用，所以常用头指针冠以链表的名字
    3.无论链表是否为空，头指针均不为空。头指针是链表的必要元素。
    头节点特点：
    1.头节点是为了操作的统一和方便而设立的，放在第一元素的节点
    之前，其数据域一般无意义；
    2.有了头节点，对在第一元素节点前插入节点和删除第一结点
    其操作与其他结点的操作就统一了；
    3.头结点不一定是链表必须要素
    
    宜采用顺序存储结构
    a)线性表需要频繁查找，很少进行插入和删除操作时；
    b)知道线性表的大致长度

    宜采用单链表结构
    a)线性表需要频繁插入和删除；
    b)元素个数变化较大或者完全不知道有多大时
    栈和队列
    栈：先进后出
    队列：先进先出
*/
using namespace std;
namespace DAY43
{
    template<class T>
    class A
    {
        public:
        A();
        ~A();
        private:
        T a;
        T b;
        char *c;
    };
    template<class T> void _Sort(T* a,int n);
}
namespace DAY43A
{
    typedef struct NODE
    {
        int a;//数据域
        NODE* next;//指针域
    }Node,*Pnode;
    void Create_Node(Pnode p);//建立链表
    void Insert_Node(Pnode p,int n);//插入节点
    void Delete_Node(Pnode p,int n);//删除节点
    int Node_length(Pnode p);//链表长度
}
namespace DAY43B
{
    typedef struct NODE
    {
        int a;//数据域
        NODE* next;//指针域
    }Node,*Pnode;
    void CreateList_Head(Pnode p);//建立链表---头插法
    void CreateList_Rear(Pnode p);//建立链表---尾插法
    void DispList(Pnode p);//遍历链表
    void InsertList(Pnode p);//插入
    void DeleteList(Pnode p);//删除
    bool Empty_List(Pnode p);//链表是否为空
}
namespace DAY43C
{
   struct Node
   {
       int data;//数据域
       Node* next;//指针域
   };
   struct Stack
   {
       Node* head;//头指针
       Node* rear;//尾指针
   };
   void Push(Stack* p,int data)//入栈
   {
      if(p->head == NULL)
      {
          p->head = new Node;
          p->head->data = data;
          p->head->next = p->rear;
      }
      Node* r = p->head;
      Node* pnew = new Node;
      pnew->data = data;
      p->head = pnew;
      pnew->next = r;
   }
   int Pop(Stack* p)
   {
       if(p->head != NULL){

           Node* T = p->head;
           int temp = T->data;
           temp = p->head->data;
           p->head = p->head->next;
         
           delete [] T;
           return temp;
       }
       return -1;
   }
}
namespace DAY43D
{
    template<class T>
    class Node
    {
        public:
        T data;//数据域
        Node* next;//指针域
    };
    template<class T>
    class Stack
    {
        public:
        Stack();
        ~Stack();
        Node<T>* head;//头结点
        Node<T>* rear;//尾结点
        void push(T data);//入栈
        T pop();//出栈
    };
}
namespace DAY43E
{
    template<typename T>
    struct Node
    {
        T data;//数据域
        Node* next;//指针域
    };
    template<typename T>
    class Queue
    {
        public:
        Queue():head(NULL),tail(NULL){}
        ~Queue()
        {
            delete [] head;
            delete [] head;
        }
        Node<T>* head;//队头
        Node<T>* tail;//队尾
        void push(T data);//入队
        T pop();//出队 
    };
}
#endif