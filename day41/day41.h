#ifndef _DAY41_
#define _DAY41_ 
#include <iostream>
#include <fstream>
#include <set>
/*
    set对元素进行排序，但是出现相同元素时会忽略掉
    因此引入multiset
*/
using namespace std;
//#define T1 //标准IO输入
//#define T2 //文件的读写
#define T3 //STL标准模板库---set容器的使用
/*
    标准输入流对象cin
    cin.get()//一次只能读取一个字符
    cin.get(一个参数)//读一个字符
    cin.get(三个参数)//可以读字符串
    cin.getline()
    cin.ignore()//忽略
    cin.peek()
    cin.putback()//吐回去
*/
/*
    文件的读写操作
    fstream提供了三个类，用来实现c++对文件的操作(文件的创建、读、写)
    iftream---从已有的文件读入
    ofstream---向文件写内容
    fstream---打开文件读写
    文件打开模式
    ios::in 只读
    ios::out 只写
    ios::app 从文件末尾开始写，防止丢失文件中原来就有的内容
    ios::binary 二进制模式
    ios::nocreate 打开一个文件，如果文件不存在，不创建文件
    ios::noreplace 打开一个文件，如果文件不存在，创建该文件
    ios::trunc 打开一个文件，然后清空内容
    ios::ate 打开一个文件时，将位置移动到文件尾
    文件指针位置在C++中的用法：
    ios::beg 文件头
    ios::end 文件尾
    ios::cur 当前位置
    例子：
    file.seekg(0,ios::beg);//让文件指针定位到文件开头
    file.seekg(0,ios::end);//让文件指针定位到文件末尾
    file.seekg(10,ios::cur);//让指针从当前位置向文件末方向移动10个字节

*/
/*
    顺序容器：可变长动态数组vector、双端队列deque、双向链表list
    关联容器：set、multiset、map、multimap.关联容器
    内的元素是排序的。插入元素时，容器会按一定的排序规则将
    元素放到适当的位置上，因此插入元素时不能指定位置。
*/
namespace DAY41
{
    void Get_Test();
    void Getline_Test();
    void Get_Test_1();
    void Ignore_Test();
    void Putback_Test();
    
}
namespace DAY41A
{
    void CRead_File();
    void Read_File();
    void CWrite_File();
    void Write_File();
}
namespace DAY41B
{
    
}
#endif