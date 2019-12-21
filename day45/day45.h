#ifndef _DAY45_
#define _DAY45_
#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;
//#define T1 //折半查找算法的递归实现---序列必须排好顺序从小到大
//#define T2 //汉诺塔问题
//#define T3 //八皇后问题
//#define T4 //八皇后问题求解2
//#define T5 //判断是否是回文
//#define T6 //括号匹配问题
//#define T7 //最大重复子串
//#define T8 //关键字查找一般算法
#define T9 //KMP匹配算法
/*
    递归和分治思想之分治思想
    当一个问题规模比较大且不易求解的时候，就可以考虑将问题分成
    几个小的模块，逐一求解
    求解递归问题步骤：
    1.递归函数功能，要实现什么
    2.找出递归结束的条件
    3.找出函数的等价关系式
    汉诺塔问题
    假设三个分别命名为X,y,Z的塔座，在塔座X上插有n个直径
    大小各不相同，依小到大编号为1,2，3的圆盘，现在要将
    X轴上的n个圆盘移动至Z上，并按照同样顺序叠排，圆盘
    移动时必须遵循以下规则：
    1.每次只能移动一个圆盘；
    2.圆盘可以插在X,Y,Z中的任意一个塔座上；
    3.任何时刻都不能将一个较大的圆盘压在较小的圆盘之上
    八皇后问题的递归解法
    如何能够在8*8的国际象棋棋盘上放置八个皇后，使得任何
    一个皇后都无法直接吃掉其他的皇后？为了达到此目的，任
    两个皇后都不能处于同一条横行、纵行或斜线上
    回文：
    a b a --> a b a;是
    a b c --> c b a;否
    KMP算法
    关键字搜索
*/
namespace DAY45
{
    int count = 0;
    template<typename T>
    int BinSearch(T* arr,int low,int high,T n);
    void HanTower(int n,char x,char y,char z);
    int NotDanger(int row,int col,int (*chess)[8]);
    void EightQueen(int row,int n,int (*chess)[8]);
    void EightQueen2(int row,int col,int (*chess)[8]);
    
}
namespace DAY45A
{
    int cnt = 0;
    template<typename T>
    struct Node
    {
        T data;//数据域
        Node<T>* next;//指针域
    };
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
        void push(T data);
        T pop();
        Node<T>* head;
        Node<T>* rear;
    };
    int HuiWen(char s1[],int k,int strlength);
    void Match(char s1[],int k,int len);//括号匹配问题

}
namespace DAY45B
{
    using namespace DAY45A;
    int _cnt = 0;
    void RepeatStr(char str[],char *MaxStr,int len);
    int OrdinaryAlgorithm(char str[],char key[],int pos);
    int KMPAlgorithm(char str[],char key[],int pos);
}
#endif