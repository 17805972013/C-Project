#include "day54.h"
int main(int argc,char* argv[])
{
    #ifdef T1
    using namespace DAY54A;
    int a[6] = {9,1,3,7,4,10};
    Node* head = NULL;
    for(int i = 0;i < 6;++i)
        InsertSort(head,a[i]);
    Node* p = head;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
    #endif
    #ifdef T2
    using namespace DAY54A;
    int a[6] = {9,1,3,7,4,10};
    InsertSort_1(a);
    #endif
    printf("hello..\n");
    return 0;
}
int DAY54::Init(HashTable *H)
{
    m = HASHSIZE;
    H->elem = new int;
    H->count = m;
    for(int i = 0;i < m;++i)
    {
        H->elem[i] = NULLKEY;
    }
    return 1;
}
void DAY54::Insert(HashTable *H,int k)
{
    int addr = Hash(k);
    while(H->elem[addr] != NULLKEY)
    {
        addr = (addr+1)%m;//开放定址
    }
    H->elem[addr] = k;
}
int DAY54::Search(HashTable* H,int k)
{
    int addr = Hash(k);
    while(H->elem[addr] != k)
    {
        addr = (addr+1)%m;
        if(H->elem[addr] == NULLKEY || addr == Hash(k))
        {
            return -1;
        }
    }
    return 0;
}
void DAY54::Result(HashTable* H)
{
    for(int i = 0;i < H->count;++i)
    {
        cout<<H->elem[i]<<" ";
    }
    cout<<endl;
}
void DAY54A::InsertSort(Node* &head,int data)
{
    if(head == NULL)
    {
        head = new Node;
        head->data = data;
        head->next = NULL;
        return;
    }
    Node* pnew = new Node;
    Node* p = head;
    while(p->next && p->data <= data)
    {
        p = p->next;
    }
    if(p->data > data){
        pnew->data = p->data;
        p->data = data;
        pnew->next = p->next;
        p->next = pnew;
    }
    else//判断是否处于最后一个位置
    {
        pnew->data = data;
        p->next = pnew;
        pnew->next = NULL;
    }
}
void DAY54A::InsertSort_1(int a[])
{
    /* for(int k = 1;k < 6;++k)
    for(int j = 0;j < k;++j)
    if(a[j] > a[k])
    {
        int temp = a[j];
        a[j] = a[k];
        a[k] = temp;
    }*/
    /*** 插入排序 ***/
    /* for (int i = 1; i < 6; i++) {
		int j = i;
		int temp = a[i];                         //待排序元素赋值给临时变量
		while (j > 0 && temp < a[j - 1]) {   //当未达到数组的第一个元素或者待插入元素小于当前元素
			a[j] = a[j - 1];             //就将该元素后移
			j--;                                 //下标减一，继续比较
		}
		a[j] = temp;                         //插入位置已经找到，立即插入
    } */
    /* 希尔排序 */
    int gap = 7;
    do
    {
        gap = gap/3 +1;
         for (int i = gap; i < 6; i+=gap) {
		int j = i;
		int temp = a[i];                         //待排序元素赋值给临时变量
		while (j > 0 && temp < a[j - gap]) {   //当未达到数组的第一个元素或者待插入元素小于当前元素
			a[j] = a[j - gap];             //就将该元素后移
			j-=gap;                                 //下标减一，继续比较
		}
		a[j] = temp;                         //插入位置已经找到，立即插入
	} 
    } while (gap > 1);
    
    for(int i = 0;i < 6;++i)
    cout<<a[i]<<" ";
    cout<<endl;
}