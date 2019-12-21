#include <iostream>
int main(int argc,char* argv[])
{
    /* 输入任务数量N,以及M个依赖关系 */
    int N,M;
    std::cin>>N>>M;
    /* 输入每个任务所要花的时间 */
    double time[N];
    for(int i = 0;i < N;++i)
        std::cin>>time[i];
    /* 输入依赖项 */
    int A[M],B[M];
    for(int i = 0;i < M;++i)
        std::cin>>A[i]>>B[i];
    /* 记录时间与方案 */
    double sumtime = 0;
    int schedule[N];
    /* 遍历每个任务 */
    int k = 0;
    while(k < N)
    for(int i = 0;i < N;++i){
        schedule[k++] = i;
        if()
    }

    for(int i = 0;i < N;++i){
        /* 判断是否有子任务 */
        if(0<A[i] && A[i]<N)
        {
            sumtime += time[B[i]];
            sumtime += time[A[i]];

        }
        else
        /* 否则子任务就是其本身 */
        sumtime += time[A[i]];
    }

      
    return 0;
}