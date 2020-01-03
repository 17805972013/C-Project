#include "day53.h"
int main(int argc,char* argv[])
{
    #ifdef T1
    using namespace DAY53;
    int a[7] = {2,3,7,9,12,13,16};
    int pos = -1;
    pos = HalfFind(a,0,6,16);
    if(pos != -1)
    {
        cout<<"Find Successfully!\n";
        cout<<"position = "<<pos<<endl;
    }
    else
    {
        cout<<"Find Failed!\n";
    }
    
    #endif
    #ifdef T2
    using namespace DAY53;
    BiTree* head;
    CreateBiTree(head);
    TranverseBiTree(head);
    #endif
    #ifdef T3
    using namespace DAY53A;
    BiTree* head = new BiTree;
    CreateSortBiTree(head);
    MidTraverse(head);
    #endif
    printf("hello.\n");
    return 0;
}
int DAY53::HalfFind(int a[],int low,int high,int key)
{
     if(low > high)
        return -1;
    int mid = (low+high)/2;
    if(a[mid] == key)
    {
        return mid;
    }
    if(a[mid] < key)
    {
        return HalfFind(a,mid+1,high,key);
    }
    if(a[mid] > key)
    {
        return HalfFind(a,low,mid,key);
    }
}
void DAY53::CreateBiTree(BiTree* &T)
{
    char c;
    c = getchar();
    if(c == ' ')
    {
        T = NULL;
    }
    else
    {
        T = new BiTree;
        T->data = c;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    
}
void DAY53::TranverseBiTree(BiTree* head)
{
    if(head)
    {
        printf("%c\n",head->data);
        TranverseBiTree(head->lchild);
        TranverseBiTree(head->rchild);
    }
}
void DAY53A::CreateBiTree(BiTree* T,int data)
{
    if(data >= T->data)
    {
        if(!(T->rchild)){
            T->rchild = new BiTree;
            T->rchild->data = data;
            T->rchild->lchild = NULL;
            T->rchild->rchild = NULL;
        }
        else
        {
             CreateBiTree(T->rchild,data);
        }
        
    }
   else
    {
        if(!(T->lchild)){
        T->lchild = new BiTree;
        T->lchild->data = data;
        T->lchild->lchild = NULL;
        T->lchild->rchild = NULL;
        }
        else
        {
            CreateBiTree(T->lchild,data);
        }
        
    }
}
void DAY53A::CreateSortBiTree(BiTree* &T)
{
    int data;
    cin>>data;
    if(data != 65535)
    {
        T = new BiTree;
        T->lchild = NULL;
        T->rchild = NULL;
        T->data = data;
    }
    while(data != 65535)
    {
        cin>>data;
        if(T && data!=65535)
        CreateBiTree(T,data);
    }

}
void DAY53A::MidTraverse(BiTree* head)
{
    if(head)
    {
        MidTraverse(head->lchild);
        cout<<head->data<<endl;
        MidTraverse(head->rchild);
    }
}