#include <stdio.h>
/** 判断是否能够构成三角形，是则返回1否则返回0 **/
int  Traingle(int a,int b,int c);
/** 判断是否是同个三角形，是返回1否则返回0 **/
int isSameTraingle(int a,int b,int c,int _a,int _b,int _c);
int main(int argc ,char *argv[])
{
    int a,b,c;
    int l,r;
    /** 用于计数能够构成三角形的个数 **/
    int count = 0;
    printf("请输入两个正整数l和r\n");
    scanf("%d%d",&l,&r);
    /** 给a,b,c赋初值 **/
    a = b = c = l-1;//
    for(int i = l;i <= r;++i){
        for(int j = l;j <= r ;++j){
            if(j != i){
                 for(int k = l;k <= r;++k){
                     if(k != i && k!= j){
                         if(Traingle(i,j,k)){
                             if(!isSameTraingle(a,b,c,i,j,k)){
                                a = i;
                                b = j;
                                c = k;
                                ++count;
                                if(count > 1)
                                break;
                             }
                        }
                     }
                 }
            } 
        }
    }
    switch(count)
    {
        case 0:
            printf("NO\n");
            break;
        case 1:
            printf("Yes\n%d %d %d\n",a,b,c);
            break;
        default:
            printf("%d %d %d\n",a,b,c);
    }

    return 0;
}
int Traingle(int a,int b,int c)
{
    if(a+b > c && a+c > b && b+c > a)
        return 1;
    return 0;
}
int isSameTraingle(int a,int b,int c,int _a,int _b,int _c)
{
    if(a+b+c == _a+_b+_c ){
       if(a == _b)
            if(b == _c || b == _a)
            return 1;
       if(a == _c)
            if(b == _a || b == _b )
            return 1;
       if(a == _a)
            if(b == _b || b == _c)
            return 1;
    }
    return 0;
}
