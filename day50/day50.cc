#include "day50.h"
int main(int argc,char* argv[])
{
    #ifdef T1
    clock_t startTime,endTime;
    startTime = clock();
    using namespace DAY50;
    int a[4][4];
    for(int i = 0;i < 4;++i)
        a[i][i] = 0;
    a[0][1] = a[1][0] = 1;
    a[0][2] = a[2][0] = 1;
    a[0][3] = a[3][0] = 1;
    a[1][2] = a[2][1] = 0;
    a[1][3] = a[3][1] = 1;
    a[2][3] = a[3][2] = 1;
    BFS(a);
    endTime = clock();
    cout<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<endl;
    #endif
    #ifdef T2
    using namespace DAY50A;
    clock_t startTime,endTime;
    startTime = clock();
    /* Create Chess */
    int a[8][8];
    for(int i = 0;i < 8;++i)
        for(int j = 0;j < 8;++j)
        a[i][j] = 0;
    a[0][0] = 1;
    TravelChessBoard(a,0,0,1);
    endTime = clock();
    cout<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<endl;
    #endif
    printf("hello..\n");
    return 0;
}
template<typename T>
void DAY50::queue<T>::push(T data)
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
}
template<typename T>
T DAY50::queue<T>::pop()
{
    if(head)
    {
        T temp = head->data;
        head = head->next;
        return temp;
    }
}
void DAY50::BFS(int a[][4])
{
    int visit[4] = {1,0,0,0};
    queue<int> s;
    s.push(0);
    printf("%d  ",0);
    while(s.head)
    {
        int pos = s.pop();
        for(int i = 0;i < 4;++i)
        if(a[pos][i] == 1)
        {
            if(visit[i] == 0){
                s.push(i);
                visit[i] = 1;
                printf("%d  ",i);
            }
        }
    }
    cout<<endl;
}
int DAY50A::SelPoint(int &x,int &y,int sel)
{
    switch(sel)
    {
        case 0:
            if(x >=1 && y>=2){
                x = x-1;
                y = y-2;
                return 1;
            }
            return 0;
        case 1:
            if(x >=1 && y<=5){
                x = x-1;
                y = y+2;
                return 1;
            }
           return 0;
        case 2:
            if(x <= 6 && y >=2){
                x = x+1;
                y = y-2;
                return 1;
            }
            return 0;
        case 3:
            if(x <= 6 && y <= 5){
                x = x+1;
                y = y+2;
                return 1;
            }
              return 0;
        case 4:
            if(x >= 2 && y >= 1){
                x = x-2;
                y = y-1;
                return 1;
            }
             return 0;
        case 5:
            if(x >= 2 && y <= 6){
                x = x-2;
                y = y+1;
                return 1;
            }
             return 0;
        case 6:
            if(x <= 5 && y >= 1){
                x = x+2;
                y = y-1;
                return 1;
            }
            return 0;
        case 7:
            if(x <= 5 && y <= 6){
                x = x+2;
                y = y+1;
                return 1;
            }
            return 0;
        default:
        cerr<<"error\n";
        return 0;
    }
}
void DAY50A::TravelChessBoard(int a[][8],int x,int y,int cnt)
{
    //终止条件
    int chess[8][8];//临时棋盘
    for(int i = 0;i < 8;++i)
        for(int j = 0;j < 8;++j){
            chess[i][j] = a[i][j];
        } 
    if(cnt == 64)
    {
        printf("**************解法%d***************\n",++k);
        for(int i = 0;i < 8;++i){
            for(int j = 0;j < 8;++j)
            printf("%d\t",chess[i][j]);
            cout<<"\n\n";
        }
        return;
    }
    for(int i = 0;i < 8;++i){
        int _x = x;
        int _y = y;
        if(SelPoint(_x,_y,i))
        {
            if(chess[_x][_y] == 0){
                for(int j = 0;j < 8;++j)
                    for(int m = 0;m < 8;++m)
                    if(chess[j][m] == cnt+1)
                    {
                        chess[j][m] = 0;
                        break;
                    }
                chess[_x][_y] = cnt+1;
                TravelChessBoard(chess,_x,_y,cnt+1);
            }
        }
    }
}