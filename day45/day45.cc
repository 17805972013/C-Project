#include "day45.h"
int main(int argc,char* argv[])
{
    #ifdef T1
    using namespace DAY45;
     int arr[11] = {1,1,2,3,5,8,13,21,34,55,89};
     int pos = BinSearch(arr,0,10,13);
     cout<<pos<<endl;
     
    #endif
    #ifdef T2
    using namespace DAY45;
    HanTower(3,'X','Y','Z');
    #endif
    #ifdef T3
    using namespace DAY45;
    int chess[8][8];
    for(int i = 0;i < 8;++i)
    for(int j = 0;j < 8;++j)
    chess[i][j] = 0;
    EightQueen(0,0,chess);
    printf("\n总共有 %d 种解决办法！\n",count);
    #endif
    #ifdef T4
    using namespace DAY45;
    int chess[8][8];
    for(int i = 0;i < 8;++i)
    for (int j = 0;j < 8;++j)
    chess[i][j] = 0;
    EightQueen2(0,0,chess);
    printf("\n总共有 %d 种解决办法！\n",count);
    #endif
    #ifdef T5
    using namespace DAY45A;
    char s1[256];
    strcpy(s1,"abc");
    HuiWen(s1,0,strlen(s1));
    cout<<cnt<<endl;
    if(cnt < 2)
    {
        cout<<"是回文串"<<endl;
    }
    else
    {
        cout<<"不是回文串"<<endl;
    }
    
    #endif
    #ifdef T6
    using namespace DAY45A;
    char s1[256];
    strcpy(s1,"(()");
    cout<<strlen(s1)<<endl;
    Match(s1,0,strlen(s1));
    if(cnt < 1)
    {
        cout<<"括号匹配"<<endl;
    }
    else
    {
        cout<<"括号不匹配"<<endl;
    }
    #endif
    #ifdef T7
    using namespace DAY45B;
    char MaxStr[256] = {'\0'};
    RepeatStr((char*)"abcab",MaxStr,6);
    cout<<MaxStr<<endl;
    #endif
    #ifdef T8
    using namespace DAY45B;
    char str[256] = {'\0'};
    char key[256] = {'\0'};
    strcpy(str,"***hellhello world!");
    strcpy(key,"hello");
    int pos = 0;
    pos = OrdinaryAlgorithm(str,key,pos);
    if(pos != -1)
    cout<<"匹配成功，位置"<<pos<<endl;
    else
    cout<<"匹配失败！\n";
    #endif
    #ifdef T9
    using namespace DAY45B;
    char str[256] = {'\0'};
    char key[256] = {'\0'};
    strcpy(str,"ABCABE");
    strcpy(key,"BE");
    int pos = 0;
    pos = KMPAlgorithm(str,key,pos);
    if(pos != -1)
    cout<<"匹配成功，位置"<<pos<<endl;
    else
    cout<<"匹配失败！\n";
    #endif
    return 0;
}
template<typename T>
int DAY45::BinSearch(T* arr,int low, int high,T n)
{
    if(low > high)
    return -1;
    int pos = (low + high)/2;
    if(arr[pos] == n)//常数项
    return pos;
    if(n > arr[pos])
    {
        BinSearch(arr,pos+1,high,n);
    }
    else
        BinSearch(arr,low,pos-1,n);
   

}
void DAY45::HanTower(int n,char x,char y,char z)
{
    if(n == 1)
    printf("%c --> %c\n",x,z);
    else
    {
        HanTower(n-1,x,z,y);
        printf("%c --> %c\n",x,z);
        HanTower(n-1,y,x,z);
    }
    
}
int DAY45::NotDanger(int row,int col,int (*chess)[8])
{
    //行是否有危险
    for(int i = 0;i < 8;++i)
    if(chess[row][i] == 1) return 0;
    //列是否有危险
    for(int i = 0;i < 8;++i)
    if(chess[i][col] == 1) return 0;
    //左上方是否有危险
    for(int i = 0;(row-i>= 0) && (col-i >= 0);++i)
    if(chess[row-i][col-i] == 1) return 0;
    //右下方是否有危险
    for(int i = 0;(row+i < 8) && (col+i < 8);++i)
    if(chess[row+i][col+i] == 1) return 0;
    //右上方是否有危险
    for(int i = 0;(row-i >= 0) && (col+i < 8);++i)
    if(chess[row-i][col+i] == 1) return 0;
    //左下方是否有危险
    for(int i = 0;(row+i < 8) && (col-i >= 0);++i)
    if(chess[row+i][col-i] == 1) return 0;
    return 1;
}
void DAY45::EightQueen(int row,int n,int (*chess)[8])
{
    int chess2[8][8],i,j;  // 临时棋盘
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            chess2[i][j] = chess[i][j]; // 临时棋盘赋值给棋盘
        }
    }
    
    if(row == 8){
        printf("第%d种：\n",count + 1);
        
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                printf("%d ",*(*(chess2+i)+j));
            }
            printf("\n");
        }
        
        count ++;
        
    }else {
        //判断这个位置是否有危险
        //如果有危险，那继续往下
        for(j=0;j<8;j++){
            if(NotDanger(row,j,chess)){ //判断是否危险
                 for(i=0;i<8;i++){ // 不危险
                    *(*(chess2+row)+i)=0;
                 }
                *(*(chess2+row)+j)=1;
                EightQueen(row+1,n,chess2);
            }
        }
    }



}
void DAY45::EightQueen2(int row,int col,int (*chess)[8])
{
    if(row == 8)//终止条件
    {
        cout<<endl;
        for(int i = 0;i < 8;++i){
            for(int j = 0;j < 8;++j)
            cout<<chess[i][j]<<" ";
            cout<<"\n";
        }
        ++count;
    }
    else
    {
        int chess2[8][8];
        for(int i = 0;i < 8;++i)
            for(int j = 0;j < 8;++j)
                chess2[i][j] = chess[i][j];
        for(int i = 0;i < 8;++i){
        if(NotDanger(row,i,chess)){//之所以用chess是为了复盘
            for(int j = 0;j < 8;++j)
                chess2[row][j] = 0;
            chess2[row][i] = 1;
            EightQueen2(row+1,col,chess2);
        }
        }
         
     
    }
}
template<typename T>
void DAY45A::stack<T>::push(T data)
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
T DAY45A::stack<T>::pop()
{
    if(head != NULL)
    {
        T temp = head->data;
        head = head->next;
        return temp;
    }
}
int DAY45A::HuiWen(char s1[],int k,int strlength)
{
   if(cnt > 1 || k >= strlength){
        return cnt;
   }
   stack<char> s;
   for(int i = k;i < strlength;++i)
   s.push(s1[i]);
  
   if(s1[k] == s.pop()){
     HuiWen(s1,k+1,strlength-1);
   }
   else
   {
       cnt++;
       HuiWen(s1,k+1,strlength);
   }
}
void DAY45A::Match(char s1[],int k,int len)
{
    if(cnt > 0 || k > len)
    {
        return;
    }
     stack<char> s;
   for(int i = k;i < len;++i)
   s.push(s1[i]);
   char temp = s.pop(); 
    switch(s1[k])
    {
        case '(':
        case '*':
            if(temp == ')' || temp == '*')
                Match(s1,k+1,len-1);
            else
            {
                ++cnt;
                Match(s1,k+1,len-1);
            }
        break;
        case ')':
            ++cnt;
            Match(s1,k+1,len-1);
        break;
    }
}
void DAY45B::RepeatStr(char str[],char* Maxstr,int len)
{
    char Prestr[len-2][256];//前缀集
    char Laststr[len-2][256];//后缀集
    int k = 0;
    /* 获取前缀集 */
    for(int i = 0;i < len-2;++i)
    {
        char str1[len] = {'\0'};
        for(int j = 0;j < i+1;++j)
        str1[j] = str[j];
        strcpy(Prestr[k++],str1);
    }
    k = 0;
    /* 获取后缀集 */
    for(int i = len-2;i > 0;--i)
    {
        stack<char> s;
        char str1[len] = {'\0'};
        int l = 0;
        for(int j = len-2;j >= i;--j)
        s.push(str[j]);
        while(s.head != NULL){
            str1[l++] = s.pop();
        }
        strcpy(Laststr[k++],str1);

    }
    for(int i = 0;i < len-2;++i)
        if(!strcmp(Prestr[i],Laststr[i])){
            if(strlen(Prestr[i]) > strlen(Maxstr))
            {
                strcpy(Maxstr,Prestr[i]);
            }
        }
}
int DAY45B::OrdinaryAlgorithm(char str[],char key[],int pos)
{
    if(pos+strlen(key) > strlen(str))
    return -1;
    int cnt = 0;
    for(int i = 0;i < strlen(key);++i)
        if(str[pos+i] == key[i])
            ++cnt;
    if(cnt == strlen(key))
        return pos;
    return OrdinaryAlgorithm(str,key,pos+1);
}
int DAY45B::KMPAlgorithm(char str[],char key[],int pos)
{
   if(pos+strlen(key) > strlen(str))
        return -1;
   int cnt = 0;
   int k = 0;
   for(int i = pos;i < strlen(str);++i)
        if(str[i] == key[0]){
            pos = i;
            char _str[256] = {'\0'};
            for(int j = pos;j < strlen(key)+pos;++j)
                if(str[j] != key[j-pos])
                break;
                else
                {
                    _str[j-pos] = key[j-pos];
                }
            char MaxStr[256] = {'\0'};
            RepeatStr(_str,MaxStr,strlen(_str));
            k = strlen(MaxStr);
            break;
        }
      
   for(int i = 0;i < strlen(key)-k;++i)
        if(key[k+i] == str[pos+k+i])
            ++cnt;
   if(cnt == (strlen(key)-k)){
        return pos;
   }
   return KMPAlgorithm(str,key,pos+1);
}