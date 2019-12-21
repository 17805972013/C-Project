#include "day49.h"
int main(int argc,char* argv[])
{
    #ifdef T1
    using namespace DAY49;
    A K;
    A S;
    cout<<K+S<<endl;
    cout<<K*S<<endl;
    cin>>K;
    cout<<K;
    #endif
    #ifdef T2
    using namespace DAY49A;
    int v,e;
    cin>>v>>e;
    Node a[e];
    int first[e];
    int next[e];
    for(int i = 0;i < e;++i)
    {
        first[i] = -1;
        next[i] = -1;
    }
    for(int i = 0;i < e;++i){
        cin>>a[i];
        if(first[a[i].u-1] == -1)
        {
            first[a[i].u-1] = i;
        }
        else
        {
            next[i] = first[a[i].u-1];
            first[a[i].u-1] = i;
        }
    }
    cout<<"*******\n";
    for(int i = 0;i < e;++i)
        if(first[i] != -1)
        {
            int k = first[i];
            while(k != -1){
                cout<<a[k]<<endl;
                k = next[k];
            }
        }
    #endif
    #ifdef T3
    using namespace DAY49B;
    int a[4][4];
    for(int i = 0;i < 4;++i)
        a[i][i] = 0;
    a[0][1] = a[1][0] = 1;
    a[0][2] = a[2][0] = 1;
    a[0][3] = a[3][0] = 1;
    a[1][2] = a[2][1] = 0;
    a[1][3] = a[3][1] = 1;
    a[2][3] = a[3][2] = 1;
    //TraverGraph(a,0);
    TraverGraph_1(a);
    #endif
    printf("hello..\n");
    return 0;
}
template<typename T>
void DAY49B::stack<T>::push(T data)
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
T DAY49B::stack<T>::pop()
{
    if(head)
    {
        T temp = head->data;
        head = head->next;
        return temp;
    }
}
void DAY49B::TraverGraph(int a[][4],int pos)
{
   //递归实现方式
   if(visit[pos] != -1)
    return;
  printf("%d ",pos);
  visit[pos] = 0;
  for(int i = 0;i < 4;++i)
    if(a[pos][i] == 1 && visit[i] == -1)
    {
        TraverGraph(a,i);
    }
    
}
void DAY49B::TraverGraph_1(int a[][4])
{
    //非递归实现方式
    stack<int> s;
    int pos = 0;
    s.push(pos);
    while(s.head)
    {
        if(visit[pos] == -1){
            printf("%d ",pos);
            visit[pos] = 0;
        }
        int cnt = 0;
        for(int i = 0;i < 4;++i)
            if(a[pos][i] == 1 && visit[i] == -1)
            {
                
                pos = i;
                s.push(pos);
                break;
            }
            else
            {
                ++cnt;
            }
        if(cnt == 4)
            s.pop();
    }
}