#include <iostream>
#include <deque>
#include <string>
using namespace std;

typedef long long int rt;
string Update_to_Uppercase(string a){
    deque<char>df;
    rt gh,count=0;
    for(rt i=0;i<a.length();++i){
       if(a[i]!='@') df.push_back(a[i]);
       else{
           rt frequency=0;
           while(a[i]=='@'){
               frequency++;
               i++;
           }
           i--;
           string temp="";
           while((!df.empty())&&(frequency--)){
                char charcter=df.back();
                df.pop_back();
                temp+=toupper(charcter);
           }
           for (rt j = temp.length() - 1; j >= 0; j--)
                df.push_back(temp[j]);
       }
   }
    a="";
    for(rt i=0;i<df.size();++i) a+=df[i];
    return a;
}

int main(){
    int a;
    cin>>a;
    string str1;
    cin>>str1;
    str1=Update_to_Uppercase(str1);
    cout<<str1;
}