#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std;

#define MM 100000
int nextiii[MM];
char str[MM];

void GetNext(char *t);

int main(){
    int index,len;
    vector<string> result;
    while(cin>>str){
       char *s=str;
       len=0;
       int i;
       for(i=0;*s!='\0';s++,i++){
           GetNext(s);
           for(int j=1;j<=strlen(s);j++)
               if(nextiii[j]>len){
                    len=nextiii[j];
                    index=i+j; //index是第一个最长重复串在str中的位置 
               }
       }
       stringstream sss;
       if(len>0){
           int i = 0;
           int j = index-len;
           while (str[i] != '\0') {
               int temp = i;
               while (j < index && str[temp] == str[j]){
                   temp++;
                   j++;
               }
               if (j == index)
                   break;
               i++;
           }
           sss << i;
          for(int i=index-len;i<index;i++)
             sss<<str[i];
          sss<<endl;
       }
       else {
           sss<<"-1"<<endl;
       }
       result.push_back(sss.str());
    }
    for (int i = 0; i< result.size(); i++){
        cout << result[i] << endl;
    }
return 0;
}


void GetNext(char *t){
     int len=strlen(t);
     nextiii[0]=-1;
     int i=0;
     int j=nextiii[i];
     while(i<len){
         if(j==-1 || t[i]==t[j]){
             i++;
             j++;
             nextiii[i]=j;
         }
         else
             j=nextiii[j];
     }
}
