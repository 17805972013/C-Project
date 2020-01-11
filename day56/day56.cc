#include "day56.h"
#include "math.h"
int main(int argc,char*argv[])
{
    #ifdef T1
    using namespace DAY56;
    using namespace DAY56A;
    srand(time(0));
    //printf("%f",A);
    Algorithm();
    #endif
   

}
void DAY56A::Algorithm()
{
    vector<int> v;
    for(int i = 0;i < M;++i)
        v.push_back(rand()%4+1);
   vector<int> s;
   vector<int> Max;
   vector<int> Min;
   double Cmax = 0;
   double Cmin = 650868000;
   AllSituation(s,0);
   printf("情况：%d\n",cnt);
   int f[WaveNum];//f[i]表示第i个波束的路段数
      double lastC;
   for(int k = 0;k < result.size();++k){
        vector<double> r;
        double b_i_b;
        double b_i_e;
        double the_ta_i;
        double G_i;
        double P_i_noise;
        int u[M] = {0};//波数覆盖的车辆数
       for(int m = 0;m < WaveNum;++m){
           if(m == 0){
                r.push_back(0);
            f[m] = result[k][m]+1;
                for(int i = 0;i < f[m];++i)
                    u[m] += v[i];
           }
           else
           {   
               r.push_back(l*(result[k][m]+1));
               f[m] = result[k][m]-result[k][m-1]+1;
                for(int i = result[k][m-1]+1;i < result[k][m]+1;++i)
                    u[m] += v[i];
           }
       }
         r.push_back(S);  
        double C = 0;//吞吐量
        double SNR;
        bool _flags = true;
        bool flags = true;
        for(int i = 0;i < WaveNum-1;++i){
            b_i_b = 1.2*r[i] - 0.2*r[i+1];
            b_i_e = 1.2*r[i+1] - 0.2*r[i]; 
            the_ta_i = atan((S/2-b_i_b)/d)-atan((S/2-b_i_e)/d);
            G_i = 32400/(the_ta_i*theta_ele);
            P_i_noise = N_floor+NF+10*log(B/u[i]);
            if(i == 0)
            for(int j = 0;j < f[i];++j){
                double d_i_j = sqrt((S/2-r[i]-j*l+l/2)*(S/2-r[i]-j*l+l/2)+(d0+Wl)*(d0+Wl)+(H0-Hs)*(H0-Hs));
                double P_r_i_j = (Ptx+G_i-Catt-Att-Ratt)/(d_i_j*d_i_j);
                SNR = P_r_i_j/P_i_noise;
                if(_flags)
                {
                    lastC = B*log(1+SNR)/(u[i]*log(2));
                    _flags = false;
                }
                if(lastC/(B*log(1+SNR)/(u[i]*log(2))) > 3 || (B*log(1+SNR)/(u[i]*log(2)))/lastC > 3){
                    flags = false;
                    break;
                }
                C += B*v[j]*log(1+SNR)/(u[i]*log(2));
            }
            else
            {
                for(int j = result[k][i-1]+1;j <  result[k][i]+1;++j){
                    double d_i_j = sqrt((S/2-r[i]-j*l+l/2)*(S/2-r[i]-j*l+l/2)+(d0+Wl)*(d0+Wl)+(H0-Hs)*(H0-Hs));
                    double P_r_i_j = (Ptx+G_i-Catt-Att-Ratt)/(d_i_j*d_i_j);
                    SNR = P_r_i_j/P_i_noise;
                if(lastC/(B*log(1+SNR)/(u[i]*log(2))) > 3 || (B*log(1+SNR)/(u[i]*log(2)))/lastC > 3){
                    flags = false;
                    break;
                }
                    C += B*v[j]*log(1+SNR)/(u[i]*log(2));
                }
            }
            
        }
        if(!flags)
        {
            
            continue;
        }
        printf("吞吐量为：%f\n",C);
        if(Cmin > C)
        {
            Cmin = C;
            Min = result[k];
        }
        if(Cmax < C)
        {
            Cmax = C;
            Max = result[k];
        }
   }
   cout<<"最小吞吐量为:"<<Cmin<<endl;
   cout<<"波策略为：\n";
   for(int i = 0;i < Min.size();++i)
   cout<<Min[i]<<" ";
   cout<<endl;
   cout<<"最大吞吐量为："<<Cmax<<endl;
   cout<<"波策略为：\n";
   for(int i = 0;i < Max.size();++i)
   cout<<Max[i]<<" ";
   cout<<endl;
   cout<<"车辆分布情况为：\n";
   for(int i = 0;i < v.size();++i)
   cout<<v[i]<<" ";
   cout<<endl;
   cout<<lastC<<endl;
    
    
}
void DAY56A::AllSituation(vector<int> s,int val)
{
    vector<int> _s;//临时变量
    if(s.size() == WaveNum-2)
    {
        if(M-val > 4)
        return;
    }
    if(s.size() == WaveNum-1)
    {
        result.push_back(s);
        for(int i = 0;i < s.size();++i)
            cout<<s[i]<<" ";
        cout<<endl;
        s.clear();
        ++cnt;
        return;
    }
    for(int i = val;i < val+4;++i){
        if(i < M-1){
            _s = s;
            _s.push_back(i);
            AllSituation(_s,i+1);
        }
    }
}