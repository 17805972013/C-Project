#ifndef _RESOURCES_
#define _RESOURCES_
#include "car.h"
void Vehicle::GetCarData(const char *data)
{
    std::stringstream ss;
    int fd;
    fd = open(data,O_RDONLY);
    int result;
    char buf[BUFSIZ]={};
    read(fd,buf,BUFSIZ);
    for(int i = 0;i != strlen(buf);++i){
        if(buf[i] == '('){
            int j = 1;
            double _temp;
            while(buf[i+j] != ')'){
               if(buf[i+j] != ','){
                     ss<<buf[i+j];
                    if(buf[i+j+1] == ',' || buf[i+j+1] == ')'){
                    ss>>_temp;
                    ss.clear();
                    this->pos.push_back(_temp);
                    }
               }
               j++;
           }
            if(pos.size() != 2)
                perror("初始位置信息错误，请重新设置！\n");
            else{
                 this->pos_x = this->pos[0];
                 this->pos_y = this->pos[1];
            }
        }
       if(buf[i] == '['){
           int j = 1;
           double _temp;
           while(buf[i+j] != ']'){
               if(buf[i+j] != ','){
               ss<<buf[i+j];
                  if(buf[i+j+1] == ',' || buf[i+j+1] == ']'){
                    ss>>_temp;
                    ss.clear();
                    Access_x.push_back(_temp);
                    }
               }
               j++;
           }
       } 
       if(buf[i] == '<'){
           int j = 1;
           double _temp;
           while(buf[i+j] != '>'){
               if(buf[i+j] != ','){
               ss<<buf[i+j];
                 if(buf[i+j+1] == ',' || buf[i+j+1] == '>'){
                    ss>>_temp;
                    ss.clear();
                    Access_y.push_back(_temp);
                    }
               }
                j++;
           }
       }
        if(buf[i] == '{'){
           int j = 1;
           double _temp;
           while(buf[i+j] != '}'){
               if(buf[i+j] != ','){
               ss<<buf[i+j];
                 if(buf[i+j+1] == ',' || buf[i+j+1] == '}'){
                    ss>>_temp;
                    ss.clear();
                    this->Interval.push_back(_temp);
                    }
               }
                j++;
           }
       }
    }
    AccessNum = Access_x.size();
    close(fd);
}
void Vehicle::handleAccident()
{
    int n;
    n = rand()%Interval.size();
    this->AccidentTime = SimTime+Interval[n];
    n = rand()%Access_x.size();
    this->a_x = Access_x[n];
    this->a_y = Access_y[n];
    this->AccidentFlags = false;
}
void Vehicle::Move()
{
    this->v_x += a_x*TimeAccuracy;
    this->v_y += a_y*TimeAccuracy;
    this->velocity = sqrt(v_x*v_x+v_y*v_y);
    this->pos_x += v_x*TimeAccuracy + 0.5*a_x*TimeAccuracy*TimeAccuracy;
    this->pos_y += v_y*TimeAccuracy + 0.5*a_y*TimeAccuracy*TimeAccuracy;
    #ifdef CollectData
    FILE* fp = fopen("postion","a+");
    fprintf(fp,"(%f,%f)\n",this->pos_x,this->pos_y);
    fclose(fp);
    #endif
}
void Vehicle::Control_Inner(double& count)
{
    if(this->AccidentFlags == false){
        count += TimeAccuracy;
        std::cout<<count<<std::endl;
    }
    if((int)count == DurationTime){
        count = 0;//计时器清零
        this->a_x = 0;
        this->a_y = 0;
        this->AccidentFlags = true;
    }
    if(this->velocity <= V_Max && this->velocity >= V_min)
        this->Move();
    else
    {
        this->a_x = 0;
        this->a_y = 0;
    }
    if((int)SimTime == this->AccidentTime){
        this->handleAccident();
    }

}
#endif