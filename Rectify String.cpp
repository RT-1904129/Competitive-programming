#include<iostream>
#include<string>
#include<utility>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
typedef  long int rt;

string Rectify_String(string & str1){
    rt a=str1.length();
    deque<char>arr;
    for(rt i=0;i<a;++i){
        if(str1[i]=='<'){
            if(!arr.empty()) arr.pop_back();
        }
        else if(str1[i]=='>') break;
        else  arr.push_back(str1[i]);
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
        cout<<Rectify_String(str)<<"\n";
    }
}