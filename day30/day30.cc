#include <iostream>
#include <vector>
using namespace std;
double max_achive(vector<int>,vector<int>,int);
int main(int argc,char* argv[])
{
    /* 输入case */
    int _case;
    cin>>_case;
    int num,time;
    int *score = new int[_case];
    int k = 0;
    while(_case--){
        cin>>num>>time;
        vector<int> achive,_time;
        for(int i = 0;i < num;++i){
            int _achive,__time;
            cin>>_achive>>__time;
            achive.push_back(_achive);
            _time.push_back(__time);
        }
        score[k++] = max_achive(achive,_time,time);
    }
    for(int i = 0;i < k;++i)
    printf("%d\n",score[i]);

}
double max_achive(vector<int> achive,vector<int>_time,int time)
{
    int result = 0;
    for(int j = 0;j < achive.size();++j){
        int time_sum = 0;
        int achive_sum = 0;
        for(int i = 0;i < achive.size();++i){
            if(i != j){
            time_sum += _time[i];
            if(time_sum <= time){
                  achive_sum += achive[i];
            }
            }
       
        }
        if(achive_sum > result)
            result = achive_sum;
    }
    return result;


}