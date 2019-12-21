#include "day48.h"
int main(int argc,char* argv[])
{
    #ifdef T1
    using namespace DAY48;
    Node* head = new Node;
    pre = head;
    CreateDoubleTree(head);
    MidTranverse(head);
    
    ThreadDoubleTree(head);
    #endif
    #ifdef T2
    using namespace DAY48A;
    queue s;
    _Node a[7];
    a[0].data = 'A';
    a[0].frequency = 60;
    a[1].data = 'B';
    a[1].frequency = 45;
    a[2].data = 'C';
    a[2].frequency = 13;
    a[3].data = 'D';
    a[3].frequency = 69;
    a[4].data = 'E';
    a[4].frequency = 14;
    a[5].data = 'F';
    a[5].frequency = 5;
    a[6].data = 'G';
    a[6].frequency = 3;
    for(int i = 0;i < 7;++i){
        a[i].lchild = NULL;
        a[i].rchild = NULL;
        s.insert(&a[i]);
    }
    s.Table = new HuffmanTable[s.Getlength()];
    CreatHuffman(s);
    CreateHuffmanTable(s.head->data,s.Table);
     for(int i = 0;i < 7;++i)
    {
        cout<<s.Table[i].name<<":"<<s.Table[i].PreCode<<endl;
    }
    #endif
    printf("hello...\n");
    return 0;
}
void DAY48::CreateDoubleTree(Node* head)
{
    head->data = 'A';
    Node* l1 = new Node;
    l1->data = 'B';
    Node* r1 = new Node;
    r1->data = 'C';
    head->lchild = l1;
    head->rchild = r1;
    Node* l2 = new Node;
    l2->data = 'D';
    l1->lchild = l2;
    Node* r2 = new Node;
    r2->data = 'E';
    l1->rchild = r2;
}
void DAY48::MidTranverse(Node* head)
{
    if(head)
    {
        MidTranverse(head->lchild);
        printf("%c\n",head->data);
        if(!head->lchild)
        {
            head->ltag = Thread;
            head->lchild = pre;
        }
        if(pre && !pre->rchild)
        {
            pre->rtag = Thread;
            pre->rchild = head;
        }
        pre = head;
        MidTranverse(head->rchild);
    }
}
void DAY48A::queue::insert(_Node* data)
{
    if(head == NULL)
    {
        head = new Link;
        head->data = data;
        tail = head;
        head->next = NULL;
        return;
    }
    Link* pnew = new Link;
    pnew->data = data;
    Link *r = head;
     while(r)
    {
        if(r->data->frequency > data->frequency)
        {
            _Node* temp = pnew->data;
            pnew->data = r->data;
            r->data = temp;
        }
        r = r->next;
    }
    tail->next = pnew;
    tail = pnew;
    pnew->next = NULL;
}
DAY48A::_Node*  DAY48A::queue::pop()
{
    if(head)
    {
        DAY48A::_Node *temp = head->data;
        head = head->next;
        return temp;
    }
    return NULL;
}
int DAY48A::queue::Getlength()
{
    Link* r = head;
    int len = 0;
    while(r)
    {
        ++len;
        r = r->next;
    }
    return len;
}
void DAY48A::CreatHuffman(queue& s)
{
    if(s.Getlength() == 1)
        return;
    _Node* l = s.pop();
    _Node* r = s.pop();
    _Node* pnew = new _Node;
    l->flag = '0';
    r->flag = '1';
    pnew->frequency = l->frequency+r->frequency;
    pnew->lchild = l;
    pnew->rchild = r;
    l->pre = pnew;
    r->pre = pnew;
    s.insert(pnew);
    CreatHuffman(s);
}
void DAY48A::stack::push(int data)
{
    if(head == NULL)
    {
        head = new __Node;
        head->data = data;
        head->next = NULL;
        return;
    }
    __Node* pnew = new __Node;
    pnew->data = data;
    pnew->next = head;
    head = pnew;
}
int DAY48A::stack::pop()
{
    int temp = head->data;
    head = head->next;
    return temp;
}
template<typename T>
void DAY48A::Stack<T>::push(T data)
{
    if(head == NULL)
    {
        head = new NodeTree<T>;
        head->data = data;
        head->next = NULL;
        return;
    }
    NodeTree<T>* pnew = new NodeTree<T>;
    pnew->data = data; 
    pnew->next = head;
    head = pnew;
}
template<typename T>
T DAY48A::Stack<T>::pop()
{
    if(head)
    {
        T temp = head->data;
        head = head->next;
        return temp;
    }
}
template<typename T>
void DAY48A::Queue<T>::push(T data)
{
    if(head == NULL)
    {
        head = new NodeTree<T>;
        head->data = data;
        tail = head;
        head->next = NULL;
        return;
    }
    NodeTree<T> * pnew = new NodeTree<T>;
    pnew->data = data;
    tail->next = pnew;
    tail = pnew;
}
template<typename T> 
T DAY48A::Queue<T>::pop()
{
    if(head)
    {
        T temp = head->data;
        head = head->next;
        return temp;
    }
}
void DAY48A::CreateHuffmanTable(_Node* p,HuffmanTable* Table)
{
    /* 非递归先序遍历 */
    /*
    Stack<_Node*> s;
    s.push(p);
    _Node* r = p;
    while(s.head){
     while(r)
     {
         printf("%cs",r->data);
         s.push(r);
         r = r->lchild;
         
     }
        r = s.pop();
        r = r->rchild;
    }
    cout<<endl;
     */
    if(p){
        for(int j = 0;j < 7;++j)
        if(p->data == 'A'+j)
        {
            _Node* r = p;
            Stack<char> s;
            Table[j].name = r->data;
            while(r)
            {
                s.push(r->flag);
                r = r->pre;
            }
            int k = 0;
            while(s.head)
            {
                char t = s.pop();
                if(t != '\0')
                Table[j].PreCode[k++] = t;
            }
        }
    CreateHuffmanTable(p->lchild,Table);
    CreateHuffmanTable(p->rchild,Table);
    }
    
}
