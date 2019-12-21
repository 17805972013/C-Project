#include "day42.h"
/*
    Author:Qingwei Zeng
    Date:2019/11/19
    使用说明：
    1.将导入的文件每个按照顺序排好
    2.将要导入的文件删除不必要的部分：
    删除第一行名字，最后两列月接收量和月故障量只保留数据部分。
    3.修改好文件后另存为DATA.csv格式的文件(注意不是UTF8那个)；
    4.将文件放在程序文件.h,.cc文件同一个目录下；
    5.编译运行稍等片刻
    6.结果会在显示屏上输出并生成Result.txt文件
    特别声明：
*/
int main(int argc,char* argv[])
{
   /*  string ModelType;
    set<string> Sort;
    int TypeCnt(0);
    ifstream is1("test.csv");
    while(is1>>ModelType)
    {
        Sort.insert(ModelType);
    }
    is1.close();
    ofstream __os("test1.csv",ios::ate);
    for(set<string>::iterator iter = Sort.begin();iter!=Sort.end();++iter){
        __os<<*iter<<endl;
    }
    __os.close();*/
  
    string line;
    stringstream ss;
    ifstream is("DATA.csv");
    ofstream os("Data.csv",ios::ate);//如果有文件清空该文件并重新写入
    while(is>>line)
    {
        line += ",";
        os<<line;
    }
    os.close();
    is.close();
    ifstream _is("Data.csv");
    int cnt = 0;
    vector<Model> AllModel;
    vector<string> Month;
    int Mcnt(0);
    while(getline(_is,line,','))
    {
        if(cnt%206 ==1 && Mcnt < 21)
        {
            Month.push_back(line);
            ++Mcnt;
        }
        if(cnt%206 == 0)
        {
            int _cnt(0);
            for(vector<Model>::iterator iter = AllModel.begin();iter!=AllModel.end();++iter)
            if(line != iter->ModelName )
              ++_cnt;
            else
                ++iter->Num;
            Model T;
            if(_cnt == AllModel.size()){
                T.ModelName = line;
                AllModel.push_back(T);
            }
        }
        ++cnt;
    }
    _is.close();
     ifstream __is("Data.csv");
     cnt = 0;
     int _cnt(0);
     int Fault_Point(2);
     Fault T[204];
    while(getline(__is,line,',')){
        if(Fault_Point == 206)
            Fault_Point = 2;
        if(cnt%206 == Fault_Point){//故障点0
            Fdate T1;
            ss<<line;
            ss>>T1.Frequency;
            ss.clear();
            T[Fault_Point-2]._Fdate.push_back(T1);
            ++Fault_Point;
        }
        ++cnt;
    }
     __is.close();
     for(int i = 0;i < AllModel.size();++i)//所有Model的信息
     for(int j = 0;j < 204;++j)//Model[i]的所有故障点信息
     for(int k = 21*i;k < 21*(i+1);++k){//Model[i]的故障点j的所有月份信息
        Fdate _T;
        _T.Frequency = T[j]._Fdate[k].Frequency;
        AllModel[i]._Fault[j]._Fdate.push_back(_T);
     }
     float a,b,c;
     for(int k = 0;k < AllModel.size();++k)
     for(int i = 0;i < 100;++i)
     {
         a = i*0.01;
         for(int j = 0;j < 100*(1-a);++j){
            b = j*0.01;
            c = 1-a-b;
            Parameterabc(a,b,c,AllModel,k);
         }
     }
     #ifdef Scheme1
     ofstream _os("Result.txt",ios::ate);
     _os<<"Model,Month,a,b,c,Precision\n";
     for(int k = 0;k < AllModel.size();++k)
     for(int i = 0;i < 17;++i)
       _os<<AllModel[k].ModelName<<","<<Month[i+4]<<","<<AllModel[k]._Fault[0]._Fdate[i+4].a<<","<<AllModel[k]._Fault[0]._Fdate[i+4].b<<","
       <<AllModel[k]._Fault[0]._Fdate[i+4].c<<","<<AllModel[k]._Fault[0]._Fdate[i+4].Precision<<endl;
     _os.close();
     #endif
     #ifdef Scheme2
     ofstream _os("Model_Result.csv",ios::ate);
     _os<<"ModelType,a,b,c,Precision\n";
     for(int i = 0;i < AllModel.size();++i)
     _os<<AllModel[i].ModelName<<","<<AllModel[i].a<<","<<AllModel[i].b<<","<<AllModel[i].c<<","<<AllModel[i].Precision<<endl;
     _os.close();
     #endif
    return 0; 
}
void Parameterabc(float a,float b,float c,vector<Model> &AllModel,int k)
{

    #ifdef Scheme1
        double A,B,C;
        for(int j = 0;j < 17;++j){
        double AllSum(0);
        double Sum(0);
        for(int i = 0;i < 204;++i){
        A = a*AllModel[k]._Fault[i]._Fdate[j].Frequency;
        B = b*AllModel[k]._Fault[i]._Fdate[j+1].Frequency;
        C = c*AllModel[k]._Fault[i]._Fdate[j+2].Frequency;
        Sum = fabs(A+B+C-AllModel[k]._Fault[i]._Fdate[j+4].Frequency);//Model0所有故障点5月份的精度
        AllSum += Sum;
        }
        AllSum /= 204;
         if(AllModel[k]._Fault[0]._Fdate[j+4].Precision > AllSum)
         {
             AllModel[k]._Fault[0]._Fdate[j+4].Precision = AllSum;
             AllModel[k]._Fault[0]._Fdate[j+4].a = a;
             AllModel[k]._Fault[0]._Fdate[j+4].b = b;
             AllModel[k]._Fault[0]._Fdate[j+4].c = c;
         }
        }
    #endif
    #ifdef Scheme2
    double Sum(0);
    double AveSum(0);
    double AllSum(0);
    double A,B,C;
    for(int j = 0;j < 204;++j){
        AveSum = 0;
        for(int i = 0;i < 17;++i){
        A = a*AllModel[k]._Fault[j]._Fdate[i].Frequency;//9月份故障点0次数
        B = b*AllModel[k]._Fault[j]._Fdate[i+1].Frequency;//10月份故障点0次数
        C = c*AllModel[k]._Fault[j]._Fdate[i+2].Frequency;//11月份故障点0次数 
        Sum = fabs(A+B+C-AllModel[k]._Fault[j]._Fdate[i+4].Frequency);//model0故障点j的精度
        AveSum += (Sum/17);//model0故障点j的平均精度
        }
        AllSum += AveSum;//Model0所有故障点平均精度之和
        Sum = 0;
    }
    AllSum /= 204;//Model0所有故障点平均精度
    if(AllModel[k].Precision > AllSum){
        AllModel[k].Precision = AllSum;
        AllModel[k].a = a;
        AllModel[k].b = b;
        AllModel[k].c = c;
    }
    #endif
}