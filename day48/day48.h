#ifndef _DAY48_
#define _DAY48_
#include <iostream>
#include <string.h>
#include <set>
using namespace std;
//#define T1 //线索二叉树
#define T2 //赫夫曼树
/*
    二叉树转树，森林
    1.若结点x是其双亲y的左孩子，则把x的右孩子，右孩子的右
    孩子,...,都与y用连线连起来；
    2.去掉所有双亲到右孩子之间的连线；
    3.调整位置。
    树的遍历分为两种方式:一种是先根遍历，另一种是后根遍历。
    规律：
    树、森林的前根遍历和转化为二叉树的先序遍历结果是一样的；
    树、森林的后根遍历和转化为二叉树的中序遍历结果一样。
  
    哈弗曼树：---最优二叉树
    目的：找出存放一串字符所需要的最少的二进制编码
    原理：首先统计出每种字符出现的概率
    1.找出字符中最小的两个，小的在左边，大的在右边，组成
    二叉树。在频率表中删除此次找到的两个树，并加入此次最小两个数
    的频率和到表中；
    2.重复1中步骤，直到表中所有元素都被遍历；
    3.添加0和1，规则左0右1；
    4.每个字符的二进制编码为(从根节点数到对应的叶子节点，路径
    上的值拼接起来就是叶子节点字母对应的编码)
    名词解释：定长编码、变长编码，前缀码
    定长编码：像ASCII编码,已经固定好了
    变长编码:单个编码长度不一致，可以根据整体出现频率来
    调节；
    前缀码：没有任何码字是其他码字的前缀--赫夫曼编码（基于贪心算法）
    即一个编码不可能成为另一个数据的前缀。
    ××赫夫曼编码：
    1.创建一个队列；(从小到大排列)
    2创建一个赫夫曼树；
    3.创建一个赫夫曼表；
    4.编码；
    5.译码.

    应用在通信领域，通常可以节省20%~90%的空间
*/
namespace DAY48
{
    //线索存储标志位
    //Link(0)表示指向左右孩子的指针
    //Thread(1)表示指向前驱后继的线索
    typedef enum{Link,Thread}PointNag;
    struct Node
    {
        char data;//数据域
        Node* lchild;//左指针
        Node* rchild;//右指针
        PointNag ltag;
        PointNag rtag;
    };
    //全局变量，它始终指向刚刚访问过的节点
    Node* pre;
    void CreateDoubleTree(Node* head);
    void MidTranverse(Node* head);//中序遍历
    void ThreadDoubleTree(Node* head);//线索二叉树
}
namespace DAY48A
{
   struct _Node
   {
       char data;
       int frequency;
       char flag;
       _Node* pre;//记录上一个结点
       _Node* lchild;
       _Node* rchild;
   };
   struct Link
   {
       Link():data(NULL){}
       _Node* data;//数据域
       Link* next;//指针域
   }; 
   struct __Node
   {
       int data;
       __Node* next;
   };
   struct stack
   {
       stack():head(NULL),rear(NULL){}
       __Node* head;
       __Node* rear;
       void push(int data);
       int pop();
   }; 
   struct HuffmanTable
   {
       HuffmanTable():name('\0'){
           memset(PreCode,'\0',256);
       }
       char name;
       char PreCode[256];
   };
   struct queue
   {
       queue():head(NULL),tail(NULL){}
       Link* head;
       Link* tail;
       HuffmanTable* Table;
       void insert(_Node* data);
       _Node* pop();
       int Getlength();
   };
   template<typename T>
   struct NodeTree
   {
       T data;
       NodeTree* next;
   };
   template<typename T>
   struct Stack
   {
       Stack():head(NULL),rear(NULL){}
       NodeTree<T>* head;
       NodeTree<T>* rear;
       void push(T data);
       T pop();
   };
   template<typename T>
   struct Queue
   {
       Queue():head(NULL),tail(NULL){}
       NodeTree<T>* head;
       NodeTree<T>* tail;
       void push(T data);
       T pop();
   };
   void CreatHuffman(queue& s);
   void CreateHuffmanTable(_Node* p,HuffmanTable* Table);
}
#endif