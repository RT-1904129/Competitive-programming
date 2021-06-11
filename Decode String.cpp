#include<iostream>
#include<string>
#include<utility>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
typedef  long int rt;

string Decode_String(string & str1){
    rt i=0, a=str1.length();
    deque<string>arr;
    while(i<a){
        if(str1[i]=='<'){
            i++;
            string str2;
            while((i<a)&&((str1[i]!='<')&&(str1[i]!='>'))){
                str2+=str1[i];
                i++;
            }
            if(str2.length()!=0) arr.push_front(str2);
        }
        else if(str1[i]=='>'){
            i++;
            string str2;
            while((i<a)&&((str1[i]!='<')&&(str1[i]!='>'))){
                str2+=str1[i];
                i++;
            }
            if(str2.length()!=0) arr.push_back(str2);
        }
        else {
            string str2 ;
            str2+=str1[i];
            arr.push_back(str2); 
            i++;
        }
    }
    string str;
    if(arr.size()==0) return "-1";
    for(rt i=0;i<arr.size();++i){
        str+=arr[i];
    }
    return str;
}
    

int main(){
    rt t;
    string str;
    ios::sync_with_stdio(false);
    cin>>t;
    for(rt i=0;i<t;++i){
        cin>>str;
        cout<<Decode_String(str)<<"\n";
    }
}