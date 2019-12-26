#include "day51.h"
int main(int argc,char* argv[])
{
    #ifdef T1
    using namespace DAY51;
    int a[6][6];
    for(int i = 0;i < 6;++i)
        a[i][i] = 0;
    a[0][1] = a[1][0] = 6;
    a[0][2] = a[2][0] = 1;
    a[0][3] = a[3][0] = 5;
    a[0][4] = a[4][0] = 100;
    a[0][5] = a[5][0] = 100;
    a[1][2] = a[2][1] = 5;
    a[1][3] = a[3][1] = 100;
    a[1][4] = a[4][1] = 3;
    a[1][5] = a[5][1] = 100;
    a[2][3] = a[3][2] = 5;
    a[2][4] = a[4][2] = 6;
    a[2][5] = a[5][2] = 4;
    a[3][4] = a[4][3] = 100;
    a[3][5] = a[5][3] = 2;
    a[4][5] = a[5][4] = 6;
    queue<int> s;
    for(int i = 0;i < 6;++i)
        s.push(i);
    queue<int> s1;
    s1.push(0);
    Pulimu(a,s,s1);
    #endif
    printf("hello..\n");
    return 0;
}
template<typename T>
void DAY51::queue<T>::push(T data)
{
    if(head == NULL)
    {
        head = new Node<T>;
        head->data = data;
        rear = head;
        head->next = NULL;
        return;
    }
    Node<T>* pnew =  new Node<T>;
    pnew->data = data;
    rear->next = pnew;
    rear = pnew;
    pnew->next = NULL;
}
template<typename T>
T DAY51::queue<T>::pop()
{
    if(head)
    {
        T temp = head->data;
        head = head->next;
        return temp;
    }
}
void DAY51::Pulimu(int a[][6],queue<int> s,queue<int> s1)
{
    if(s.head)
    {
        queue<int> s2;
        while(s.head)
        {
            queue<int> s3 = s1;
            bool flags = true;
            int temp = s.pop();
            while(s3.head)
            {
                int temp1 = s3.pop();
                if(temp == temp1)
                {
                    flags = false;
                }
            }
            if(flags)
            {
                s2.push(temp);
            }
        }
        s = s2;
        int i = -1;
        int j = -1;
        int temp = 200;
        while(s.head)
        {  
            queue<int> s3 = s1;
            int l = s.pop();
            int m;
            while(s3.head)
            {
                m = s3.pop();
                if(a[l][m] < temp){
                    i = l;
                    j = m;
                    temp =a[l][m];
                }
            }
        }
        if(j != -1){
        printf("%d-->%d = %d\n",j,i,a[i][j]);
        sum += a[i][j];
        s1.push(i);
        }
        Pulimu(a,s2,s1);
    }
    else
    {
        printf("最小权值和 = %d\n",sum);
    }
    
}