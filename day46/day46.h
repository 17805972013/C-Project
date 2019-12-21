#ifndef _DAY46_
#define _DAY46_
#include <iostream>
using namespace std;
//#define T1 //数据结构之树
//#define T2 //深度优先搜索DFS---图论部分(后续补充)
//#define T3 //线索二叉树
#define T4 //非递归方式实现先序、中序、后序遍历
/*
    树是一种抽象数据类型或是实现这种抽象数据类型的数据结构
    用来模拟具有树状结构性质的数据集合。它是由n(n > 0)个
    有限节点组成一个具有层次关系的集合。
    特点：
    1.每个节点有零个或多个子节点；
    2.没有父节点称为根节点；
    3.每一个非根节点有且只有一个父节点；
    4.除了根节点外，每个子节点可以分为多个不相交的子树；
    树基本术语：度，叶子节点，根节点，父节点，子节点，深度
    高度。
    满二叉树：
    除最后一层无任何子节点外，每一层上的所有节点都有两个子
    节点。
    完全二叉树：
    若二叉树的深度为h,除第h层外，其它各层(1~(h-1))的节点
    数都达到最大个数，第h层所有的节点都连续集中在最左边。
    二叉树的遍历方式:
    先序遍历：根节点-->遍历左子树-->遍历右子树
    中序遍历:遍历左子树-->根节点-->遍历右子树
    后序遍历:遍历左子树-->遍历右子树-->根节点
    深度优先搜索(DFS)：
    从一个顶点V0开始，沿着一条路一直走到底，如果发现不能到达
    目标，那就返回到上一个节点，然后从另一条路开始走到底
    广度优先搜索(BFS)：
    从v0节点出发，先访问其相连的子节点，若子节点不符合，再
    访问子节点的子节点，按级别顺序依次访问，直到访问到目标
    节点
    DFS与BFS对比：
    BFS在树的层次较深且子节点数较多的情况下，消耗内存十分
    严重。适用于子节点数量不多，树的层次不深的情况,能够找到
    最短路径--很方便。
    DFS的方法是一条路走到黑，显然无法知道这条路是否是最短
    的，所以还需要走其他的路进行比较，因此缺点是难以寻找最优解
    ，优点是内存消耗小。
    线索二叉树：
    n个节点的二叉链表共有2n个链域，非空链域为n-1,空链
    域为n+1个，因此提出了一种方法，利用原来的空链域存放
    指针，指向树中其他节点，这种指针称为线索
    线索二叉树规则：
    前提:节点中增加两个标签ltag,rtag;
    1.ltag为0时指向该节点的左孩子，为1时指向该节点的前驱；
    2.rtag为0时指向该节点的右孩子，为1时指向该节点的后继；
    前驱和后继是按照中序遍历的顺序决定的.
    实则：
    线索二叉树等于是把一颗二叉树转变成了一个双向链表
    ，这样对我们的插入和删除节点、查找节点都带来了方便
    所以我们对二叉树以某种次序遍历使其变为线索二叉树的
    过程称作是线索化。

*/
namespace DAY46
{
    typedef enum{Link,Thread} PionterTag;
    template<typename T>
    struct Node
    {
        Node():flags(false){}
        bool flags;
        PionterTag ltag;
        PionterTag rtag;
        T data;//数据域
        Node* lp;//左指针
        Node* rp;//右指针
    };
    template<typename T>
    struct _Node
    {
        _Node():next(NULL){}
    
        T data;
        _Node<T>* next;
    };
    template<typename T>
    struct queue
    {
        queue():head(NULL),rear(NULL){}
        ~queue()
        {
            if(head != NULL)
            {
                delete [] head;
                head = NULL;
            }
            if(rear != NULL)
            {
                delete [] rear;
                rear = NULL;
            }
        }
        _Node<T> *head;//头指针
        _Node<T> *rear;//尾指针
        void push(T data);
        T pop();
    };
    Node<char>* pre;
    template<typename T>
    void CreateDoubleTree(Node<T>* head);
    template<typename T>
    /* 先序遍历 */
    void PreTransver(Node<T>* head);
    template<typename T>
    /* 中序遍历 */
    void MidTransver(Node<T>* head);
    template<typename T>
    /* 后序遍历 */
    void LastTransver(Node<T>* head);
    /* 线索二叉树 */
    template<typename T>
    void ThreadDoubleTree(Node<T>* head);
    template<typename T>
    void InOrderThreading(Node<T>* &head);
}
namespace DAY46A
{
    using namespace DAY46;
    template<typename T>
    struct stack
    {
        stack():head(NULL),rear(NULL){}
        ~stack()
        {
            if(head != NULL)
            {
                delete [] head;
                head = NULL;
            }
            if(rear != NULL)
            {
                delete [] rear;
                rear = NULL;
            }
        }
        _Node<T>* head;
        _Node<T>* rear;
        void push(T data);
        T pop();
    };
    template<typename T>
    void DFS(Node<T>* head);//深度优先遍历
    template<typename T>
    void BFS(Node<T>* head);//广度优先遍历
}
#endif