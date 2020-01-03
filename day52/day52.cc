#include "day52.h"
int main(int argc,char* argv[])
{
    #ifdef T1
    using namespace DAY52;
    int v,e;
    cin>>v>>e;
    int first[e] = {-1,-1,-1,-1,-1};
    int next[e] = {-1,-1,-1,-1,-1};
    Node p[e];
    for(int i = 0;i < e;++i)
    {
        cin>>p[i];
        if(first[p[i].u-1] == -1)
            first[p[i].u-1] = i;
        else
        { 
            next[i] = first[p[i].u-1];
            first[p[i].u-1] = i;
        }
    }
    cout<<"**********\n";
   for(int i = 0;i < e;++i)
        if(first[i] != -1)
        {
            int k = first[i];
            while(k != -1){
                cout<<p[k]<<endl;
                k = next[k];
            }
        }
    #endif
    #ifdef T2
    using namespace DAY52;
    queue<int> s;
    queue<int> s1;
    Node p[9];
    int Degree[9] = {0};
    int visit[9] = {0};
    for(int i = 0;i < 9;++i){
        cin>>p[i];
        ++Degree[p[i].v-1];
    }
    for(int i = 0;i < 9;++i)
    cout<<Degree[i]<<" ";
    cout<<endl;
    while(1){
        int len = 0;
        for(int i = 0;i < 9;++i){
            if(visit[i] == 1)
                ++len;
        }
        if(len == 9){
         cout<<endl;
            break;
        }
    for(int i = 0;i < 9;++i)
        if(Degree[i] == 0 && visit[i] == 0)
        {
            printf("%d ",i);
            s.push(i);
            visit[i] = 1;
        }
    while(s.head)
    {
        int t = s.pop();
        for(int i = 0;i < 9;++i)
        {
            if(p[i].u-1 == t)
            {
                --Degree[p[i].v-1];
            }
        }
    }
    }
    #endif
    #ifdef T3
    using namespace DAY52A;
    //创建邻接表
    int v,e;
    cin>>v>>e;
    int ve[v] = {0};//事件最早发生时间
    int vl[v];//事件最迟发生时间
    for(int i = 0;i < v;++i)
        vl[i] = 10;
    int ee[e] = {0};//活动最早发生时间

    int el[e] = {0};//活动最迟发生时间

    int degree[v] = {0};//顶点入度
    int visit[v] = {0};
    Edge p[v];
    for(int i = 0;i < e;++i){
        cin>>p[i];
        ++degree[p[i].v];
    }
    for(int i = 0;i < v;++i)
        for(int j = 0;j < v;++j)
            if(p[j].v == i)
                if(ve[i] < ve[p[j].u]+p[j].w){
                    ve[i] = ve[p[j].u]+p[j].w;
                }

    for(int i = v-2;i >= 0;--i)
        for(int j = 0;j < v;++j)
            if(p[j].u == i)
                if(vl[i] > vl[p[j].v]-p[j].w)
                    vl[i] = vl[p[j].v]-p[j].w;
    for(int i = 0;i < v;++i)
    cout<<vl[i]<<" ";
    cout<<endl;
    #endif
    printf("hello..\n");
    return 0;
}
template<typename T>
void DAY52::queue<T>::push(T data)
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
T DAY52::queue<T>::pop()
{
    if(head)
    {
        T temp = head->data;
        head = head->next;
        return temp;
    }
}
template<typename T>
void DAY52A::stack<T>::push(T data)
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
T DAY52A::stack<T>::pop()
{
    if(head)
    {
        T t = head->data;
        head = head->next;
        return t;
    }
}