#include "day44.h"
inline double Char2Num(int n)
{
    double sum(1);
    for(int i = 0;i < n;++i)
    {
        sum *= 0.1;
    }
    return sum;
}
int main(int argc,char* argv[])
{
    #ifdef T1
    using namespace DAY44; 
    Pnode p = new Node;
    CircleList(p,5);
    Disp(p,6);
    Insert(p,3,5);
    Disp(p,6);
    Delete(p,2);
    Disp(p,6);
    Pnode q = new Node;
    CircleList(q,11);
    //Disp(q,11);
    Ysfh(q,11,4);
    #endif
    #ifdef T2
    using namespace  DAY44A;
    Pnode p = new Node;
    CreateDoubleList(p);
    Disp(p);
    #endif
    #ifdef T3
    using namespace DAY44B;
    stack<double> s;
    char c;
    double a,b;
    char r[256];//用来缓存数据
    memset(r,'\0',256);
    int i(0);
    while(c != '$')
    {
      c = getchar();
      double num;
      if('0' < c && c < '9' || c == '.'){
        r[i++] = c;
        num = atof(r);
        continue;
     }
      if(strlen(r) != 0 && c == ' ')
     {
         i = 0;
         memset(r,'\0',256);
         s.push(num);
     }
      switch(c)
      {
          case '+':
          b = s.pop();
          a = s.pop();
          s.push(a+b);
          break;
          case '-':
          b = s.pop();
          a = s.pop();
          s.push(a-b);
          break;
          case '*':
          b = s.pop();
          a = s.pop();
          s.push(a*b);
          break
          case '/':
          b = s.pop();
          a = s.pop();
          if(b != 0)
          s.push(a/b);
          else
          {
              cerr<<"您的输入有误！\n";
             return -1;
          }
          break;
          case '=':
          b = s.pop();
          a = s.pop();
          s.push(b);
          break;
      }
    }
   while(s.head != NULL)
   {
       cout<<s.pop();
   }
    #endif
    #ifdef T4
    using namespace DAY44B;
    stack<char> s;
    stack<char> s1;
    stack<char> s2;
    stack<double> s3;
    char c('0');
    char str[256];
    memset(str,'\0',256);
    int i(0);
    while(c != '#')
    {
        c = getchar(); 
        if('0' <= c && c <= '9' || c == '.')
        {
            s1.push(c);
            str[i++] = c;
            continue;
        }
        if(strlen(str) != 0 && c == ' ')
        {
            s1.push(' ');
            i = 0;
            memset(str,'\0',256);
        }
        switch(c)
        {
            case '+':
            while(s.head !=NULL && s.head->data != '(')
            {
                s1.push(s.pop());
                s1.push(' ');
            }
            s.push(c);
            break;
            case '-':
            while(s.head != NULL && s.head->data != '(')
            {
                s1.push(s.pop());
                s1.push(' ');
            }
            s.push(c);
            break;
            case '*':
            s.push(c);
            break;
            case '/':
            s.push(c);
            break;
            case '(':
            s.push(c);
            break;
            case ')':
            while(s.head != NULL && s.head->data != '(')
            {
                s1.push(s.pop());
                s1.push(' ');
            }
            s.pop();
            break; 
        }
    }
    while(s.head != NULL)
    {
        s1.push(s.pop());
        s1.push(' ');
    }
    while(s1.head != NULL)
    {
        s2.push(s1.pop());
    }
    double a,b;
    while(s2.head != NULL){
      c = s2.pop();
      if('0' < c && c < '9' || c == '.'){
        str[i++] = c;
        continue;
     }
      if(strlen(str) != 0 && c == ' ')
     {
         double num = atof(str);
         i = 0;
         memset(str,'\0',256);
         s3.push(num);
     }
      switch(c)
      {
          case '+':
          b = s3.pop();
          a = s3.pop();
          s3.push(a+b);
          break;
          case '-':
          b = s3.pop();
          a = s3.pop();
          s3.push(a-b);
          break;
          case '*':
          b = s3.pop();
          a = s3.pop();
          s3.push(a*b);
          break;
          case '/':
          b = s3.pop();
          a = s3.pop();
          if(b != 0)
          s3.push(a/b);
          else
          {
              cerr<<"您的输入有误！\n";
             return -1;
          }
          break;
          case '=':
          b = s3.pop();
          a = s3.pop();
          s3.push(b);
          break;
      }
    }
    while(s3.head != NULL)
   {
       cout<<s3.pop();
   }
    #endif
    #ifdef T5
    using namespace DAY44C;
    queue<double> s;
    s.push(1);
    s.push(3.14);
    s.push(2.34);
    while(s.head != NULL)
    {
        cout<<s.pop()<<" ";
    }
    cout<<endl;
    #endif
    return 0;
}
void DAY44::CircleList(Pnode p,int sum)
{
    //建立数量为sum的循环链表
    Pnode r = p;
    if(p != NULL)
    {
        for(int i = 0;i < sum;++i)
        {
            if(i < sum-1){
            Pnode pnew = new Node;
            pnew->data = i+1;
            r->next = pnew;
            r = pnew;
            }
            else
            {
                r->next = p->next;
            }
            
        }
    }
}
void DAY44::Disp(Pnode p,int n)
{
    Pnode r = p->next;
    while(n--)
    {
        cout<<r->data<<" ";
        r = r->next;
    }
    cout<<endl;
}
void DAY44::Insert(Pnode p,int pos,int e)
{
    Pnode r = p->next;
    while(pos-- > 2)
    {
        r = r->next;
    }
    Pnode pnew = new Node;
    pnew->data = e;
    Pnode _r = r->next;
    r->next = pnew;
    pnew->next = _r;
}
void DAY44::Delete(Pnode p,int pos)
{
    Pnode r = p->next;
    while(pos-- > 2)
    {
        r = r->next;
    }
    Pnode _r = r->next;
    r->next = _r->next;
    delete [] _r;
    _r = NULL;
}
void DAY44::Ysfh(Pnode p,int sum,int pos)
{
    if(sum == 5){
    return;
    }
    Pnode r = p->next;
    while(pos-->2)
    {
        r = r->next;
    }
    Pnode _r = r->next;
    r->next = _r->next;
    printf("%d\n",_r->data);
    delete [] _r;
    _r = NULL;
    Ysfh(r,--sum,pos);
}
void DAY44A::CreateDoubleList(Pnode p)
{
    //建立长度为5的双向链表
    Pnode r = p;
    p->data = 0;
    for(int i = 0;i < 5;++i)
    { 
        Pnode pnew = new Node;
        pnew->data = i+1;
        r->next = pnew;
        pnew->prev = r;
        r = pnew;
        pnew->next = NULL;
    }
}
void DAY44A::Disp(Pnode p)
{
    Pnode r = p->next;
    while(r != NULL)
    {
        printf("%d ",r->data);
        printf("前一个数为：%d\n",r->prev->data);
        r = r->next;
    }
    printf("\n");
}
template<typename T>
void DAY44B::stack<T>::push(T data)
{
    if(head == NULL)
    {
        head = new Node<T>;
        head->data = data;
        head->next = NULL;
        return;
    }
    Node<T> *pnew  = new Node<T>;
    pnew->data = data;
    pnew->next = head;
    head = pnew;
}
template<typename T>
T DAY44B::stack<T>::pop()
{
    if(head != NULL)
    {
      
        T temp = head->data;
        Node<T>* r = head;
        head = head->next;
        delete [] r;
        r = NULL;
        return temp;
    }
    return '\0';
}
template<typename T>
void DAY44C::queue<T>::push(T data)
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
T DAY44C::queue<T>::pop()
{
    if(head != NULL)
    {
        Node<T>*  temp = head;
        head = head->next;
        return temp->data;
    }
}