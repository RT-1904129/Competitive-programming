#include <iostream>
#include <algorithm>
#include<utility>
#include <string>
#include <unordered_map>
typedef long int rt;
using namespace std; 

void Unique_Character(string &str){
    pair<rt,rt>check;
    unordered_map<char,pair<rt,rt>>arr;
    for(rt i=0;i<str.length();++i){
        if(arr.find(str[i])!=arr.end()){
            check=arr[str[i]];
            check.second++;
            arr[str[i]]=check;
        }
        else{
            arr[str[i]]={i,1};
        }
    }
    rt count=0,min_index=str.length()+1;
    for(auto itr=arr.begin();itr!=arr.end();++itr){
        if(itr->second.second==1){
               if(itr->second.first<=min_index) min_index=itr->second.first;
               count++;
        }
    }
    if(count==0) cout<<"-1";
    else cout<<min_index;
}

int main() {
    string str;
    ios::sync_with_stdio(false);
    cin>>str;
    Unique_Character(str);
}