#include "day47.h"
int main(int argc,char* argv[])
{
    #ifdef T1
    using namespace DAY47;
     BiTree<char>* head = new BiTree<char>;
    head->lp = NULL;
    head->rp = NULL;
    head->data = 'A';
    CreateDoubleTree(head);
    PreTransver(head);
    #endif
    printf("hello..\n");
    return 0;
}
template<typename T>
void DAY47::queue<T>::push(T data)
{
    if(head == NULL)
    {
        head = new Node<T>;
        head->data = data;
        tail = head;
        return;
    }
    Node<T>* pnew = new Node<T>;
    pnew->data = data;
    tail->next = pnew;
    tail = pnew;
    pnew->next = NULL;
}
template<typename T>
T DAY47::queue<T>::pop()
{
    if(head != NULL)
    {
        Node<T> *r = head;
        T temp = head->data;
        head = head->next;
        return temp;
    }
}
template<typename T> 
void DAY47::stack<T>::push(T data)
{
    if(head == NULL)
    {
        head = new Node<T>;
        head->data = data;
        head->next = NULL;
        return;
    }
    Node<T>* pnew = new Node<T>;
    pnew->data = data;
    pnew->next = head;
    head = pnew;
}
template<typename T>
T DAY47::stack<T>::pop()
{

    if(head)
    {
        T temp = head->data;
        head = head->next;
        return temp;
    }
}
template<typename T>
void DAY47::CreateDoubleTree(BiTree<T>* head)
{
     /* 动态创建二叉树 */
    BiTree<T>* r;
    queue<BiTree<T>*> s;
    char c;
    c = getchar();
    head->data = c;
    s.push(head);
    while(c != '\n')
    {
        r = s.pop();
        c = getchar();
        if(c != '\n' && c != '#'){
            r->lp = new BiTree<T>;
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
            r->rp = new BiTree<T>;
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
void DAY47::PreTransver(BiTree<T>* head)
{   /* if(head){
        printf("%c\n",head->data);
        PreTransver(head->lp);
        PreTransver(head->rp);
    }*/
    stack<BiTree<T>*> s;
    s.push(head);
    BiTree<T>* r = head;
    while(r){
        while(r)
        {
            printf("%c\n",r->data);
            r = r->lp;
            if(r)
            s.push(r);
        }
        r = s.pop();
        if(r && r->rp){
            r = r->rp;
            s.push(r);
        }
        else
        {
            if(r){
                r = s.pop();
                if(r)
                r = r->rp;
            }
        }
    }
   
}