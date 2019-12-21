#include "day46.h"
int main(int argc,char* argv[])
{
    #ifdef T1
    using namespace DAY46;
    cout<<endl;
    Node<char>* head = new Node<char>;
    head->lp = NULL;
    head->rp = NULL;
    head->data = 'A';
    CreateDoubleTree(head);//动态创建二叉树
    //PreTransver(head);
    MidTransver(head);
    //LastTransver(head);
    #endif
    #ifdef T2
    using namespace DAY46A;
    #endif
    #ifdef T3
    using namespace DAY46;
    Node<char>* head = new Node<char>;
    head->lp = NULL;
    head->rp = NULL;
    head->data = 'A';
    CreateDoubleTree(head);//动态创建二叉树
    InOrderThreading(head);
    #endif
    printf("hello..\n");
    return 0;
}
template<typename T>
void DAY46::CreateDoubleTree(Node<T>* head)
{
    /* 动态创建二叉树 */
    Node<T>* r;
    queue<Node<T>*> s;
    char c;
    c = getchar();
    head->data = c;
    s.push(head);
    while(c != '\n')
    {
        r = s.pop();
        c = getchar();
        if(c != '\n' && c != '#'){
            r->lp = new Node<T>;
            r->lp->data = c;
            s.push(r->lp);
        }
        else
        {
            if(c == '\n')
                break;
        }
        c = getchar();
        if(c != '\n' && c != '#'){
            r->rp = new Node<T>;
            r->rp->data = c;
            s.push(r->rp);
        }
        else
        {
            if(c == '\n')
                break;
        }
        
    }
} 
template<typename T>
void DAY46::PreTransver(Node<T>* head)
{
    if(head != NULL){
        printf("%c\n",head->data);
        PreTransver(head->lp);
        PreTransver(head->rp);
    }
}
template<typename T>
void DAY46::MidTransver(Node<T>* head)
{
    if(head != NULL){
        MidTransver(head->lp);
        printf("%c\n",head->data);
        MidTransver(head->rp);
    }
}
template<typename T>
void DAY46::LastTransver(Node<T>* head)
{
    if(head != NULL){
        LastTransver(head->lp);
        LastTransver(head->rp);
        printf("%c\n",head->data);
    }
}
template<typename T>
void DAY46::queue<T>::push(T data)
{
    if(head == NULL)
    {
        head = new _Node<T>;
        head->data = data;
        rear = head;
        head->next = NULL;
        return;
    }
    _Node<T>* pnew = new _Node<T>;
    pnew->data = data;
    rear->next = pnew;
    rear = pnew;
    pnew->next = NULL;

}
template<typename T>
T DAY46::queue<T>::pop()
{
    if(head != NULL)
    {

        T temp = head->data;
        head = head->next;
        return temp;
    }
}
template<typename T>
void DAY46::ThreadDoubleTree(Node<T>* head)
{
    if(head != NULL)
    {
        ThreadDoubleTree(head->lp);
        printf("%c\n",head->data);
         if(!head->lp)
        {
            head->ltag = Thread;//标志tag为线索
            head->lp = pre;
        }
        if(!pre->rp)
        {
            head->rtag = Thread;
            pre->rp = head;
        }
        pre = head;
        ThreadDoubleTree(head->rp);
    }
}
template<typename T>
void DAY46::InOrderThreading(Node<T>* &head)
{
    pre = NULL;
    if(!head)
    {
        ThreadDoubleTree(head);
    }
}
template<typename T>
void DAY46A::stack<T>::push(T data)
{
    if(head == NULL)
    {
        head = new _Node<T>;
        head->data = data;
        head->next = NULL;
        return;
    }
    _Node<T>* pnew = new _Node<T>;
    pnew->data = data;
    pnew->next = head;
    head = pnew;
}
template<typename T>
T DAY46A::stack<T>::pop()
{
    if(head != NULL)
    {
        T temp = head->data;
        head = head->next;
        return temp;
    }
}
template<typename T>
void DAY46A::DFS(Node<T>* head)
{
  
    
}