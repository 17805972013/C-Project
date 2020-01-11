#ifndef _DAY56_
#define _DAY56_
#include <iostream>
#include <math.h>
#include <time.h>
#include <vector>
#include <queue>
using namespace std;
#define T1
namespace DAY56
{
    double Ptx = 10;
    double Catt = 70;
    double Att = 3;
    double Ratt = 5;
    double d0 = 1.5;
    double Wl = 3;
    double H0 = 15;
    double Hs = 1.5;
    double theta_ele = 26.5;
    double S = 200;
    int M = 20;//路段数
    int WaveNum = 10;//波数
    double l = S/M;
    double N_floor = -174;
    double NF = 6;
    double B = 2000000000;
    double d = sqrt((d0+Wl)*(d0+Wl)+H0*H0);
    //double A = pow(10.0,(Ptx-Catt-Att-Ratt)/10.0);
}
namespace DAY56A
{
    int cnt = 0;
    vector<vector<int>> result;//存储所有的情况
    using namespace DAY56;
    void Algorithm();
    void AllSituation(vector<int> s,int val);
}
#endif

