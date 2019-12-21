#include <iostream>
#include <vector>
#include <sstream>
#include <unistd.h>
int main(int argc,char* argv[])
{

    std::vector<int> a;
    /* 字符转数字 */
    std::stringstream ss;
    char c;
    int num;
    /* A与B的容器 */
    std::vector<int> A,B;
    while(c=getchar()){
        if(c == '\n')
        break;
        if(c == ' ')
        continue;
        ss<<c;
        ss>>num;
        ss.clear();
        A.push_back(num);
    }
     while(c=getchar()){
        if(c == '\n')
        break;
        if(c == ' ')
        continue;
        ss<<c;
        ss>>num;
        ss.clear();
        B.push_back(num);
    }
    /* 找出A中不符合升序的数 */
    int seq;//记录序号
    int val;//记录值
    for(int i = 0;i < A.size()-1;++i){
        if(A[0] > A[1]){
            seq = 0;
            val = A[1];
            break;
        }
        if(A[A.size()-1] < A[A.size()-2]){
            seq = A.size()-1;
            val = A[A.size()-2];
            break;
        }
      if(A[i] >= A[i+1]){
          seq = i+1;
          val = A[i+1];
      }
    }
    /* 在B中找出满足的最大数 */
    int err = 0;//用于判断是否存在
    for(int i = 0;i < B.size();++i){
        if(B[i] < val && B[i] > A[seq-1]){
            A[seq] = B[i];
            ++err;
        }
    }
    if(err == 0){
        printf("NO\n");
    }
    else
    for(int i = 0;i < A.size();++i){
        printf("%d ",A[i]);
    }
    printf("\n");
  
    
    return 0;
}