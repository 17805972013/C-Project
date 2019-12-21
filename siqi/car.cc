#include "resources.cc"
int main(int argc,char* argv[])
{
    double count = 0;//计时器
    if(argc != 2){
        std::cout<<"您的输入有误，请重新输入！\n";
        exit(1);
    }
    srand(unsigned(time(0)));
    Vehicle vehicle;
    vehicle.GetCarData(argv[1]);
    vehicle.handleAccident();
    while(1){
        std::cout<<"仿真时间："<<SimTime<<std::endl;
        std::cout<<"随机事件发生时刻："<<vehicle.AccidentTime<<std::endl;
        vehicle.Control_Inner(count);
        SimTime += TimeAccuracy;
    }
    return 0;
}