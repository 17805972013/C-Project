#ifndef _DAY42_
#define _DAY42_
#include <iostream>
#include <set>
#include <string.h>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <unistd.h>
//#define Scheme1
#define Scheme2
using namespace std;
class Fdate
{
    public:
    Fdate():Precision(100000){}
    string Month;
    double Frequency;
    float a,b,c;
    float Precision;
};
class Fault
{
    public:
    vector<Fdate> _Fdate;
   
};
class Model
{
public:
    Model():Num(1),a(0.0),b(0.0),c(0.0),Precision(100000){}
    int Num;//Model出现的次数
    float a,b,c;//权重设置
    float Precision;//精度
    string ModelName; 
    string date;
    Fault _Fault[204];
};
void Parameterabc(float a,float b,float c,vector<Model> &AllModel,int k);
#endif