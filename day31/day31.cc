#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
string DelMonth(string line);//对月份数据进行删减
void ReadData();//读取数据
int main(int argc,char* argv[])
{
    ReadData();
    return 0;
}
string DelMonth(string line)
{
    int count = 0;
    char temp[50] = {' '};
    for(int i = 0;i < line.length();++i){
        if(line[i] == '/')
            ++count;
        if(count == 2)
            break;
        temp[i] = line[i];
    }
    line = temp;
    return line;

}
void ReadData()
{
    ifstream is;
    ofstream os;
    os.open("data.txt",os.app);
    string line;
    is.open("FPD2018_Fail.csv");
    getline(is,line);
    int sel = 0;
    while(getline(is,line,','))
    { 
        if(sel == 0)
        {
            line = DelMonth(line);
            os<<line<<",";
        }
        else if(sel == 2){
            os<<line<<endl;
            sel = 0;
        }
       
        else{
            os<<line<<",";
            ++sel;
        }

    }
    is.close();
    os.close();
     
    vector<string> words;
    vector<int> sum;
    is.open("data.txt");
    os.open("DataFail.csv",os.app);
    getline(is,line);
    words.push_back(line);
    int count = 1;
    sum.push_back(count);
    while(getline(is,line)){
        count = 1;
        for(int i = 0;i < words.size();++i)
            if(line == words[i]){
                ++count;
                sum[i] += 1;
        }
        if(count == 1){
            words.push_back(line);
            sum.push_back(1);
        }
    }
    is.close();
    os<<"frequency,fdate,Model,WXID\n";
     for(int i = 0;i < words.size();++i){
       
         os<<sum[i]<<","<<words[i];
     }
     os.close();
    FILE* fp = popen("rm -rf data.txt","r");
    fclose(fp);
}