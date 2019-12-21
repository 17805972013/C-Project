/*
Author: QingweiZeng
Date:2016.6.27
*/
#ifndef _CAR_
#define _CAR_
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#define CollectData
/*时间精度*/
const double TimeAccuracy = 0.01;
/*最大车速与最小车速*/
const double V_Max = 20;
const double V_min = 0;
/*仿真初始时间*/
double SimTime = 0; 
/*随机事件持续时间*/
int DurationTime = 2;
class Vehicle
{
    public:
    /*随机事件发生的时刻*/
    int AccidentTime;
    /*加速度可选个数*/
    int AccessNum;
    /*可选的加速度*/
    std::vector<double> Access_x;
    std::vector<double> Access_y;
    /*当前位置*/
    std::vector<double> pos;
    double pos_x;
    double pos_y;
    /*当前加速度*/
    double a_x;
    double a_y;
    /*当前速度*/
    double v_x;
    double v_y;
    double velocity;
    /*随机事件发生的间隔*/
    std::vector<double> Interval;
    /*获取车辆初始信息*/
    void GetCarData(const char * data);
    /*处理事件*/
    void handleAccident();
    bool AccidentFlags;
    /*车辆移动*/
    void Move();
    /*车辆内部控制*/
    void Control_Inner(double& count);
};
#endif