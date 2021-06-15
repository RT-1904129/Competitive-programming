#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
}

void Maximum_Non_Overlapping_Substrings(vector<string>&checking,string &str){
    vector<pair<int,int>>arr;
    int t=checking.size(),a;
    for(int i=0;i<t;++i){
        int j=0;
        while(str.find(checking[i],j)!= -1){
            a=str.find(checking[i],j);
            arr.push_back({a,a+checking[i].size()-1});
            j=(a+1);
        }
    }
    sort(arr.begin(),arr.end(),compare);
    int count=0,end=-1;
    for(int i=0;i<arr.size();++i){
        if(arr[i].first>end){
            count++;
            end=arr[i].second;
        } 
    }
    cout<<count<<"\n";
}

int main(){
    string str,str2;
    vector<string>checking;
    int t,h,count,a;
    cin>>t;
    for(int i=0;i<t;++i){
        cin>>str;
        checking.push_back(str);
    }
    cin>>h;
    for(int i=0;i<h;++i){
        cin>>str;
        Maximum_Non_Overlapping_Substrings(checking,str);
    }
}