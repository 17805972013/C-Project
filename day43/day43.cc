#include "day43.h"
int main(int argc,char* argv[])
{
    #ifdef T1
    int a[5] = {2,1,0,4,3};
    string b[5] = {"hello","ability","avoid","boal","secure"};
    DAY43::_Sort<int>(a,5);
    for(int i = 0;i < 5;++i)
    cout<<a[i]<<" ";
    cout<<endl;
    DAY43::_Sort<string>(b,5);
    for(int i = 0;i < 5;++i)
    cout<<b[i]<<" ";
    cout<<endl;
    DAY43::A<int> _A;
    #endif
    #ifdef T2
        DAY43A::Pnode phead = new DAY43A::Node; 
        phead->a = 0;
        phead->next = NULL;
        DAY43A::Create_Node(phead);
        DAY43A::Insert_Node(phead,3);//插入结点
        DAY43A::Delete_Node(phead,4);//删除结点
        DAY43A::Pnode p = phead->next;
        while(p != NULL){
            cout<<p->a<<" ";
            p = p->next;
        }
        cout<<endl;
    #endif
    #ifdef T3
    using namespace DAY43B;
    Pnode phead = new Node;
    phead->next = NULL;
    CreateList_Head(phead);
    DispList(phead);
    #endif
    #ifdef T4
    using namespace DAY43C;
    Stack *p = new Stack;
    Push(p,1);
    Push(p,2);
    Push(p,3);
    cout<<Pop(p)<<" "<<Pop(p)<<" "<<Pop(p)<<endl;
    #endif
    #ifdef T5
    using namespace DAY43D;
    Stack<char*> a;
    a.push((char*)("hello"));
    a.push((char*)("world"));
    a.push((char*)("入栈出栈"));
    cout<<a.pop()<<" "<<a.pop()<<" "<<a.pop()<<endl;
    #endif
    #ifdef T6
    using namespace DAY43E;
    Queue<int> a;
    a.push(1);
    a.push(2);
    a.push(4);
    cout<<a.pop()<<" "<<a.pop()<<" "<<a.pop()<<endl;
    #endif
    printf("hello..\n");
    return 0;
}
template<class T> 
void DAY43::_Sort(T* a,int n)
{
    T temp;
    for(int i = 0;i < n;++i)
    for(int j = i+1;j < n;++j)
    if(a[i] > a[j]){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
template<class T> DAY43::A<T>::A():a(1),b(2),c(new char[6])
{
    strcpy(c,"hello");
    printf("构造函数A\n");
    printf("a = %d , b = %d , c = %s\n",a,b,c);
}
template<class T> DAY43::A<T>::~A()
{
    if(c != NULL)
    {
        delete [] c;
        c = NULL;
    }
    printf("析构函数A\n");
}
void DAY43A::Create_Node(Pnode p)
{
    /*
        开始建立链表长度为5
    */
   for(int i = 0;i < 5;++i)
   {
       Pnode pnew = new Node;
       pnew->a = i+1;
       p->next = pnew;
       p = pnew;
       pnew->next = NULL;
       
   }
}
void DAY43A::Insert_Node(Pnode phead,int n)
{
    //插入第六个节点在第3个节点之前
    Pnode p = phead;
    while(n-- > 1)
    {

        p = p->next;
    }
    Pnode pnew = new Node;
    pnew->a = 6;
    pnew->next = p->next;
    p->next = pnew; 

}
void DAY43A::Delete_Node(Pnode phead,int n)
{
    Pnode p = phead;
    while(n-- > 1)
    {
        p = p->next;
    }
    Pnode T = p->next;
    p->next = T->next;
    delete [] T;
}
void DAY43B::CreateList_Rear(Pnode p)//尾插法最后遍历是相同方向，需要加入一个辅助指针
{
    Pnode r = p;
    /*初始5个点*/
    for(int i = 0;i < 5;++i)
    {
        Pnode pnew = new Node;
        pnew->a = i+1;
        r->next = pnew;
        r = pnew;
        pnew->next = NULL;
    }
}
void DAY43B::CreateList_Head(Pnode p)//头插法最后遍历的时候相反，不需要加入辅助指针
{
    for(int i = 0;i < 5;++i)
    {
        Pnode pnew = new Node;
        pnew->a = i+1; 
        pnew->next = p->next;
        p->next = pnew;
    }
}
void DAY43B::DispList(Pnode p)
{
    Pnode r = p->next;
    while(r != NULL)
    {

        cout<<r->a<<" ";
        r = r->next;
    }
    cout<<endl;
}
template<class T>
void DAY43D::Stack<T>::push(T data)
{
    if(head == NULL)
    {
        head = new Node<T>;
        head->data = data;
        head->next = rear;
        return;
    }
    Node<T>* r = head;
    Node<T>* pnew = new Node<T>;
    pnew->data = static_cast<T>(data);
    head = pnew;
    pnew->next = r;
}
template<class T>
T DAY43D::Stack<T>::pop()
{
    if(head != NULL)
    {
        T temp = static_cast<T>(head->data);
        Node<T>* r = head;
        head = head->next;
        delete [] r;
        r = NULL;
        return temp;
    }
}
template<class T>
DAY43D::Stack<T>::Stack():head(NULL),rear(NULL)
{

}
template<class T>
DAY43D::Stack<T>::~Stack()
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
template<typename T>
void DAY43E::Queue<T>::push(T data)
{
    if(head == NULL)
    {
        head = new Node<T>;
        head->data = data;
        tail = head;
        head->next = NULL;
        return;
    }
    Node<T>* pnew = new Node<T>;
    pnew->data = data;
    tail->next = pnew;
    tail = pnew;
    pnew->next = NULL;
}
template<typename T> 
T DAY43E::Queue<T>::pop()
{
    if(head != NULL)
    {
        T temp = head->data;
        Node<T>* r = head;
        head = head->next;
        delete [] r;
        return temp;
    }

}