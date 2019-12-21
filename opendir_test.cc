#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
int main(int argc,char* argv[])
{
  std::string name = "/home/zqw/";
  DIR* fp;

  fp = opendir(name.c_str());
  struct dirent* fq;

  while((fq = readdir(fp)) != NULL){
  std::cout<<fq->d_name<<std::endl;
  }
  closedir(fp);
  return 0;
}