#include "day41.h"
int main(int argc,char* argv[])
{
    #ifdef T1
    //DAY41::Get_Test();
    //DAY41::Getline_Test();
    //DAY41::Get_Test_1();
    //DAY41::Ignore_Test();
    DAY41::Putback_Test();
    #endif
    #ifdef T2
    //DAY41A::Read_File();
    //DAY41A::Write_File();
    //DAY41A::CRead_File();
    DAY41A::CWrite_File();
    #endif
    #ifdef T3
    int a[5] = {2,1,3,4,0};
    set<int> _a(a,a+5);
    string b[5]={"ssss","ssss","llkdhsa","qwdwr","thgh"};
    set<string> _b(b,b+5);
    for(set<string>::iterator iter = _b.begin();iter != _b.end();++iter)
    cout<<*iter<<" ";
    cout<<endl;
    #endif

    cout<<"hello..."<<endl;
    return 0;
}
void DAY41::Get_Test()
{
    char ch;
    while(((ch = cin.get()))!=EOF)
    {
        cout<<ch<<endl;
    }
}
void DAY41::Getline_Test()
{
    /*
        允许接受空格字符
    */
    char buf[50];
    while((cin.getline(buf,50)))
    {
        cout<<buf<<endl;
    }
}
void DAY41::Get_Test_1()
{
  char a,b,c;
  //方式1同时读取三个字符
  cin.get(a);
  cin.get(b);
  cin.get(c);
  cout<<a<<b<<c<<"因为缓存区有数据，程序不会阻塞\n";
  //方式2
  cin.get(a).get(b).get(c);//同时读取三个字符
  cout<<a<<b<<c;   
}
void DAY41::Ignore_Test()
{
    char buf1[256];
    char buf2[256];
    cout<<"请输入一个字符串 含有多个空格aa bbccdd\n";
    cin>>buf1;
    cin.ignore(2);//忽略两个空格
    //cin.peek()的返回值是一个char型字符，其返回值是指向当前字符，但
    //它只是观测指针停留在当前位置并不后移；如果访问的字符是
    //文件结束符，则函数返回值是EOF(-1)
    int myint = cin.peek();
    cout<<"myint:"<<myint<<endl;
    cin.getline(buf2,256);
    cout<<"buf1:"<<buf1<<"\nbuf2:"<<buf2<<endl;
}
void DAY41::Putback_Test()
{
    /*
        将输入的字符串和整数分开
        putback是将字符放回到输入流中,一般输入流中字符的长度是不变的。 
        putback会把cin刚刚“吃”进来的字符再“吐”回去，也就是说，
        下次cin的时候，刚刚得到的那个字符还会被输入
    */
   cout<<"Please,enter a number or a word:";
   char c = cin.get();
   if((c >= '0')&&(c <= '9'))
   {
       int n;
       cin.putback(c);//将数字入栈
       cin>>n;
       cout<<"You enter a number:"<<n<<'\n';
   }
   else
   {
        string str;
        cin.putback(c);
        getline(cin,str);
        cout<<"You enter a word: "<<str<<endl;       
   }
   
}
void DAY41A::Read_File()
{
    ifstream is("read.txt");
    //is.seekg(0,ios::end);//加入这句话，文件读取不到数据
    string line;
    while(getline(is,line))
    {
        cout<<line<<endl;
    }
    is.close();
}
void DAY41A::Write_File()
{
    ofstream os("write.txt",ios::app);
    char buf[256];
    while(cin.getline(buf,356))
    {
        os<<buf<<endl;
    }
    os.close();
}
void DAY41A::CRead_File()
{
    FILE *fp = fopen("read.txt","r");
    char buf[256];
    while(fscanf(fp,"%s",buf) != EOF)
    {
        cout<<buf<<endl;
    }
    fclose(fp);

}
void DAY41A::CWrite_File()
{
   
    char buf[256];
    while(cin>>buf){
        FILE* fp = fopen("write.txt","a+");
        printf("%s\n",buf);
        fprintf(fp,"%s",buf);
        fclose(fp);
    }
    
}